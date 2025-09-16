import os
import numpy as np
import torch
from tqdm import tqdm
from torchvision import transforms, models
from I_features import process_current_folder
from U_features import process_voltage_folder
from S_features import process_sound_folder
from image_featuresA import extract_image_features, CustomMobileNetV3Small
from flow_features import process_flow_folder
from wirespeed_features import process_wirespeed_folder
from infrared_features import process_infrared_folder

# 图像预处理
transform = transforms.Compose([
    transforms.ToPILImage(),
    transforms.Resize((224, 224)),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])
])

# 初始化图像模型
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
# pretrained_model = models.mobilenet_v3_small(weights=models.MobileNet_V3_Small_Weights.DEFAULT)
pretrained_model = models.mobilenet_v3_small(weights=None)
model = CustomMobileNetV3Small(pretrained_model).to(device)
model.load_state_dict(torch.load('best_mobile_model_A.pth', map_location=device))
model.eval()


# 特征对齐函数
def align_features(folder_base):
    """处理单条焊缝的四个模态数据"""
    # 各模态特征提取
    sound_feat, _ = process_sound_folder(os.path.join(folder_base, "out_sound"))
    print("✅ Sound feature shape:", sound_feat.shape)
    current_feat, _ = process_current_folder(os.path.join(folder_base, "out_current"))
    print("✅ Current feature shape:", current_feat.shape)
    voltage_feat, _ = process_voltage_folder(os.path.join(folder_base, "out_voltage"))
    print("✅ Voltage feature shape:", voltage_feat.shape)
    flow_feat, _ = process_flow_folder(os.path.join(folder_base, "out_flow"))
    print("✅ Flow feature shape:", flow_feat.shape)
    # wirespeed_feat, _ = process_wirespeed_folder(os.path.join(folder_base, "out_wirespeed"))
    # print("✅ Wirespeed feature shape:", wirespeed_feat.shape)
    infrared_feat, _ = process_infrared_folder(os.path.join(folder_base, "out_infrared"))
    print("✅ Infrared feature shape:", infrared_feat.shape)
    image_feat, _ = extract_image_features(os.path.join(folder_base, "out_images"), model, transform)
    print("✅ Image feature shape:", image_feat.shape)


    # 确保特征数量一致
    min_length = min(len(sound_feat), len(current_feat), len(voltage_feat),  len(flow_feat), len(infrared_feat), len(image_feat))


    # 特征拼接
    combined = np.hstack([
        current_feat[:min_length],
        voltage_feat[:min_length],
        sound_feat[:min_length],
        flow_feat[:min_length],
        # wirespeed_feat[:min_length],
        infrared_feat[:min_length],
        image_feat[:min_length],
    ])

    return combined


