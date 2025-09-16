import torch
from PIL import Image,ImageOps  # 用Pillow代替cv2读取图像
import os
import numpy as np
from torchvision import transforms, models
from torch import nn
from torch.utils.data import Dataset, DataLoader


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
            nn.Dropout(0.5),
            nn.Linear(128, 12),
            nn.ReLU(inplace=True),
            # nn.Dropout(0.4),
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
        x = self.fc[2](x)  # Dropout
        x = self.fc[3](x)  # Linear(128, 12)
        # x = self.fc[4](x)  # ReLU
        # x = self.fc[5](x)

        return x  # 输出 12 维特征



device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
# pretrained_model = models.mobilenet_v3_small(weights=models.MobileNet_V3_Small_Weights.DEFAULT)
pretrained_model = models.mobilenet_v3_small(weights=None)
model = CustomMobileNetV3Small(pretrained_model)
model.load_state_dict(torch.load('best_mobile_model_A.pth', map_location=device))
model.to(device)
model.eval()  # 设置为评估模式


# 图像预处理（与训练时相同）
transform = transforms.Compose([
    transforms.Resize((224, 224)),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
])




device = torch.device("cuda" if torch.cuda.is_available() else "cpu")


# 提取图像特征函数
def extract_image_features(image_path):
    # 使用Pillow加载图像
    image = Image.open(image_path).convert("RGB")
    image = image.transpose(Image.FLIP_TOP_BOTTOM)  # 上下翻转
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

# image_path = "./data/20250830_182203/WeldPoolImage_20250830_182204_102.png"
# features = extract_image_features(image_path)
# print(features)

filename = r"D:\20250826_win64\data\testwelding"
for img_file in os.listdir(filename):
    img_path = os.path.join(filename, img_file)
    features = extract_image_features(img_path)
    print(features)

