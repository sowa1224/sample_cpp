#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <KAR/KARoperator.h> // 適切なヘッダを含める
#include <Eigen/Dense>

using namespace Eigen;
//初期位置姿勢posq<<0.47,0.35 , 0.022 , 0.28,0,0,1,0;　個々での0.023はいわゆるy=0

int main() {
    KAROperator ks;
    VectorXd posq(8); // 手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 4.0; // 移動時0,間


posq<<0.483,0.35 , 0.022 , 0.28,0,0,1,0;
ks.setq(time,posq);
sleep(5);

posq<<0.483,0.38 , 0.022 , 0.2,0,0,1,0;
ks.setq(time,posq);
sleep(5);


/*芽取り用の初期値点の設定と確認
posq<<0.483,0.4 , -0.04 , 0.14,0,0,1,0;
ks.setq(time,posq);
sleep(5);
posq<<0.483,0.3 , 0.08 , 0.3,0,0,1,0;
ks.setq(time,posq);
sleep(5);
*/


/*
posq<<0.47,0.31874,0.01999+0.022,0.19148-0.01,0,0.104528,0.994522,0;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.31874,0.01999+0.022,0.19148-0.01,0, 0.66262, 0.748956 ,0;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.4 , 0.022 , 0.3,0, 0.66262, 0.748956 ,0;
ks.setq(time,posq);
sleep(3);



//remove x+0.03or-0.02 y+0.022 z-0.01

*/



//正しい皮むき用
  std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/test/remove/data/remove_kar.csv");
 //std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/test/peel/data/peel_kar.csv");
 // std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/test/peel/0305/3/0/peel_kar.csv");
//std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/test/peel/0204_peel_1/peel_4/peel_kar.csv");

//    std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/test/peel/peel_kar.csv");
    std::vector<VectorXd> data; // CSVファイルのデータを格納するベクトル

    std::string line;
    bool header = true; // 最初の行がヘッダーかどうかを示すフラグ
    while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue; // ヘッダー行をスキップする
        }

        std::istringstream iss(line);
        std::string token;
        VectorXd row(8);

        int index = 0;
        while (std::getline(iss, token, ',')) {
            row(index++) = std::stod(token);
        }

        data.push_back(row);
    }

    for (const auto& row : data) {
      //  posq << row(0), row(1)-0.15, row(2)-0.018, row(3)-0.007, row(4), row(5), row(6), row(7);
       posq << 0.483, row(1), row(2)+0.02, row(3)+0.025, row(4), row(5), row(6), row(7);
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        ks.setq(3.0, posq);
        sleep(3);
    }

    return 0;




}









