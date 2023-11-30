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

    ofs<<"posq(rail)"<<","<<std::endl;
    ofs<<"posq(x)"<<","<<std::endl;
    ofs<<"posq(y)"<<","<<std::endl;
    ofs<<"posq(z)"<<","<<std::endl;
    ofs<<"posq(q_x)"<<","<<std::endl;
    ofs<<"posq(q_y)"<<","<<std::endl;
    ofs<<"posq(q_z)"<<","<<std::endl;
    ofs<<"posq(q_w)"<<","<<std::endl;
    ofs<<"posq(F_x)"<<","<<std::endl;
    ofs<<"posq(F_y)"<<","<<std::endl;
    ofs<<"posq(F_z)"<<","<<std::endl;
    ofs<<"posq(M_x)"<<","<<std::endl;
    ofs<<"posq(M_y)"<<","<<std::endl;
    ofs<<"posq(M_z)"<<","<<std::endl;
    while(1){
        ks.getforce(force);
        ks.getq(posq);
        ks.geterror(err,servooffreaseon);
        switch (servooffreaseon){
        case 101:
            std::cout << "servo off : limit sensor. " << servooffreaseon << std::endl;
            break;
        case 102:
            std::cout << "servo off : control error is too large. " << servooffreaseon << std::endl;
            break;
        case 103:
            std::cout << "servo off : angle origin is unknowm. " << servooffreaseon << std::endl;
            break;
        case 104:
            std::cout << "servo off : motor driver is strange. "  << servooffreaseon << std::endl;
            break;
        case 105:
            std::cout << "servo off : encoder module is strange. " << servooffreaseon << std::endl;
            break;
        case 106:
            std::cout << "servo off : emergency stop button is ON. " << servooffreaseon << std::endl;
            break;
        default:
            break;
        }
        switch (err){
        case 1:
            std::cout << "err : not initialized. " << err << std::endl;
            break;
        case 2:
            std::cout << "err : share memory is unallocated. " << err << std::endl;
            break;
        case 3:
            std::cout << "err : cannot open module. " << err << std::endl;
            break;
        case 4:
            std::cout << "err : cannot open initial file. " << err << std::endl;
            break;
        case 5:
            std::cout << "err : argument error(argument is out of range). " << err << std::endl;
            break;
        case 6:
            std::cout << "err : argument error(argument is NUN). " << err << std::endl;
            break;
        case 7:
            std::cout << "err : mode error. " << err << std::endl;
            break;
        case 8:
            std::cout << "err : FIFO error. " << err << std::endl;
            break;
        case 9:
            std::cout << "err : in working. " << err << std::endl;
            break;
        default:
            break;
        }
        std::cout << "posq(rail,x,y,z,q_x,q_y,q_z,q_w) :\t" << std::flush;
        showvec(posq);
        std::cout << "force(F_x,F_y,F_z,M_x,M_y,M_z) :\t" << std::flush;
        showvec(force);
        sleep(1);
	ofs<<posq[0]<<std::endl;
    ofs<<posq[1]<<std::endl;
    ofs<<posq[2]<<std::endl;
    ofs<<posq[3]<<std::endl;
    ofs<<posq[4]<<std::endl;
    ofs<<posq[5]<<std::endl;
    ofs<<posq[6]<<std::endl;
    ofs<<posq[7]<<std::endl;
    //    ofs<<force<<std::endl;
        if(kb.getkey()=='q'){break;}
    }
}
