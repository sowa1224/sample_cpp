#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)
#include <Eigen/Dense>
#include <Eigen/Geometry>
#include <iostream>
#include <cmath>


Eigen::Quaterniond rpyToQuaternion(double roll, double pitch, double yaw) {
    using namespace Eigen;
    Quaterniond q1(0, 0, 0, 1); 
    double offsetroll = roll * M_PI / 180.0;//いわゆるYaw軸回り
    double offsetpitch = pitch * M_PI / 180.0;//いわゆるPitch軸回り、過去のデータでは-20～40まで
    double offsetyaw = yaw * M_PI / 180.0;//いわゆるRoll軸回り

    Matrix3d Rroll, Rpitch, Ryaw;

    Rroll << 1, 0, 0,
             0, cos(offsetroll), -sin(offsetroll),
             0, sin(offsetroll), cos(offsetroll);

    Rpitch << cos(offsetpitch), 0, sin(offsetpitch),
              0, 1, 0,
              -sin(offsetpitch), 0, cos(offsetpitch);

    Ryaw << cos(offsetyaw), -sin(offsetyaw), 0,
            sin(offsetyaw), cos(offsetyaw), 0,
            0, 0, 1;
    Matrix3d Rcombined = Ryaw * Rpitch * Rroll;
    Quaterniond q2(Rcombined);
    Quaterniond q3 = q2 * q1;
    return (q3);
}


Eigen::VectorXd posq(double a, double b, double c, double d, double roll, double pitch, double yaw) {
    using namespace Eigen;
    Quaterniond q = rpyToQuaternion(roll, pitch, yaw);
    VectorXd ps(8);
    ps << a, b, c, d, q.x(), q.y(), q.z(), q.w();
    return ps;
}


int main(){
    KAROperator ks;
    VectorXd p(8);
    double time = 3;
    p=posq(0.33,0.3 , 0.022 , 0.28,0,0,0);
    ks.setq(time,p);
    sleep(3);

    p<<0.483,0.36703,0.022,0.15321,-0.25038,0,0.968148,0;//なんで行けるの？
    ks.setq(time,p);
    sleep(3);    

    p=posq(0.33,0.3,0.022,0.28,40,0,0);
    ks.setq(time,p);
    sleep(3);

    p=posq(0.33,0.3,0.022,0.28,40,0,30);
    ks.setq(time,p);
    sleep(3);

    p=posq(0.33,0.3,0.022,0.28,40,0,0);
    ks.setq(time,p);
    sleep(3);

}