#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)


int main(){
    KAROperator ks;
    VectorXd posq(8);//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 10.0;//移動時間
    // posq << 0.8,0.4,0.1,0.33,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    posq << 0.27,0.54,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    
    ks.setq(time,posq);

    posq << 0.27,0.52,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    sleep(5);
    ks.setq(time,posq);
    posq << 0.27,0.52,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    sleep(5);
    
    ks.setq(time,posq);
    posq << 0.27,0.52,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    sleep(5);
    
    ks.setq(time,posq);
    posq << 0.27,0.52,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    
    sleep(5);
    
    ks.setq(time,posq);

    posq << 0.27,0.52,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    
    sleep(5);
    
    ks.setq(time,posq);
    
}



// 0.311037 , 0.542007 , -0.000644983 , 0.21664 , 0.00752422 , 0.182187 , 0.983235 , -0.000837038
// 0.31,0.54,0.0,0.22,0,0,1,0