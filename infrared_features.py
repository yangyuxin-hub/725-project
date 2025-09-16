import os
import numpy as np
from PIL import Image,ImageOps

# ----------- 读取 .asc 红外图像并重建为二维矩阵 -----------
def load_asc_file(file_path):
    data = []
    width, height = None, None

    with open(file_path, 'r', encoding='utf-8', errors='ignore') as f:
        in_data = False
        for line in f:
            line = line.strip()
            if not line:
                continue
            if line.startswith('ImageWidth='):
                width = int(line.split('=')[1])
            elif line.startswith('ImageHeight='):
                height = int(line.split('=')[1])
            elif line.startswith('[Data]'):
                in_data = True
                continue
            elif in_data:
                parts = [x.replace(',', '.') for x in line.split('\t') if x]
                try:
                    floats = list(map(float, parts))
                    data.extend(floats)
                except ValueError:
                    continue

    if not data or width is None or height is None:
        raise ValueError(f"数据或图像尺寸无效: {file_path}")

    array = np.array(data)
    if array.size != width * height:
        raise ValueError(f"数据大小不匹配图像尺寸: {file_path}, 读取了 {array.size} 项，应为 {width*height}")

    return array.reshape((height, width))


# ----------- 中心 ROI 特征提取 -----------
def extract_infrared_features(image_path_or_matrix):
    if isinstance(image_path_or_matrix, str):
        # 如果传入的是图片路径（png/jpg等）
        img = Image.open(image_path_or_matrix).convert("L")  # 转灰度
        img = ImageOps.invert(img) # 灰度反转
        temp_matrix = np.array(img, dtype=np.float32)
    else:
        # 如果传入的是矩阵（.asc 文件解析结果）
        temp_matrix = image_path_or_matrix.astype(np.float32)

    h, w = temp_matrix.shape
    center_x, center_y = h // 2, w // 2

    x_min = max(0, center_x - 100)
    x_max = min(h, center_x + 100)
    y_min = max(0, center_y - 100)
    y_max = min(w, center_y + 100)
    roi = temp_matrix[x_min:x_max, y_min:y_max]

    roi_max = np.max(roi)
    roi_mean = np.mean(roi)
    roi_rms = np.sqrt(np.mean(roi ** 2))

    return [roi_max, roi_mean, roi_rms]

def gray_to_temperature(gray_value, t_min, t_max):
    return t_min + (gray_value / 255.0) * (t_max - t_min)

# 读取文件夹中所有 .asc 文件，提取特征并打标签
def process_infrared_folder(folder):
    files = sorted([f for f in os.listdir(folder) if f.endswith('.asc')])
    features = []
    for file in files:
        file_path = os.path.join(folder, file)
        temp_matrix = load_asc_file(file_path)
        feats = extract_infrared_features(temp_matrix)
        features.append(feats)
    return np.array(features)


# 示例使用
if __name__ == "__main__":
    # 例1：处理 .asc 文件夹
    # folder_path = r"E:\SJTU\multi-sensor\725\dataset\A12-A17\A12-A17\红外导出\A12"
    # features = process_infrared_folder(folder_path)
    # print("Features shape:", features.shape)
    # print("Example feature vector:", features[0])
    filename = r"D:\20250826_win64\data\test"
    for img_file in os.listdir(filename):
        img_path = os.path.join(filename, img_file)
        features = extract_infrared_features(img_path)
        print(features)

    # 例2：处理普通图片
    # image_path = r"D:\20250826_win64\data\20250903_184114\InfraredImage_20250903_184145_746.png"
    # features = extract_infrared_features(image_path)
    # print(features)




