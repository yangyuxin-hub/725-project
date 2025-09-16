import numpy as np
import joblib
from sklearn.preprocessing import StandardScaler

def predict_from_array(features):
    """
    对一个特征数组进行归一化和模型预测。
    """
    # 1. 加载归一化参数
    scaler_data = np.load("scaler_params_C.npz")
    scaler = StandardScaler()
    scaler.mean_ = scaler_data["scaler_mean"]
    scaler.scale_ = scaler_data["scaler_scale"]

    # 2. 特征预处理（替换 NaN → 0）
    features = np.nan_to_num(features)

    # 变成 (1, n_features)
    features = features.reshape(1, -1)

    # 3. 归一化
    features_scaled = scaler.transform(features)

    # 4. 加载模型并预测
    model = joblib.load("saved_model_C.joblib")
    predictions = model.predict(features_scaled)

    return predictions


# 你的特征数组
features = [0.055, 1.891, -1.983, 5.293, 22.000, 3.573, -0.016, 0.336, 1.695, 8.441, 15.308, 0.112, -0.477, 0.481, 1.045, -0.371, 6.347, 0.004, 0.020, 9.830, 0.021, 0.024, -0.391, -0.121, 0.018, 9.026, 0.023, 0.023, -0.252, -0.001, -60.380, 73.944, 33.680, 18.997, 18.378, 14.624, 10.957, 7.027, 4.234, 7.907, 7.196, 5.504, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 66.000, 47.889, 48.021, 12.974, 11.073, 74.199, 15.809, 2.244, 14.762, 0.000, 0.000, 24.238, 0.000, 48.349, 38.635]

# features = np.load("feature_array.npy")  # 或直接传入内存中的数组

# 调用函数进行预测
preds = predict_from_array(
    features=features
)

# 0-4对应["正常", "错边", "焊偏", "气孔", "焊漏"]
# 输出结果
print("预测标签：", preds[0])

