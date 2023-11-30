import math

# オイラー角（ロール、ピッチ、ヨー）をラジアンで指定
roll = input("roll?")
pitch = input("pitch?")
yaw = input("yaw?")


roll = math.radians(float(roll))
pitch = math.radians(float(pitch))
yaw = math.radians(float(yaw))

# オイラー角からクォータニオンへの変換関数
def euler_to_quaternion(roll, pitch, yaw):
    cy = math.cos(yaw * 0.5)
    sy = math.sin(yaw * 0.5)
    cp = math.cos(pitch * 0.5)
    sp = math.sin(pitch * 0.5)
    cr = math.cos(roll * 0.5)
    sr = math.sin(roll * 0.5)

    w = cy * cp * cr + sy * sp * sr
    x = cy * cp * sr - sy * sp * cr
    y = sy * cp * sr + cy * sp * cr
    z = sy * cp * cr - cy * sp * sr

    return (w, x, y, z)

# オイラー角からクォータニオンへ変換
quaternion = euler_to_quaternion(roll, pitch, yaw)

# 結果の表示
print("クォータニオン: ", quaternion)
