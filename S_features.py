import numpy as np
import os
import matplotlib.pyplot as plt
from scipy.stats import kurtosis, skew
import pywt
from scipy.signal import butter, filtfilt
import librosa
import librosa.display


# 读取文件夹中的所有 .npy 文件
def load_signals_from_folder(folder_path):
    files = [f for f in os.listdir(folder_path) if f.endswith('.npy')]
    signals = [np.load(os.path.join(folder_path, file)) for file in files]
    signals = wavelet_denoising(signals)
    print(f"Loaded {len(signals)} signals from {folder_path}")  # 检查信号数量
    return signals

# 去除直流分量
def remove_dc_offset(signal):
    signal = np.array(signal, dtype=float)
    return signal - np.mean(signal)


# 小波滤波
def wavelet_denoising(signal, wavelet='coif8', level=4):
    signal = remove_dc_offset(signal)
    coeffs = pywt.wavedec(signal, wavelet, level=level)
    sigma = np.median(np.abs(coeffs[-level])) / 0.6745
    uthresh = sigma * np.sqrt(2 * np.log(len(signal)))
    coeffs[1:] = (pywt.threshold(i, value=uthresh, mode='soft') for i in coeffs[1:])
    return pywt.waverec(coeffs, wavelet)


# 带通滤波器
def bandpass_filter(data, lowcut, highcut, fs, order=4):
    nyquist = 0.5 * fs
    low = lowcut / nyquist
    high = highcut / nyquist

    b, a = butter(order, [low, high], btype='band')
    return filtfilt(b, a, data)


# 提取电流时域特征
def extract_sound_time_features(signal):
    signal = np.array(signal, dtype=float)
    mean_value = np.mean(signal)  # 均值
    rms_value = np.sqrt(np.mean(signal ** 2))  # 均方根
    # peak_to_peak_value = np.max(signal) - np.min(signal)  # 峰峰值 （记得注释掉）
    peak_factor = np.max(signal) / rms_value  # 峰值因子
    kurt = kurtosis(signal)  # 峭度
    skewness_value = skew(signal)  # 偏度
    variance = np.var(signal)  # 方差

    return [mean_value, rms_value, skewness_value, peak_factor, kurt, variance]


# 提取频域特征
def extract_sound_frequency_features(signal, fs):
    signal = np.array(signal, dtype=float)
    freqs = [(1, 3000), (3000, 6000)]
    features = []

    for lowcut, highcut in freqs:
        filtered_signal = bandpass_filter(signal, lowcut, highcut, fs)
        avg_amplitude = np.mean(np.abs(filtered_signal))  # 平均幅值
        amplitude_sum = np.sum(np.abs(filtered_signal))  # 幅值和
        std_dev = np.std(filtered_signal)  # 标准差
        rms = np.sqrt(np.mean(filtered_signal ** 2))  # 均方根
        kurt = kurtosis(filtered_signal)  # 峭度
        skewness = skew(filtered_signal)  # 偏度

        features.extend([avg_amplitude, amplitude_sum, std_dev, rms, kurt, skewness])

    return features


def extract_mfcc_features(signal, sr=40160, n_mfcc=12):
    """
    计算MFCC特征的均值和标准差。

    :param signal: 输入音频信号
    :param sr: 采样率
    :param n_mfcc: 需要提取的MFCC系数数量
    :return: MFCC特征向量
    """
    signal = np.array(signal, dtype=float)
    mfccs = librosa.feature.mfcc(y=signal, sr=sr, n_mfcc=n_mfcc)

    # 计算MFCC的统计特征
    mfcc_mean = np.mean(mfccs, axis=1)  # 每个MFCC系数的均值
    mfcc_std = np.std(mfccs, axis=1)  # 每个MFCC系数的标准差

    return np.hstack([mfcc_mean, mfcc_std])  # 拼接MFCC特征


# 读取并提取所有特征
def extract_all_sound_features(signal, fs=40160):
    signal = np.array(signal, dtype=float)
    # 提取时域特征
    time_features = np.array(extract_sound_time_features(signal))
    # 提取频域特征
    frequency_features = np.array(extract_sound_frequency_features(signal, fs))
    # 提取MFCC特征
    mfcc_features = extract_mfcc_features(signal, fs)
    all_features = np.concatenate([time_features, frequency_features, mfcc_features])
    return all_features


# 处理每个文件夹中的所有电流信号
def process_sound_folder(folder):
    sound_signals = load_signals_from_folder(folder)  # 加载电流信号
    features = [extract_all_sound_features(signal) for signal in sound_signals]
    return np.array(features)