/*

posq<<0.47,0.35 , 0.022 , 0.28,0.173648, 0, 0.984808 ,0
;
ks.setq(time,posq);
sleep(10);



posq<<0.47,0.35 , 0.022 , 0.2,-0.258819, 0, 0.965926 ,0
;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.33 , 0.022 , 0.23, -0.173648, 0, 0.984808 ,0
;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.35 , 0.022, 0.28,   -0.0871557, 0, 0.996195 ,0
;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.3 , 0.022 , 0.3,  0,0,1,0
;
ks.setq(time,posq);
sleep(5);

posq<<0.47,0.27 , 0.022 , 0.33,   0.0871557, 0, 0.996195 ,0
;
ks.setq(time,posq);
sleep(20);

posq<<0.47,0.25 , 0.022 , 0.36, 0.173648, 0, 0.984808 ,0
;
ks.setq(time,posq);
sleep(5);

    std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/real_do_program/peel_posi.csv");
    std::vector<VectorXd> data; // CSVファイルのデータを格納するベクトル

    std::string line;
    bool header = true; // 最初の行がヘッダーかどうかを示すフラグ
    while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue; // ヘッダー行をスキップする
        }

        std::istringstream iss(line);
        std::string token;
        VectorXd row(8);

        int index = 0;
        while (std::getline(iss, token, ',')) {
            row(index++) = std::stod(token);
        }

        data.push_back(row);
    }

    for (const auto& row : data) {
        posq << row(0), row(1)-0.16, 0, row(3)+0.02,  0, 0, 1,0;
       // posq << row(0), row(1)-0.1, row(2), row(3), row(4), row(5), row(6), row(7);
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        ks.setq(time, posq);
        sleep(3);
    }

    return 0;



    posq<<0.483,0.3 , 0.0 , 0.2,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);

    posq<<0.483,0.4 , 0.0 , 0.2,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);


    posq<<0.483,0.3 , 0.0 , 0.2,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);



    posq<<0.483,0.3 , 0.0 , 0.3,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);

    posq<<0.483,0.4 , 0.0 , 0.3,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);


    posq<<0.483,0.3 , 0.0 , 0.3,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);


    posq<<0.483,0.4 , 0.0 , 0.3,0, 0, 1 ,0;
    ks.setq(time,posq);
    sleep(8);

    posq<<0.483,0.242,0.024,0.15193,0,-0.14033644940381387,0.9901038738277569,0;
    ks.setq(time,posq);
    sleep(8);
    posq<<0.483,0.212,0.048,0.15193, 0, 0.766044, 0.642788 ,0;
    ks.setq(time,posq);
    sleep(8);
    posq<<0.483,0.36,0.048,0.15193, 0, 0.766044, 0.642788 ,0;
    ks.setq(time,posq);
    sleep(8);

//皮むき用
    // CSVファイルからのデータ読み取り
    std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/real_do_program/peel_posi.csv");
    std::vector<VectorXd> data; // CSVファイルのデータを格納するベクトル

    std::string line;
    bool header = true; // 最初の行がヘッダーかどうかを示すフラグ
    while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue; // ヘッダー行をスキップする
        }

        std::istringstream iss(line);
        std::string token;
        VectorXd row(8);

        int index = 0;
        while (std::getline(iss, token, ',')) {
            row(index++) = std::stod(token);
        }

        data.push_back(row);
    }

    for (const auto& row : data) {
        posq << row(0), row(1)-0.125, row(2), row(3)+0.0115, 0, 0, 1,0;
     //   posq << row(0), row(1), row(2), row(3)+0.02, row(4), row(5), row(6), row(7);
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        ks.setq(time, posq);
        sleep(5);
    }

    return 0;




//芽取り用
    // CSVファイルからのデータ読み取り
    std::ifstream file("/home/sowa/prog/pointcloud/pointcloud_program/real_do_program/remove/remove_posi.csv");
    std::vector<VectorXd> data; // CSVファイルのデータを格納するベクトル

    std::string line;
    bool header = true; // 最初の行がヘッダーかどうかを示すフラグ
    while (std::getline(file, line)) {
        if (header) {
            header = false;
            continue; // ヘッダー行をスキップする
        }

        std::istringstream iss(line);
        std::string token;
        VectorXd row(8);

        int index = 0;
        while (std::getline(iss, token, ',')) {
            row(index++) = std::stod(token);
        }

        data.push_back(row);
    }

    for (const auto& row : data) {
        posq << row(0), row(1)-0.012, row(2), row(3), row(4), row(5), row(6), row(7);
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        ks.setq(time, posq);
        sleep(5);


    }

    return 0;


*/



