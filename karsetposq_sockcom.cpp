#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <Eigen/Geometry>
#include <Eigen/StdVector>
#include <vector>

#include "mymath.h"
#include "sequence.h"
#include "socketcom.h"

#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)

void samle_func(Sockcom *so){
  std::string st;
  char moji[1024];
  double data[50];
  st = ":io\n";
  //std::cout << "1" << std::endl;
  so->sendd(st,0);
  //std::cout << "2" << std::endl;
  so->recvv(&moji,0);
  /*int i=0;
  for(i=0;i<50;i++){
    so->recvv(&data[i],0);
    std::cout << data[i] << std::endl;
    //std::cout << "\n" << std::endl;
  }*/
  //std::cout << "3" << std::endl;
  std::cout << moji << std::endl;
  //std::cout << "4" << std::endl;
}

void samle_func2(Sockcom *so){
  std::string st;
  char moji[1024];
  std::cout << "1" << std::endl;
  so->recvv(&moji,0);
  std::cout << "2" << std::endl;
  std::cout << moji << std::endl;
  std::cout << "3" << std::endl;
}

int main(){
    KAROperator ks;
    VectorXd posq(8);//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 10.0;//移動時間
    posq << 0.8,0.4,0.1,0.33,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    ks.setq(time,posq);
}