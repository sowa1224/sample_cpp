import numpy as np
from scipy.spatial.transform import Rotation
import numpy as np

def quaternion_to_euler(q):
    # クォータニオンの要素
    x = q[0]
    y = q[1]
    z = q[2]
    w = q[3]
        # オイラー角の計算
    roll = np.arctan2(2 * (w * x + y * z), 1 - 2 * (x**2 + y**2))
    pitch = np.arcsin(2 * (w * y - z * x))
    yaw = np.arctan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

    # ラジアンを度に変換
    roll_deg = np.degrees(roll)
    pitch_deg = np.degrees(pitch)
    yaw_deg = np.degrees(yaw)


    return roll,pitch,yaw

def euler_to_quaternion(roll, pitch, yaw):
    cy = np.cos(yaw * 0.5)
    sy = np.sin(yaw * 0.5)
    cp = np.cos(pitch * 0.5)
    sp = np.sin(pitch * 0.5)
    cr = np.cos(roll * 0.5)
    sr = np.sin(roll * 0.5)

    w = cr * cp * cy + sr * sp * sy
    x = sr * cp * cy - cr * sp * sy
    y = cr * sp * cy + sr * cp * sy
    z = cr * cp * sy - sr * sp * cy

    return np.array([w, x, y, z])

q_wxyz = [0.0188505, -0.395338, 0.91737, -0.0422521]
roll, pitch, yaw = quaternion_to_euler(q_wxyz)
# yaw軸の角度を30度ずつ5回引いたクォータニオンを出力
for _ in range(5):
    yaw += np.radians(20)  # 10度をラジアンに変換して引く
    updated_quaternion = euler_to_quaternion(roll, pitch, yaw)
    #print("Updated Quaternion:", updated_quaternion)
    print(f"{updated_quaternion[0],updated_quaternion[1],updated_quaternion[2],updated_quaternion[3]}")

"""
q_kar = [ 0.0188505, -0.395338, 0.91737, -0.0422521]
q_wxyz =[q_kar[3],q_kar[0],q_kar[1],q_kar[2]]
print(f'q_karは{q_kar}')
print(f'q_wxyz{q_wxyz}')

O=quaternion_to_euler(q_wxyz)
print(f'オイラー角は:{O}')
print(f'roll{np.degrees(O[0])},pitch{np.degrees(O[1])},yaw{np.degrees(O[2])}')
print(f'オイラー角からの変換:{euler_to_quaternion(O[0],O[1],O[2])}')
"""





"""
# クォータニオンからオイラー角への変換
def quaternion_to_euler(quaternion):
    r = Rotation.from_quat(quaternion)
    euler = r.as_euler('zyx', degrees=True)
    return euler

# オイラー角からクォータニオンへの変換
def euler_to_quaternion(euler):
    r = Rotation.from_euler('zyx', euler, degrees=True)
    quaternion = r.as_quat()
    return quaternion

# サンプルクォータニオン
#入力する順序は[z,y,x,w],karではx,y,z,wの順序なので注意
quaternion_kar=[ 0.128105 , 0.791139 , 0.583475 , -0.131323
]
print("API表示したクウォータニオンxyzw",quaternion_kar)
q_x=quaternion_kar[0]
q_y=quaternion_kar[1]
q_z=quaternion_kar[2]
q_w=quaternion_kar[3]
quaternion = [q_z,q_y,q_x,q_w]
print("変換用クウォータニオンzyxw:",quaternion)
#quaternion=[ 1,0,0,0]
#何も回転しない場合は[0,0,0,1]




# クォータニオンからオイラー角への変換
#出力されるオイラー角は[z,y,x]の順序計算上オイラー角の変換順序はz→y→x
euler_angles = quaternion_to_euler(quaternion)
euler_angles_xyz =[euler_angles[2],euler_angles[1],euler_angles[0]] 
print("オイラー角x,y,z:", euler_angles_xyz)

# オイラー角からクォータニオンへの変換
#入力するオイラー角は[z,y,x]
new_quaternion = euler_to_quaternion(euler_angles)
new_quaternion_kar = [new_quaternion[2],new_quaternion[1],new_quaternion[0],new_quaternion[3]]
print("クォータニオンz,y,x,w:", new_quaternion)

print("kar用クォータニオンx,y,z,w:", new_quaternion_kar)


#euler = [-120.22891116,    0.21180878, -179.15808022]
#qua=euler_to_quaternion(euler)
#print(f"{-1*qua[2]},{-1*qua[1]},{-1*qua[0]},{-1*qua[3]}")
#print(quaternion_to_euler(qua))


euler = [-80,0.69499743,-179.47182526]
qua=euler_to_quaternion(euler)
print(f"{-1*qua[2]},{-1*qua[1]},{-1*qua[0]},{-1*qua[3]}")

euler = [-100,0.69499743,-179.47182526]
qua=euler_to_quaternion(euler)
print(f"{-1*qua[2]},{-1*qua[1]},{-1*qua[0]},{-1*qua[3]}")

def quaternion_to_rotation_matrix(q):
    # クォータニオンの要素
    w, x, y, z = q

    # 回転行列の要素を計算
    rotation_matrix = np.array([
        [1 - 2 * (y**2 + z**2), 2 * (x * y - w * z), 2 * (x * z + w * y)],
        [2 * (x * y + w * z), 1 - 2 * (x**2 + z**2), 2 * (y * z - w * x)],
        [2 * (x * z - w * y), 2 * (y * z + w * x), 1 - 2 * (x**2 + y**2)]
    ])

    return rotation_matrix



def rotation_matrix_to_quaternion(rotation_matrix):
    trace = np.trace(rotation_matrix)
    if trace > 0:
        S = 2 * np.sqrt(trace + 1.0)
        w = 0.25 * S
        x = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) / S
        y = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) / S
        z = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) / S
    else:
        if rotation_matrix[0, 0] > rotation_matrix[1, 1] and rotation_matrix[0, 0] > rotation_matrix[2, 2]:
            S = 2.0 * np.sqrt(1.0 + rotation_matrix[0, 0] - rotation_matrix[1, 1] - rotation_matrix[2, 2])
            w = (rotation_matrix[2, 1] - rotation_matrix[1, 2]) / S
            x = 0.25 * S
            y = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / S
            z = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / S
        elif rotation_matrix[1, 1] > rotation_matrix[2, 2]:
            S = 2.0 * np.sqrt(1.0 + rotation_matrix[1, 1] - rotation_matrix[0, 0] - rotation_matrix[2, 2])
            w = (rotation_matrix[0, 2] - rotation_matrix[2, 0]) / S
            x = (rotation_matrix[0, 1] + rotation_matrix[1, 0]) / S
            y = 0.25 * S
            z = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / S
        else:
            S = 2.0 * np.sqrt(1.0 + rotation_matrix[2, 2] - rotation_matrix[0, 0] - rotation_matrix[1, 1])
            w = (rotation_matrix[1, 0] - rotation_matrix[0, 1]) / S
            x = (rotation_matrix[0, 2] + rotation_matrix[2, 0]) / S
            y = (rotation_matrix[1, 2] + rotation_matrix[2, 1]) / S
            z = 0.25 * S

    return np.array([w, x, y, z])

    R=quaternion_to_rotation_matrix(q_wxyz)
print(f'回転行列は：{R}')
print(f'回転行列からの変換：{rotation_matrix_to_quaternion(R)}')
"""



