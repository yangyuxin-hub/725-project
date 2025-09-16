import numpy as np
import os

# 读取所有 .npy 文件
# 读取所有 .npy 文件
def load_wirespeed_from_folder(folder_path):
    files = [f for f in os.listdir(folder_path) if f.endswith('.npy')]
    wirespeeds = [np.load(os.path.join(folder_path, file)) for file in files]
    print(f"Loaded {len(wirespeeds)} wirespeed values from {folder_path}")
    return wirespeeds

# 直接提取气流特征（每个文件一个值，直接返回）
def extract_wirespeed_features(wirespeed_value):
    return [wirespeed_value.item()]  # 只返回一个值作为特征向量

# 处理整个文件夹的气流特征
def process_wirespeed_folder(folder):
    wirespeed_values = load_wirespeed_from_folder(folder)
    features = [extract_wirespeed_features(val) for val in wirespeed_values]
    return np.array(features)