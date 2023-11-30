#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)//  ijijoijoijiojij

int main(){
    KAROperator ks;
    int err;//エラー
    int servooffreaseon;//サーボオフになった原因
    keyboard kb;//キーボード
    VectorXd force;//力センサ
    VectorXd posq;//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    int i;
    for(i=0;i<2;i++){
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
    }

    double time = 5.0;//移動時間
    /*VectorXd lenghs(8);//移動距離
    lenghs << 0.01,0.0,0.0,0.0,0,0,0,0;*/
    posq(0)=posq(0)+0.01;
    showvec(posq);
    ks.setq(time,posq);
}