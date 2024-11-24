import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import quaternion
import math
# クォータニオンの値


qw=-0.0803673
qx=-0.159512 
qy=0.983884 
qz=0.00827396
"""
qw =-0.0803673
qx =  -0.159512 
qy =  0.983884 
qz =  0.00827396
"""


quat = quaternion.quaternion(qw, qx, qy, qz)
rot = quaternion.as_rotation_matrix(quat)
print(rot)

# クォータニオンからオイラー角を取得
euler = quaternion.as_euler_angles(quat)
roll = euler[0]
pitch = euler[1]
yaw = euler[2]

print(f'roll: {np.degrees(roll)}, pitch: {np.degrees(pitch)}, yaw: {np.degrees(yaw)}')

# 回転行列からクォータニオンを作成
from_rot = quaternion.from_rotation_matrix(rot)
#print(from_rot)

# オイラー角からクォータニオンを作成
from_euler = quaternion.from_euler_angles(roll, pitch, yaw)
#print(from_euler)

# yaw角を20度3回減少させる
roll_degres = np.degrees(roll)
new_roll_degres_0 = roll_degres + 40  # 20度を3回減少
new_roll_degres_1 = roll_degres + 50
new_roll_degres_2 = roll_degres + 60

new_roll_radians_0 = np.radians(new_roll_degres_0)  # ラジアンに変換
new_roll_radians_1 = np.radians(new_roll_degres_1) 
new_roll_radians_2 = np.radians(new_roll_degres_2) 
# 新しいyaw角を考慮してクォータニオンを作成
new_quat_0 = quaternion.from_euler_angles(new_roll_radians_0,pitch, yaw)
new_quat_1 = quaternion.from_euler_angles(new_roll_radians_1, pitch,yaw)
new_quat_2 = quaternion.from_euler_angles(new_roll_radians_2, pitch,yaw)


print(new_quat_0)
new_euler_0 = quaternion.as_euler_angles(new_quat_0)
roll_0 = new_euler_0[0]
pitch_0 = new_euler_0[1]
yaw_0 = new_euler_0[2]
print(f'roll: {np.degrees(roll_0)}, pitch: {np.degrees(pitch_0)}, yaw: {np.degrees(yaw_0)}')

print(new_quat_1)
new_euler_1 = quaternion.as_euler_angles(new_quat_1 )
roll_1 = new_euler_1[0]
pitch_1 = new_euler_1[1]
yaw_1 = new_euler_1[2]
print(f'roll: {np.degrees(roll_1)}, pitch: {np.degrees(pitch_1)}, yaw: {np.degrees(yaw_1)}')


print(new_quat_2)
new_euler_2= quaternion.as_euler_angles(new_quat_2)
roll_2 = new_euler_2[0]
pitch_2 = new_euler_2[1]
yaw_2 = new_euler_2[2]
print(f'roll: {np.degrees(roll_2)}, pitch: {np.degrees(pitch_2)}, yaw: {np.degrees(yaw_2)}')




input_quaternion = quaternion.quaternion(qw, qx, qy, qz)














# クォータニオンから回転軸と回転角度を取得
#下の関数で大事なポイントは　クォータニオンから変換して得たのは
#回転ベクトル、このベクトルの方向を回転軸、大きさが回転角度

# 回転ベクトルの取得
rotation_vector = quaternion.as_rotation_vector(input_quaternion)
print(f'rotation_vector: {rotation_vector}')

# 回転ベクトルの長さ（回転角度）を取得
angle = np.linalg.norm(rotation_vector)
print(f'rotation angle: {angle}')

# 回転軸を取得
rotation_axis = rotation_vector / angle if angle != 0 else np.zeros_like(rotation_vector)
print(f'rotation_axis: {rotation_axis}')



def rotate_x_axis(vector, theta_deg):
    theta_rad = math.radians(theta_deg)  # 度数からラジアンに変換
    rotation_matrix = np.array([
        [1, 0, 0],
        [0, math.cos(theta_rad), -math.sin(theta_rad)],
        [0, math.sin(theta_rad), math.cos(theta_rad)]
    ])
    rotated_vector = np.dot(rotation_matrix, vector)
    return rotated_vector
def rotate_y_axis(vector, theta_deg):
    theta_rad = math.radians(theta_deg)
    rotation_matrix = np.array([
        [math.cos(theta_rad), 0, math.sin(theta_rad)],
        [0, 1, 0],
        [-math.sin(theta_rad), 0, math.cos(theta_rad)]
    ])
    rotated_vector = np.dot(rotation_matrix, vector)
    return rotated_vector

def rotate_z_axis(vector, theta_deg):
    theta_rad = math.radians(theta_deg)
    rotation_matrix = np.array([
        [math.cos(theta_rad), -math.sin(theta_rad), 0],
        [math.sin(theta_rad), math.cos(theta_rad), 0],
        [0, 0, 1]
    ])
    rotated_vector = np.dot(rotation_matrix, vector)
    return rotated_vector

def plot_vectors(vec1, vec2):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')

    # 原点からベクトルの始点までの位置を設定
    ax.quiver(0, 0, 0, vec1[0], vec1[1], vec1[2], color='r', label='Vector 1')
    ax.quiver(0, 0, 0, vec2[0], vec2[1], vec2[2], color='b', label='Vector 2')

    # 軸ラベルの設定
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')

    # グラフ表示
    ax.legend()
    plt.show()




def print_result(new_rotation_vector):
    print(f'new_rotation_vector{new_rotation_vector}')

    # 回転軸を取得
    new_rotation_axis = new_rotation_vector / new_angle if new_angle != 0 else np.zeros_like(new_rotation_vector)
    print(f'new_rotation_axis: {new_rotation_axis}')

    # 回転ベクトルの長さ（回転角度）を取得
    new_angle = np.linalg.norm(new_rotation_vector)
    print(f'new_rotation angle: {new_angle}')



new_rotation_vector = rotate_x_axis(rotation_vector,30)
# 回転ベクトルからクォータニオンへの変換
quaternion_result = quaternion.from_rotation_vector(new_rotation_vector)
print(f"Quaternion from rotation vector: {quaternion_result}")

#new_rotation_vector = rotate_y_axis(rotation_vector,-30)
# 回転ベクトルからクォータニオンへの変換
#quaternion_result = quaternion.from_rotation_vector(new_rotation_vector)
#print(f"Quaternion from rotation vector: {quaternion_result}")

#new_rotation_vector = rotate_z_axis(rotation_vector,-30)
# 回転ベクトルからクォータニオンへの変換#
#quaternion_result = quaternion.from_rotation_vector(new_rotation_vector)
#print(f"Quaternion from rotation vector: {quaternion_result}")


new_vec = quaternion.from_rotation_vector( [ 1.62225158 ,-2.67450352, -0.01076135])
print(new_vec)