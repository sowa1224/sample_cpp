import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def quaternion_multiply(q1, q2):
    w1, x1, y1, z1 = q1
    w2, x2, y2, z2 = q2
    w = w1 * w2 - x1 * x2 - y1 * y2 - z1 * z2
    x = w1 * x2 + x1 * w2 + y1 * z2 - z1 * y2
    y = w1 * y2 - x1 * z2 + y1 * w2 + z1 * x2
    z = w1 * z2 + x1 * y2 - y1 * x2 + z1 * w2
    return np.array([w, x, y, z])

def plot_quaternions(quaternion_list, colors=['b', 'g'], labels=['Quaternion 1', 'Quaternion 2']):
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')
    for i, quaternion in enumerate(quaternion_list):
        ax.quiver(0, 0, 0, quaternion[1], quaternion[2], quaternion[3], color=colors[i], label=labels[i])
    ax.set_xlim([-1, 1])
    ax.set_ylim([-1, 1])
    ax.set_zlim([-1, 1])
    ax.set_xlabel('X')
    ax.set_ylabel('Y')
    ax.set_zlabel('Z')
    ax.legend()
    plt.show()



quaternion_kar = [0,0,0,1


]
quaternion_kar_1 = [0.00433415 , 0.856152 , 0.516668 , -0.00625894

]
quaternion_kar_2 = [ 0.00737646 , -0.148745 , 0.988847 , 0.00165308

]

# 任意のクォータニオンを定義
original_quaternion = np.array([quaternion_kar[3],quaternion_kar[0],quaternion_kar[1],quaternion_kar[2]])  # [w, x, y, z]
original_quaternion_1=np.array([quaternion_kar_1[3],quaternion_kar_1[0],quaternion_kar_1[1],quaternion_kar_1[2]]) 

original_quaternion_2=np.array([quaternion_kar_2[3],quaternion_kar_2[0],quaternion_kar_2[1],quaternion_kar_2[2]]) 

# x軸90度回転するためのクォータニオン
rotation_quaternion = np.array([np.cos(np.pi / 4), np.sin(np.pi / 4), 0, 0])  # 90度（π/2）回転

# 回転後のクォータニオンを計算
rotated_quaternion = quaternion_multiply(rotation_quaternion, original_quaternion)
rotated_quaternion = quaternion_multiply(rotated_quaternion, np.array([rotation_quaternion[0], -rotation_quaternion[1], -rotation_quaternion[2], -rotation_quaternion[3]]))

#quaternion_list = [original_quaternion, original_quaternion_1]
#plot_quaternions(quaternion_list, colors=['b', 'g'], labels=['Quaternion 1', 'Quaternion 2'])
quaternion_list = [original_quaternion, original_quaternion_1, original_quaternion_2]
plot_quaternions(quaternion_list, colors=['b', 'g', 'r'], labels=['Quaternion_defalut', 'Quaternion 1', 'Quaternion 2'])

# ２つのクォータニオンをリストにしてプロット
#quaternion_list = [original_quaternion, rotated_quaternion]
#plot_quaternions(quaternion_list, colors=['b', 'g'], labels=['Original Quaternion', 'Rotated Quaternion'])


# クォータニオンを表示
print("開店前のKARクウォータニオン",quaternion_kar)
print("回転前のクォータニオン:", original_quaternion)
print("回転後のクォータニオン:", rotated_quaternion)