/*
posq<<0.483,0.3 , 0.0 , 0.3,0, 0, 1 ,0
;
ks.setq(time,posq);
sleep(5);
posq<<0.483,0.31543, 0.0, 0.13630,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31543, 0.0, 0.146,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31494, 0.0, 0.148,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31413, 0.0, 0.151,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31364, 0.0, 0.154,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31331, 0.0, 0.155,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31299, 0.0, 0.157,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31136, 0.0, 0.162,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.31071, 0.0, 0.164,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.30957, 0.0, 0.16,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.30908, 0.0, 0.167,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.30811, 0.0, 0.169,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.30762, 0.0, 0.170,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);
posq<<0.483,0.30599, 0.0, 0.174,0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(2);











posq<<0.483,0.37 , 0.0 , 0.2,0, 0,1,0
;
ks.setq(time,posq);
sleep(10);

posq<<0.481,0.273 , 0.034 , 0.16, 0, -0.34202, 0.939693 ,0
;
ks.setq(time,posq);
sleep(10);




posq<<0.481,0.268 , 0.034 , 0.16, 0, -0.258819, 0.965926 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.263 , 0.034 , 0.16, 0, -0.16648, 0.984808 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.258 , 0.034 , 0.16, 0, -0.0871557, 0.996195 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.253 , 0.034 , 0.16,  0, 0, 1 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.248 , 0.034 , 0.16,  0, 0.0871557, 0.996195 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.245 , 0.034 , 0.16, 0, 0.16648, 0.984808 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.243 , 0.034 , 0.16, 0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.245 , 0.034 , 0.16,0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.248 , 0.034 , 0.16,  0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.26 , 0.034 , 0.16,  0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.3 , 0.034 , 0.16,  0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.34 , 0.034 , 0.16,0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

posq<<0.481,0.36 , 0.034 , 0.16,0, 0.422618, 0.906308 ,0
;
ks.setq(time,posq);
sleep(3);

}
*/

//12/16メモ　キャリブレーション時のAPI上の姿勢は0.650614 , -0.355919 , 0.451662 , -0.496009
//もしwxyzの順ならオイラー角はroll-69.61225309043303,pitch13.570237125844347,yaw-84.09821630723097
//仮にxyzwの順ならroll-95.90183081648989,pitch-13.570237125844347,yaw-69.61225309043303
//成功したc++のプログラムは以下
/*
#include <iostream>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

int main() {
    Eigen::Quaterniond q1(0, 0, 0, 1);
    Eigen::Matrix3d Ryaw;
        Eigen::Matrix3d Rpitch;
    double offsetyaw =-30 * M_PI / 180.0;
    Ryaw << 1,0,0,
    0,cos(offsetyaw),-sin(offsetyaw),
            0,sin(offsetyaw),cos(offsetyaw);
    Eigen::Quaterniond q2(Ryaw);
    Eigen::Quaterniond q3 = q2 * q1; // Applying q2 rotation to q1

    // Getting new pose from q3 quaternion
    Eigen::Vector3d new_pose = q3.toRotationMatrix().eulerAngles(2, 1, 0); // Assuming ZYX rotation order

    // Output new pose (Yaw, Roll, Pitch)
    std::cout << "New Pose (Yaw, Roll, Pitch): " << new_pose.transpose()*180/3.14 << std::endl;

    // Output q3 quaternion
    std::cout << "q3 Quaternion (w, x, y, z): " << q3.w() << " " << q3.x() << " " << q3.y() << " " << q3.z() << std::endl;

    std::cout << "q3 Quaternion (x, y, z, w): " << q3.x() << ", " << q3.y() << ", " << q3.z() << " ," << q3.w() << std::endl;

    return 0;
}

    こっちの限度は-45~45
    double offsetroll =-10 * M_PI / 180.0;
    Rroll <<cos(offsetyaw), -sin(offsetyaw),0,
            sin(offsetyaw), cos(offsetyaw),0,
            0,0,1;
    こっちの限度は-120~85
    double offsetpitch =-10 * M_PI / 180.0;
    Rpitch << 1,0,0,
    0,cos(offsetyaw),-sin(offsetyaw),
            0,sin(offsetyaw),cos(offsetyaw);

    こっちも限度は-7.5~40
    double offsetpitch =-10 * M_PI / 180.0;
    Ryaw << cos(offsetyaw),0, sin(offsetyaw),
            0,1,0,
            -sin(offsetyaw),0, cos(offsetyaw);

*/




