#include <iostream>             
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)


int main(){
    KAROperator ks;
    VectorXd posq(8);//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 3.0;//移動時間 
    double quick = 2.0;//作業時間
    posq<<0.371999 , 0.337392 , -0.00210042 , 0.206784 , 0.00462054 , 0.836841 , 0.547393 , -0.00598772;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.372858 , 0.337609 , -0.00210069 , 0.192047 , 0.00458126 , 0.836891 , 0.547318 , -0.00604982;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.372858 , 0.366396 , -0.00210468 , 0.182759 , 0.00416343 , 0.835946 , 0.548755 , -0.0067031;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.383337 , 0.379925 , -0.0021157 , 0.160363 , 0.0047123 , 0.835538 , 0.54938 , -0.00593203;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.38701 , 0.381415 , -0.00209734 , 0.153429 , 0.00466267 , 0.835531 , 0.549392 , -0.00589379;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.387035 , 0.400333 , -0.00209841 , 0.153396 , 0.00472904 , 0.83505 , 0.550123 , -0.00579589;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.387035 , 0.419941 , -0.00210113 , 0.153058 , 0.00426161 , 0.840247 , 0.542147 , -0.00657737;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.387033 , 0.440647 , -0.00205021 , 0.153323 , 0.00443789 , 0.853296 , 0.521372 , -0.00611209;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368969 , 0.440701 , -0.00205097 , 0.153311 , 0.00443918 , 0.853327 , 0.521322 , -0.00611524;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368382 , 0.44068 , -0.00204966 , 0.153301 , 0.0044204 , 0.853326 , 0.521323 , -0.00613745;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368349 , 0.440681 , -0.00204965 , 0.153305 , 0.004424 , 0.853325 , 0.521325 , -0.00613148;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368346 , 0.451876 , -0.00207339 , 0.166369 , 0.00417738 , 0.852642 , 0.522437 , -0.00668125;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368343 , 0.494805 , -0.00206285 , 0.215136 , 0.00447524 , 0.850346 , 0.526169 , -0.00610259;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368344 , 0.494834 , -0.00206223 , 0.215152 , 0.00445807 , 0.850347 , 0.526168 , -0.00612637;
    sleep(3);
    ks.setq(time,posq);    
    posq<<0.368344 , 0.494831 , -0.00206117 , 0.215172 , 0.00447277 , 0.850348 , 0.526167 , -0.00609574;
    sleep(3);
    ks.setq(time,posq);    

}