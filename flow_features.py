import numpy as np
import os

# 读取所有 .npy 文件
def load_flow_from_folder(folder_path):
    files = [f for f in os.listdir(folder_path) if f.endswith('.npy')]
    flows = [np.load(os.path.join(folder_path, file)) for file in files]
    print(f"Loaded {len(flows)} flow values from {folder_path}")
    return flows

# 直接提取气流特征（每个文件一个值，直接返回）
def extract_flow_features(flow_value):
    return [flow_value.item()]  # 只返回一个值作为特征向量

# 处理整个文件夹的气流特征
def process_flow_folder(folder):
    flow_values = load_flow_from_folder(folder)
    features = [extract_flow_features(val) for val in flow_values]
    return np.array(features)
