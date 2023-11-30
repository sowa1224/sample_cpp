import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from scipy.spatial.transform import Rotation as R

# ロボットの手先の位置 (x, y, z)
position = np.array([1.0, 2.0, 3.0])

# クォータニオン (w, x, y, z)
quaternion_kar = [0.632507, 0.294905, 0.535454, 0.475662]
quaternion = np.array([quaternion_kar[3], quaternion_kar[0], quaternion_kar[1], quaternion_kar[2]])  # 例として適当な値を設定しています

# クォータニオンを回転行列に変換
rotation_matrix = R.from_quat(quaternion).as_matrix()

# x, y, z軸の方向ベクトル
x_axis = rotation_matrix[:, 0]
y_axis = rotation_matrix[:, 1]
z_axis = rotation_matrix[:, 2]

# 45度回転するためのクォータニオンを生成
angle = np.radians(45)  # 45度をラジアンに変換
new_quaternion = R.from_quat(quaternion).apply(R.from_rotvec(angle * np.array([1, 0, 0])).as_quat())

# 新しいクォータニオンを回転行列に変換
new_rotation_matrix = R.from_quat(new_quaternion).as_matrix()

# 新しいx軸方向ベクトル
new_x_axis = new_rotation_matrix[:, 0]

# プロットの準備
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# 手先の位置をプロット
ax.scatter(position[0], position[1], position[2], color='red', label='Hand Position')

# 手先の姿勢を矢印でプロット
ax.quiver(position[0], position[1], position[2], x_axis[0], x_axis[1], x_axis[2], length=0.5, color='blue', label='X-axis')
ax.quiver(position[0], position[1], position[2], y_axis[0], y_axis[1], y_axis[2], length=0.5, color='green', label='Y-axis')
ax.quiver(position[0], position[1], position[2], z_axis[0], z_axis[1], z_axis[2], length=0.5, color='orange', label='Z-axis')

# 新しいx軸方向ベクトルをプロット (45度回転後)
ax.quiver(position[0], position[1], position[2], new_x_axis[0], new_x_axis[1], new_x_axis[2],
          length=0.5, color='purple', linestyle='dashed', label='X-axis (45° rotation)')

# 軸ラベルの設定
ax.set_xlabel('X-axis')
ax.set_ylabel('Y-axis')
ax.set_zlabel('Z-axis')

# 凡例の表示
ax.legend()

# グラフ全体が見えるように軸の範囲を設定
ax.set_xlim([-1, 1])
ax.set_ylim([-1, 3])
ax.set_zlim([1, 4])

# グラフの表示
plt.show()
