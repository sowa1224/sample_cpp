import quaternion
import numpy as np
import math
import numpy as np

qx =0.00755731  # クォータニオンの値を設定してください。
qy = 0.00938686
qz = 0.999927 
qw = 0.000467385
def calc_quat_to_rpy(qx,qy,qz,qw):
    q0q0 = qw * qw
    q1q1 = qx * qx
    q2q2 = qy * qy
    q3q3 = qz * qz
    q0q1 = qw * qx
    q0q2 = qw * qy
    q0q3 = qw * qz
    q1q2 = qx * qy
    q1q3 = qx * qz
    q2q3 = qy * qz

    roll = math.atan2(2.0 * (q2q3 + q0q1), q0q0 - q1q1 - q2q2 + q3q3)
    pitch = -math.asin(2.0 * (q1q3 - q0q2))
    yaw = math.atan2(2.0 * (q1q2 + q0q3), q0q0 + q1q1 - q2q2 - q3q3)

    return roll, pitch, yaw

def calc_rpy_to_quat(roll,pitch,yaw):
    cy = np.cos(yaw * 0.5)
    sy = np.sin(yaw * 0.5)
    cp = np.cos(pitch * 0.5)
    sp = np.sin(pitch * 0.5)
    cr = np.cos(roll * 0.5)
    sr = np.sin(roll * 0.5)

    qw = cr * cp * cy + sr * sp * sy
    qx = sr * cp * cy - cr * sp * sy
    qy = cr * sp * cy + sr * cp * sy
    qz = cr * cp * sy - sr * sp * cy
    return qx, qy, qz, qw



print(math.degrees(calc_quat_to_rpy(qx,qy,qz,qw)[0]),math.degrees(calc_quat_to_rpy(qx,qy,qz,qw)[1]),math.degrees(calc_quat_to_rpy(qx,qy,qz,qw)[2]))  
print(calc_rpy_to_quat(0,0,0))  


import numpy as np

# 元のクォータニオン q1
q1 = np.array([1, 0, 0, 0])  # 単位クォータニオン

# yaw軸周りの20度の回転を表すクォータニオン q2 を計算
offsetyaw = 20 * np.pi / 180.0
q2 = np.array([np.cos(offsetyaw / 2), 0, np.sin(offsetyaw / 2), 0])  # 回転軸に沿った半角回転

# クォータニオンの乗算を計算する関数
def quaternion_multiply(q1, q2):
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2
    
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2
    z = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2
    
    return np.array([w, x, y, z])

# q1 と q2 を掛けて q3 を得る
q3 = quaternion_multiply(q1, q2)

# 結果の表示
print("q1:", q1)
print("q2:", q2)
print("q3:", q3)


"""
# 10度ごとにpitchを増やし、クォータニオンを計算
for angle in range(10, 61, 10):
    # 現在のオイラー角
    current_pitch = angle
    
    # クォータニオンからオイラー角を計算
    roll, pitch, yaw = calc_quat_to_rpy(qx, qy, qz, qw)
    
    # pitch軸を変更
    pitch += math.radians(current_pitch)
    # オイラー角からクォータニオンを計算
    qx_new, qy_new, qz_new, qw_new = calc_rpy_to_quat(roll, pitch, yaw)

    
    print(f"posq<<0.483888 , 0.522864 , -0.00920468 , 0.314561 , {qx_new}, {qy_new}, {qz_new}, {qw_new}")
    print(";")
    print("ks.setq(time,posq);")
    print("sleep(1);")








qz = -0.0422521  
qw = 0.0188505
qx = -0.395338
qy = 0.91737
"""