//;
/*
/*
void run(float time, float rail, float x, float y, float z, float qx, float qy, float qz, float qw)
{
        KAROperator ks;
    VectorXd posq(8);
    posq<<rail,x,y,z,qx,qy,qz,qw;
    ks.setq(time,posq);
    sleep(1);
}

double roll;
double pitch;
double yaw;

double qx;
double qy;
double qz;
double qw;

typedef struct q
{
    float x;
    float y;
    float z;
    float w;
};

typedef struct o
{
    float roll;
    float pitch;
    float yaw;
};



void calc_rpy_to_quat(o rpy, double& qx, double& qy, double& qz, double& qw){
	double cy = cos(rpy.yaw * 0.5);
    double sy = sin(rpy.yaw * 0.5);
    double cp = cos(rpy.pitch * 0.5);
    double sp = sin(rpy.pitch * 0.5);
    double cr = cos(rpy.roll * 0.5);
    double sr = sin(rpy.roll * 0.5);

    qw = cr * cp * cy + sr * sp * sy;
    qx = sr * cp * cy - cr * sp * sy;
    qy = cr * sp * cy + sr * cp * sy;
    qz = cr * cp * sy - sr * sp * cy;
}


void calc_quat_to_rpy(q geometry_quat, double& roll, double& pitch, double& yaw){
	float q0q0 = geometry_quat.w * geometry_quat.w;
	float q1q1 = geometry_quat.x * geometry_quat.x;
	float q2q2 = geometry_quat.y * geometry_quat.y;
	float q3q3 = geometry_quat.z * geometry_quat.z;
	float q0q1 = geometry_quat.w * geometry_quat.x;
	float q0q2 = geometry_quat.w * geometry_quat.y;
	float q0q3 = geometry_quat.w * geometry_quat.z;
	float q1q2 = geometry_quat.x * geometry_quat.y;
	float q1q3 = geometry_quat.x * geometry_quat.z;
	float q2q3 = geometry_quat.y * geometry_quat.z;

    roll = atan2f((2.f * (q2q3 + q0q1)), (q0q0 - q1q1 - q2q2 + q3q3));
    pitch = -asinf((2.f * (q1q3 - q0q2)));
    yaw = atan2f((2.f * (q1q2 + q0q3)), (q0q0 + q1q1 - q2q2 - q3q3));
}



    q test;

    test.w =0.0188505;
    test.x =-0.395338; 
    test.y = 0.91737;
    test.z =  -0.0422521;
    calc_quat_to_rpy(test,roll,pitch,yaw);
    printf("%f %f %f ",roll*180/3.14,pitch*180/3.14,yaw*180/3.14);
    ks.setq(time,posq);
        sleep(1);    

    for(float i=0.0; i>-120.0*3.14/180; i-=30.0*3.14/180)
    {
        o test;
        test.roll = 0.0;
        test.pitch = 0.0;
        test.yaw = i;
        calc_rpy_to_quat(test, qx, qy, qz, qw);
           
        posq<<0.483888 , 0.522864 , -0.00920468 , 0.314561 , qx , qy , qz,qw ;
        ks.setq(time,posq);
        sleep(1);    
         printf("%f %f %f %f ",qw,qx,qy,qz);
        

    }
*/ 
 

//オイラー角度roll45.87978659666439,pitch-0.8672399888419537,yaw179.93611987740218
   
//オイラー角度roll-14.120213403335606,pitch-0.8672399888419536,yaw179.93611987740218









//y-0.0803673335564482, -0.134004520160496, 0.983884410809524, 0.0869214958429587
//z-0.0803673335564485, -0.630083707292607, 0.772312860847326, 0.00827396345469747










//デフォルト
//    posq<<0.351197 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673 , -0.159512 , 0.983884 , 0.00827396;
//    ks.setq(time,posq);
//        sleep(1);   

//y
//    posq<<0.351197 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673 , -0.159512 , 0.983884 , 0.00827396;
//    ks.setq(time,posq);
//        sleep(1);   
//    posq<<0.351197 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673335564482, -0.134004520160496, 0.983884410809524, 0.0869214958429587;
//    ks.setq(time,posq);
//        sleep(1);   


