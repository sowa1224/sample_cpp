#include <iostream>             
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)


int main(){
    KAROperator ks;
    VectorXd posq(8);//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 3.0;//移動時間 
    double quick = 2.0;//作業時間
    posq<<0.447121,0.301415,-0.00660854,0.146622,0.0157076,0.686408,0.726869,-0.0160913;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.442854,0.277989,-0.00660812,0.146602,0.0155559,0.691528,0.721999,-0.0162317;
    sleep(3);
    ks.setq(time,posq);    
    
    posq<<0.44257,0.272326,-0.00668417,0.153745,0.0161621,0.693822,0.719787,-0.016007;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.439389,0.223993,-0.00658192,0.197907,0.0150765,0.713416,0.700382,-0.0166076;
    sleep(3);
    ks.setq(time,posq);    

    
    posq<<0.439425
,0.224395
,-0.00659356
,0.197714
,0.0150279
,0.713255,0.700544,-0.0167132;
    sleep(3);
    ks.setq(time,posq);


  
    posq<<
0.426409
,0.304364
,-0.0066189
,0.220262
,0.0159085
,0.678756
,0.734018
,-0.0159605;
    sleep(3);
    ks.setq(time,posq);    
    
    posq<<0.420993
,0.304205
,-0.00661001
,0.193238
,0.0159193
,0.678742
,0.734032
,-0.0159093;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<00.423648
,0.304027
,-0.00660778
,0.178669
,0.0159111
,0.678689
,0.734082
,-0.0159066;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.423736
,0.303971
,-0.00660585
,0.149962
,0.0158784
,0.678679
,0.73409
,-0.015928;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.473433
,0.303958
,-0.00654079
,0.149974
,0.0166841
,0.638462
,0.769325
,-0.0150722;
    sleep(3);
    ks.setq(time,posq); 


    posq<<0.467182
,0.291466
,-0.00606709
,0.152822
,0.018802
,0.531949
,0.846475
,-0.0125635;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.465373
,0.288474
,-0.00608503
,0.145135
,0.0185982
,0.531311
,0.846876
,-0.0127716;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.423736
,0.303971
,-0.00660585
,0.149962
,0.0158784
,0.678679
,0.73409
,-0.015928;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.473433
,0.303958
,-0.00654079
,0.149974
,0.0166841
,0.638462
,0.769325
,-0.0150722;
    sleep(3);
    ks.setq(time,posq);    


    posq<<0.465371
,0.273265
,-0.00608722
,0.139194
,0.0186244
,0.534392
,0.844936
,-0.0127254;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.455317
,0.273049
,-0.00608644
,0.139116
,0.0184947
,0.534424
,0.844917
,-0.0128038;
    sleep(3);
    ks.setq(time,posq);    



    posq<<0.450382
,0.260147
,-0.00627537
,0.153573
,0.0198237
,0.538067
,0.842573
,-0.0126734;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.434194
,0.229569
,-0.00614903
,0.188761
,0.0183354
,0.546028
,0.837465
,-0.0130196;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.43546
,0.22973
,-0.00617632
,0.215999
,0.0184902
,0.54604
,0.837454
,-0.0130294;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.43568
,0.229651
,-0.00615706
,0.220821
,0.0183288
,0.54599
,0.83749
,-0.0130569;
    sleep(3);
    ks.setq(time,posq);    

///////////////
    posq<<0.435666
,0.22983
,-0.00616913
,0.212504
,0.0183016
,0.545962
,0.837507
,-0.013124
;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.435657
,0.231233
,-0.00617848
,0.241812
,0.0183921
,0.545493
,0.837811
,-0.0131085;
    sleep(3);
    ks.setq(time,posq); 


    posq<<0.447121,0.301415,-0.00660854,0.146622,0.0157076,0.686408,0.726869,-0.0160913;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.442854,0.277989,-0.00660812,0.146602,0.0155559,0.691528,0.721999,-0.0162317;
    sleep(3);
    ks.setq(time,posq);    
    
    posq<<0.44257,0.272326,-0.00668417,0.153745,0.0161621,0.693822,0.719787,-0.016007;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.439389,0.223993,-0.00658192,0.197907,0.0150765,0.713416,0.700382,-0.0166076;
    sleep(3);
    ks.setq(time,posq);    

    
    posq<<0.439425
,0.224395
,-0.00659356
,0.197714
,0.0150279
,0.713255,0.700544,-0.0167132;
    sleep(3);
    ks.setq(time,posq);


  
    posq<<
0.426409
,0.304364
,-0.0066189
,0.220262
,0.0159085
,0.678756
,0.734018
,-0.0159605;
    sleep(3);
    ks.setq(time,posq);    
    
    posq<<0.420993
,0.304205
,-0.00661001
,0.193238
,0.0159193
,0.678742
,0.734032
,-0.0159093;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<00.423648
,0.304027
,-0.00660778
,0.178669
,0.0159111
,0.678689
,0.734082
,-0.0159066;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.423736
,0.303971
,-0.00660585
,0.149962
,0.0158784
,0.678679
,0.73409
,-0.015928;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.473433
,0.303958
,-0.00654079
,0.149974
,0.0166841
,0.638462
,0.769325
,-0.0150722;
    sleep(3);
    ks.setq(time,posq); 


    posq<<0.467182
,0.291466
,-0.00606709
,0.152822
,0.018802
,0.531949
,0.846475
,-0.0125635;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.465373
,0.288474
,-0.00608503
,0.145135
,0.0185982
,0.531311
,0.846876
,-0.0127716;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.423736
,0.303971
,-0.00660585
,0.149962
,0.0158784
,0.678679
,0.73409
,-0.015928;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.473433
,0.303958
,-0.00654079
,0.149974
,0.0166841
,0.638462
,0.769325
,-0.0150722;
    sleep(3);
    ks.setq(time,posq);    


    posq<<0.465371
,0.273265
,-0.00608722
,0.139194
,0.0186244
,0.534392
,0.844936
,-0.0127254;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.455317
,0.273049
,-0.00608644
,0.139116
,0.0184947
,0.534424
,0.844917
,-0.0128038;
    sleep(3);
    ks.setq(time,posq);    



    posq<<0.450382
,0.260147
,-0.00627537
,0.153573
,0.0198237
,0.538067
,0.842573
,-0.0126734;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.434194
,0.229569
,-0.00614903
,0.188761
,0.0183354
,0.546028
,0.837465
,-0.0130196;
    sleep(3);
    ks.setq(time,posq);    

    posq<<0.43546
,0.22973
,-0.00617632
,0.215999
,0.0184902
,0.54604
,0.837454
,-0.0130294;
    sleep(3);
    ks.setq(time,posq);    


  
    posq<<0.43568
,0.229651
,-0.00615706
,0.220821
,0.0183288
,0.54599
,0.83749
,-0.0130569;
    sleep(3);
    ks.setq(time,posq);    

///////////////
    posq<<0.435666
,0.22983
,-0.00616913
,0.212504
,0.0183016
,0.545962
,0.837507
,-0.013124
;
    sleep(3);
    ks.setq(time,posq);
  
    posq<<0.435657
,0.231233
,-0.00617848
,0.241812
,0.0183921
,0.545493
,0.837811
,-0.0131085;
    sleep(3);
    ks.setq(time,posq); 
    //この場所はちょうどピーラーがじゃがいもに触れた場所


  
    
    
  //  ks.setq(time,posq);
  //  posq << 0.26,0.54,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
  //  sleep(5);
    
  //  ks.setq(time,posq);
  //  posq << 0.26,0.54,0.0,0.22,0,0,1,0;//(rail,x,y,z,q_x,q_y,q_z,q_w)
    
  //  sleep(5);
    
  //  ks.setq(time,posq);
    
   //初期位置は　1番目X:0.29  2番めY:0.54 このY軸はレールの垂直方向に動く　与えが大きいほど内側に行く
   //            4番目Z:
    
}

// 0.311037 , 0.542007 , -0.000644983 , 0.21664 , 0.00752422 , 0.182187 , 0.983235 , -0.000837038
// 0.31,0.54,0.0,0.22,0,0,1,0