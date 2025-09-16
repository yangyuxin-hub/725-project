import numpy as np
import os
import matplotlib.pyplot as plt
from scipy.stats import kurtosis, skew
import pywt



# 读取文件夹中的所有 .npy 文件
def load_signals_from_folder(folder_path):
    files = [f for f in os.listdir(folder_path) if f.endswith('.npy')]
    signals = [np.load(os.path.join(folder_path, file)) for file in files]
    signals = wavelet_denoising(signals)
    print(f"Loaded {len(signals)} signals from {folder_path}")  # 检查信号数量
    return signals


# 小波滤波
def wavelet_denoising(signal, wavelet='coif8', level=4):
    coeffs = pywt.wavedec(signal, wavelet, level=level)
    sigma = np.median(np.abs(coeffs[-level])) / 0.6745
    uthresh = sigma * np.sqrt(2 * np.log(len(signal)))
    coeffs[1:] = (pywt.threshold(i, value=uthresh, mode='soft') for i in coeffs[1:])
    return pywt.waverec(coeffs, wavelet)

# 提取电流时域特征
def extract_current_time_features(signal):
    signal = np.array(signal, dtype=float)
    mean_value = np.mean(signal)  # 均值
    rms_value = np.sqrt(np.mean(signal ** 2))  # 均方根
    # peak_to_peak_value = np.max(signal) - np.min(signal)  # 峰峰值
    peak_factor = np.max(signal) / rms_value  # 峰值因子
    kurt = kurtosis(signal)  # 峭度
    skewness_value = skew(signal)  # 偏度
    variance = np.var(signal)  # 方差

    return [mean_value, rms_value, skewness_value, peak_factor, kurt, variance]


# 处理每个文件夹中的所有电流信号
def process_current_folder(folder):
    current_signals = load_signals_from_folder(folder)  # 加载电流信号
    features = [extract_current_time_features(signal) for signal in current_signals]
    return np.array(features)





