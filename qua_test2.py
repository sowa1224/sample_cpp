import numpy as np
from scipy.spatial.transform import Rotation

# 現在の姿勢であるクォータニオン
current_quaternion = np.array([0.0188505, -0.395338, 0.91737, -0.0422521])  # 例として [0, 0, 0, 1] を使います

# Yaw, Roll, Pitchを指定
yaw = 30 * np.pi / 180.0
roll = 0 * np.pi / 180.0
pitch = 0 * np.pi / 180.0

# Yaw, Roll, Pitchを含む回転行列を作成
r = Rotation.from_euler('ZYX', [yaw, roll, pitch])

# 回転行列からクォータニオンを求める
new_quaternion = r.as_quat()
print(new_quaternion)
# 新しいクォータニオンを現在のクォータニオンに掛ける
# Quaternion multiplication: q = q1 * q2
def quaternion_multiply(q1, q2):
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2

    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2
    z = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2

    return np.array([w, x, y, z])

result_quaternion = quaternion_multiply(current_quaternion, new_quaternion)
print("Result Quaternion:", result_quaternion)
