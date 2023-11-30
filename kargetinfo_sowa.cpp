#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)
#include <fstream>
using namespace std;
int main(){
    KAROperator ks;
    ofstream ofs("data.csv");
    int err;//エラー
    int servooffreaseon;//サーボオフになった原因
    keyboard kb;//キーボード
    VectorXd force;//力センサ
    VectorXd posq;//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    while(1){
        ks.getforce(force);
        ks.getq(posq);
        ks.geterror(err,servooffreaseon);
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        sleep(1);
    ofs<<posq[0]<<std::endl;
    ofs<<posq[1]<<std::endl;
    ofs<<posq[2]<<std::endl;
    ofs<<posq[3]<<std::endl;
    ofs<<posq[4]<<std::endl;
    ofs<<posq[5]<<std::endl;
    ofs<<posq[6]<<std::endl;
    ofs<<posq[7]<<std::endl;
        if(kb.getkey()=='q'){break;}
    }
}