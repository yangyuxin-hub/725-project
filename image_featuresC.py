import torch
import os
import numpy as np
from torch.ao.quantization.fx import convert
from torchvision import transforms, models
from torch import nn
from torch.utils.data import Dataset, DataLoader
from PIL import Image,ImageOps  # 用Pillow代替cv2读取图像


class CustomMobileNetV3Small(nn.Module):
    def __init__(self, pretrained_model):
        super(CustomMobileNetV3Small, self).__init__()

        # 保留预训练模型的前几层
        self.features = pretrained_model.features

        # 插入新的全连接层
        self.avgpool = nn.AdaptiveAvgPool2d((1, 1))
        self.fc = nn.Sequential(
            nn.Linear(576, 128),
            nn.ReLU(inplace=True),
            nn.Linear(128, 12),
            nn.ReLU(inplace=True),
            nn.Linear(12, 5)
        )

    def forward(self, x):
        # 提取特征
        x = self.features(x)
        x = self.avgpool(x)
        x = torch.flatten(x, 1)

        # 只执行到输出 12 维特征
        x = self.fc[0](x)  # Linear(576, 128)
        x = self.fc[1](x)  # ReLU
        x = self.fc[2](x)  # Linear(128, 12)
        x = self.fc[3](x)  # ReLU

        return x  # 输出 12 维特征


# 设备选择
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

# 加载预训练模型并进行微调
pretrained_model = models.mobilenet_v3_small(weights=None)
model = CustomMobileNetV3Small(pretrained_model)
model.load_state_dict(torch.load('best_mobile_model_for_C_1(0.9778).pth', map_location=device))
model.to(device)
model.eval()  # 设置为评估模式

# 图像预处理（与训练时相同）
transform = transforms.Compose([
    transforms.Resize((224, 224)),  # 调整大小
    transforms.ToTensor(),  # 转换为 tensor
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])  # 标准化
])


# 自定义 Dataset 类
class ImageDataset(Dataset):
    def __init__(self, data_dir, transform=None):
        self.data_dir = data_dir
        self.transform = transform
        self.image_paths = []

        # 加载目录中的所有图片路径
        for img_file in os.listdir(data_dir):
            img_path = os.path.join(data_dir, img_file)
            self.image_paths.append(img_path)

        print(f"Loaded {len(self.image_paths)} images from {data_dir}")  # Debug

    def __len__(self):
        return len(self.image_paths)

    def __getitem__(self, idx):
        # 读取图像并转换为 RGB 格式（使用Pillow）
        image_path = self.image_paths[idx]
        image = Image.open(image_path).convert("RGB")  # 用Pillow打开并转换为RGB
        image = self.transform(image)  # 应用预处理（resize和标准化）

        return image


# 提取图像特征
def extract_image_features(image_path):
    # 使用Pillow加载图像
    image = Image.open(image_path).convert("RGB")
    img_array = np.array(image)
    image = img_array[:, :, ::-1]
    image = Image.fromarray(image)
    image = transform(image)  # 应用预处理
    image = image.unsqueeze(0).to(device)  # 添加批次维度: [1, 3, 224, 224]

    # 提取特征
    with torch.no_grad():  # 禁用梯度计算
        features = model(image)

    # 返回特征（去掉梯度并转为 NumPy 数组）
    return features.detach().cpu().numpy().flatten()

filename = r"D:\20250826_win64\data\testwelding"
for img_file in os.listdir(filename):
    img_path = os.path.join(filename, img_file)
    features = extract_image_features(img_path)
    print(features)
# 测试提取特征
# image_path = "./data/20250830_182203/WeldPoolImage_20250830_182204_102.png"
# features = extract_image_features(image_path)
# print(features)
