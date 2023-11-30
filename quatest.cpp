#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>

int main() {
    double rotation_angle = 0.1; // 回転角度（ラジアン）
    double total_rotation = 2.0 * M_PI; // 総回転角度（ラジアン）
    int num_steps = static_cast<int>(total_rotation / rotation_angle); // ステップ数

    Eigen::Quaterniond initial_quaternion(0.0150307, 0.406642, 0.912921, -0.0314963); // 初期クォータニオン
    Eigen::Quaterniond quaternion = initial_quaternion; // クォータニオン
    Eigen::Vector3d axis = Eigen::Vector3d::UnitX(); // 回転軸（x軸）

    for (int i = 0; i <= num_steps; i++) {
        double angle = i * rotation_angle; // 現在の回転角度

        // クォータニオンの計算
        quaternion = initial_quaternion * Eigen::Quaterniond(Eigen::AngleAxisd(angle, axis));

        // クォータニオンの出力

        std::cout << " posq <<0.45 , 0.55, -0.0102505 , 0.126 ," << quaternion.x() << ", " << quaternion.y() << ", "
                  << quaternion.z() << ", " << quaternion.w() << ";\n sleep(5);\n ks.setq(time,posq);"<<std::endl;

        // 手先の位置姿勢の計算
        Eigen::Matrix3d rotation_matrix = quaternion.toRotationMatrix(); // 回転行列
        Eigen::Vector3d position = rotation_matrix * Eigen::Vector3d::UnitZ(); // 手先の位置

        // 手先の位置姿勢の出力
        //std::cout << "Position (" << i << "): " << position.x() << ", " << position.y() << ", "
                  //<< position.z() << std::endl;
    }

    return 0;
}