//z
//    posq<<0.351197 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673 , -0.159512 , 0.983884 , 0.00827396;
//    ks.setq(time,posq);
//        sleep(1);   
//    posq<<0.351197 , 0.522037 , -0.00137562 , 0.311119 , -0.0803673335564485, -0.630083707292607, 0.772312860847326, 0.00827396345469747;
//    ks.setq(time,posq);
//        sleep(1);   















//rail原点は0.0512052

// 0.311037 , 0.542007 , -0.000644983 , 0.21664 , 0.00752422 , 0.182187 , 0.983235 , -0.000837038
// 0.31,0.54,0.0,0.22,0,0,1,0

/*

テスト用の初期位置
    posq<<0.361794 , 0.462466 , -0.00141845 , 0.26669 , 0.00723724 , 0.369003 , 0.929397 , -0.00227366
;











ヨー軸を３０度づつマイナスのつもりがロール軸になっている
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);        


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.10781206412165328, 0.3746117574308317, 0.8901409118877824, 0.23599098925170714
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.20109511446306297, 0.33394335584747814, 0.798731133337985, 0.45833521211121275
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.28067386507920444, 0.2705172664306076, 0.6528891480168117, 0.6494446477000899
;

    ks.setq(time,posq);
        sleep(1);   

使用した関数
# クォータニオンからオイラー角を取得
roll, pitch, yaw = quaternion_to_euler(q_wxyz)

def quaternion_to_euler(q):
    # クォータニオンの要素
    w, x, y, z = q

    # オイラー角の計算
    roll = np.arctan2(2 * (w * x + y * z), 1 - 2 * (x**2 + y**2))
    pitch = np.arcsin(2 * (w * y - z * x))
    yaw = np.arctan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

    # ラジアンを度に変換
    roll_deg = np.degrees(roll)
    pitch_deg = np.degrees(pitch)
    yaw_deg = np.degrees(yaw)


    return roll,pitch,yaw

# yaw軸の角度を30度ずつ5回引いたクォータニオンを出力
for _ in range(5):
    yaw -= np.radians(30)  # 10度をラジアンに変換して引く
    updated_quaternion = euler_to_roll, pitch, yaw)
    #print("Updated Quaternion:", updated_quaternion)
    print(f"{updated_quaternion[1],updated_quaternion[2],updated_quaternion[3],updated_quaternion[0]}")















!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
ロールー軸を30度マイナスのつまりがヨー軸になっている
!!!!!!!!!!!!!その逆も可能　ロール軸をプラスにしたらよー軸のプラスになった
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);        


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.1381260183433962, 0.9903855902317626, -0.0004933033083495566
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671723, 0.992388663760853, 0.0014834062078802515
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.006804606922133188, -0.37557215430690477, 0.9267620898544501, 0.0033590240424876874
;

    ks.setq(time,posq);
        sleep(1);   
使用した関数
# クォータニオンからオイラー角を取得
roll, pitch, yaw = quaternion_to_euler(q_wxyz)

def quaternion_to_euler(q):
    # クォータニオンの要素
    w, x, y, z = q

    # オイラー角の計算
    roll = np.arctan2(2 * (w * x + y * z), 1 - 2 * (x**2 + y**2))
    pitch = np.arcsin(2 * (w * y - z * x))
    yaw = np.arctan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

    # ラジアンを度に変換
    roll_deg = np.degrees(roll)
    pitch_deg = np.degrees(pitch)
    yaw_deg = np.degrees(yaw)


    return roll,pitch,yaw

# yaw軸の角度を30度ずつ5回引いたクォータニオンを出力
for _ in range(5):
    roll -= np.radians(30)  # 10度をラジアンに変換して引く
    updated_quaternion = euler_to_roll, pitch, yaw)
    #print("Updated Quaternion:", updated_quaternion)
    print(f"{updated_quaternion[1],updated_quaternion[2],updated_quaternion[3],updated_quaternion[0]}")




これは上から見ると逆時計回りに回転したら時計回りに回転するようになる
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);        


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.1381260183433962, 0.9903855902317626, -0.0004933033083495566
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671723, 0.992388663760853, 0.0014834062078802515
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.006804606922133188, -0.37557215430690477, 0.9267620898544501, 0.0033590240424876874
;

    ks.setq(time,posq);
        sleep(1);  

    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671723, 0.992388663760853, 0.0014834062078802515
;
    ks.setq(time,posq);
        sleep(1);   


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.1381260183433962, 0.9903855902317626, -0.0004933033083495566
;

    ks.setq(time,posq);
        sleep(1);   


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);     

    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671717, 0.992388663760853, 0.001483406207880251
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.13812601834339625, 0.9903855902317626, -0.000493303308349557
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.007186772376560993, 0.3897501411474452, 0.9208893754179508, -0.0024363950193376045
;

    ks.setq(time,posq);
        sleep(1);  
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.13812601834339625, 0.9903855902317626, -0.000493303308349557
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671717, 0.992388663760853, 0.001483406207880251
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);     
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!












ヨー軸を30度マイナスのつまりがヨー軸になっている
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);        


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007572474478578624, 0.1381260183433962, 0.9903855902317626, -0.0004933033083495566
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.007442124958986886, -0.12291116434671723, 0.992388663760853, 0.0014834062078802515
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.006804606922133188, -0.37557215430690477, 0.9267620898544501, 0.0033590240424876874
;

    ks.setq(time,posq);
        sleep(1);   
使用した関数
# クォータニオンからオイラー角を取得
roll, pitch, yaw = quaternion_to_euler(q_wxyz)

def quaternion_to_euler(q):
    # クォータニオンの要素
    w, x, y, z = q

    # オイラー角の計算
    roll = np.arctan2(2 * (w * x + y * z), 1 - 2 * (x**2 + y**2))
    pitch = np.arcsin(2 * (w * y - z * x))
    yaw = np.arctan2(2 * (w * z + x * y), 1 - 2 * (y**2 + z**2))

    # ラジアンを度に変換
    roll_deg = np.degrees(roll)
    pitch_deg = np.degrees(pitch)
    yaw_deg = np.degrees(yaw)


    return roll,pitch,yaw

# yaw軸の角度を30度ずつ5回引いたクォータニオンを出力
for _ in range(5):
    roll -= np.radians(30)  # 10度をラジアンに変換して引く
    updated_quaternion = euler_to_roll, pitch, yaw)
    #print("Updated Quaternion:", updated_quaternion)
    print(f"{updated_quaternion[1],updated_quaternion[2],updated_quaternion[3],updated_quaternion[0]}")









ピッチ軸を20度マイナスにやるつもり
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.00718677 , 0.38975 , 0.92089 , -0.00243639
;

    ks.setq(time,posq);
        sleep(1);        


    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 , 0.1698777994710373, 0.38322759802299755, 0.9057264844264575, -0.07008013178034922
;

    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.32171494832384756, 0.3650608782551427, 0.8630435525253819, -0.13559451919947269
;
    ks.setq(time,posq);
        sleep(1);   
    posq<<0.302693 , 0.524271 , -0.00148314 , 0.28809 ,0.46666697079139013, 0.33580196843122306, 0.7941374790019322, -0.19698893576685755
;

    ks.setq(time,posq);
        sleep(1);  

# yaw軸の角度を10度ずつ5回引いたクォータニオンを出力
for _ in range(5):
    pitch -= np.radians(20)  # 10度をラジアンに変換して引く
    updated_quaternion = euler_to_roll, pitch, yaw)
    #print("Updated Quaternion:", updated_quaternion)
    print(f"{updated_quaternion[1],updated_quaternion[2],updated_quaternion[3],updated_quaternion[0]}")
*/