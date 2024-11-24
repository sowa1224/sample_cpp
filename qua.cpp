#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

int main() {
    Eigen::Quaterniond q1(0, 0, 0, 1);
    Eigen::Matrix3d Ryaw;
        Eigen::Matrix3d Rpitch;
    double offsetyaw =-80 * M_PI / 180.0;


    Ryaw << 1,0,0,
    0,cos(offsetyaw),-sin(offsetyaw),
            0,sin(offsetyaw),cos(offsetyaw);

    Eigen::Quaterniond q2(Ryaw);
    Eigen::Quaterniond q3 = q2 * q1; // Applying q2 rotation to q1
    // Getting new pose from q3 quaternion
    Eigen::Vector3d default_pose = q1.toRotationMatrix().eulerAngles(2, 1, 0); // Assuming ZYX rotation order

    // Output new pose (Yaw, Roll, Pitch)
    std::cout << "Default Pose (Yaw, Roll, Pitch): " << default_pose.transpose()*180/3.14 << std::endl;

    // Getting new pose from q3 quaternion
    Eigen::Vector3d new_pose = q3.toRotationMatrix().eulerAngles(2, 1, 0); // Assuming ZYX rotation order

    // Output new pose (Yaw, Roll, Pitch)
    std::cout << "New Pose (Yaw, Roll, Pitch): " << new_pose.transpose()*180/3.14 << std::endl;

    // Output q3 quaternion
    std::cout << "q3 Quaternion (w, x, y, z): " << q3.w() << " " << q3.x() << " " << q3.y() << " " << q3.z() << std::endl;

    std::cout << "q3 Quaternion (x, y, z, w): " << q3.x() << ", " << q3.y() << ", " << q3.z() << " ," << q3.w() << std::endl;
    // Output rotation matrix of q1
    Eigen::Matrix3d R1 = q1.toRotationMatrix();
    std::cout << "R1 Rotation Matrix: \n" << R1 << std::endl;

    // Output rotation matrix of q3
    Eigen::Matrix3d R3 = q3.toRotationMatrix();
    std::cout << "R3 Rotation Matrix: \n" << R3 << std::endl;

    return 0;
}

/*
    こっちの限度は-45~45　下の回転行列正式にはYaw軸回転
    double offsetroll =-10 * M_PI / 180.0;
    Rrro <<cos(offsetyaw), -sin(offsetyaw),0,
            sin(offsetyaw), cos(offsetyaw),0,
            0,0,1;
    こっちの限度は-120~85　下の回転行列正式にはRoll軸回転
    double offsetpitch =-10 * M_PI / 180.0;
    Rpitch << 1,0,0,
    0,cos(offsetyaw),-sin(offsetyaw),
            0,sin(offsetyaw),cos(offsetyaw);

    こっちも限度は-30~40　下の回転行列正式にはPitch軸回転
    double offsetpitch =-10 * M_PI / 180.0;
    Ryaw << cos(offsetyaw),0, sin(offsetyaw),
            0,1,0,
            -sin(offsetyaw),0, cos(offsetyaw);


]*/