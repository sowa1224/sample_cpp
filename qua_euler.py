import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import quaternion
import math
# クォータニオンの値
#joystick yaw+ 0.0160202 , -0.691073 , 0.720186 , -0.0591029
#デフォルト姿勢0.0188505 , -0.395338 , 0.91737 , -0.0422521
#joystickでyaw - 0.00702533 , -0.138656 , 0.989259 , -0.0457313
#joystickでyaw --  0.00427669 , -0.0792271 , 0.995783 , -0.0460649


q=[ 0.0188505 , -0.395338 , 0.91737 , -0.0422521
]
qw=q[3]
qx=q[0]
qy=q[1] 
qz=q[2]

quat = quaternion.quaternion(qw, qx, qy, qz)

# クォータニオンからオイラー角を取得
euler = np.degrees(quaternion.as_euler_angles(quat))
roll = euler[0]
pitch = euler[1]
yaw = euler[2]
print(f'roll {roll}  pitch {pitch}    yaw {yaw}')

# クォータニオンから得たオイラー角
euler_angles = np.degrees(quaternion.as_euler_angles(quat))
roll, pitch, yaw = euler_angles[0], euler_angles[1], euler_angles[2]




from_euler_0 = quaternion.from_euler_angles(np.radians(roll), np.radians(pitch-10), np.radians(yaw))
from_euler_1 = quaternion.from_euler_angles(np.radians(0), np.radians(0), np.radians(0))
print(from_euler_0)
#print(np.degrees(quaternion.as_euler_angles(from_euler_0)))
print(from_euler_1)
#print(np.degrees(quaternion.as_euler_angles(from_euler_1)))



import quaternion
import numpy as np



# 元のクォータニオン
original_quaternion = quaternion.quaternion(-0.0803673, -0.159512, 0.983884, 0.00827396)
"""
# 回転する軸と角度を定義
angles = np.arange(10, 90, 5)  # 0度から90度まで10度刻みで回転すると仮定
axis = np.array([0, 0, 1])  # X軸周りに回転
print(angles)
for angle in angles:
    # 角度をラジアンに変換
    angle_rad = np.radians(angle)

    # 軸周りのクォータニオンを生成
    rotation_quaternion = quaternion.from_rotation_vector(angle_rad * axis)

    # 回転を適用
    rotated_quaternion = rotation_quaternion * original_quaternion

    # 回転後のクォータニオンを取得
    rotated_result = quaternion.as_float_array(rotated_quaternion)
    # 個々の要素を "qw, qx, qy, qz" 形式で表示
    print(f'posq<<0.48 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673 ,{rotated_result[0]},{rotated_result[1]},{rotated_result[2]},{rotated_result[3]};')
    print('ks.setq(time,posq);')
    print('sleep(10);')
    """
import quaternion
import numpy as np

# 元のクォータニオン
original_quaternion = quaternion.quaternion( 0.0188505 , -0.395338 , 0.91737 , -0.0422521)

# 回転する軸と角度を定義
angle = np.radians(45)  # 45度回転すると仮定
axis = np.array([1, 0, 0])  # X軸周りに回転

# 軸周りのクォータニオンを生成
rotation_quaternion = quaternion.from_rotation_vector(angle * axis)

# 回転を適用
rotated_quaternion = rotation_quaternion * original_quaternion

# 回転後のクォータニオンを取得
rotated_result = quaternion.as_float_array(rotated_quaternion)

#print("Rotated quaternion:", rotated_result)
