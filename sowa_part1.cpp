#include <iostream>             
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)


int main(){
    KAROperator ks;
    VectorXd posq(8);//手先姿勢位置(rail,x,y,z,q_x,q_y,q_z,q_w)
    double time = 3.0;//移動時間 
    double quick = 2.0;//作業時間
    posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.42193 , -0.00172288 , 0.14043 , 0.00692427 , 0.460672 , 0.887539 , -0.00300866;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421956 , -0.0018446 , 0.140428 , 0.00687968 , 0.502184 , 0.864727 , -0.00326031;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421914 , -0.00192895 , 0.14043 , 0.00664415 , 0.532584 , 0.846344 , -0.00357125;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421948 , -0.00200655 , 0.140432 , 0.006593 , 0.56367 , 0.825965 , -0.00376374;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.393062 , -0.00198458 , 0.14052 , 0.00754708 , 0.556757 , 0.830635 , -0.00306799;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360385 , -0.00195728 , 0.14041 , 0.00663055 , 0.543295 , 0.839507 , -0.00363912;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360389 , -0.00195721 , 0.140422 , 0.0066436 , 0.543288 , 0.839512 , -0.00363043;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360388 , -0.00195643 , 0.140432 , 0.00665636 , 0.543294 , 0.839509 , -0.00361897;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324099 , 0.346971 , -0.00199253 , 0.164323 , 0.00780343 , 0.544645 , 0.838625 , -0.00301351;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322271 , 0.306138 , -0.00197498 , 0.209428 , 0.00661305 , 0.549336 , 0.835567 , -0.00369188;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322319 , 0.314722 , -0.00196538 , 0.209185 , 0.00607898 , 0.54846 , 0.836145 , -0.00400756;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.42929 , -0.00194995 , 0.209181 , 0.00656426 , 0.53952 , 0.841939 , -0.00367123;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.428509 , -0.00195035 , 0.209389 , 0.00677616 , 0.539585 , 0.841897 , -0.00353671;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.327931 , 0.428529 , -0.00194683 , 0.209304 , 0.00665939 , 0.539587 , 0.841896 , -0.00359732;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340192 , 0.428515 , -0.00194683 , 0.209308 , 0.00666204 , 0.539585 , 0.841897 , -0.00359559;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340145 , 0.428523 , -0.00194919 , 0.209314 , 0.0066741 , 0.53958 , 0.8419 , -0.00359745;
    sleep(3);
    ks.setq(time,posq);
        posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);

    posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.42193 , -0.00172288 , 0.14043 , 0.00692427 , 0.460672 , 0.887539 , -0.00300866;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421956 , -0.0018446 , 0.140428 , 0.00687968 , 0.502184 , 0.864727 , -0.00326031;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421914 , -0.00192895 , 0.14043 , 0.00664415 , 0.532584 , 0.846344 , -0.00357125;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421948 , -0.00200655 , 0.140432 , 0.006593 , 0.56367 , 0.825965 , -0.00376374;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.393062 , -0.00198458 , 0.14052 , 0.00754708 , 0.556757 , 0.830635 , -0.00306799;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360385 , -0.00195728 , 0.14041 , 0.00663055 , 0.543295 , 0.839507 , -0.00363912;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360389 , -0.00195721 , 0.140422 , 0.0066436 , 0.543288 , 0.839512 , -0.00363043;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360388 , -0.00195643 , 0.140432 , 0.00665636 , 0.543294 , 0.839509 , -0.00361897;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324099 , 0.346971 , -0.00199253 , 0.164323 , 0.00780343 , 0.544645 , 0.838625 , -0.00301351;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322271 , 0.306138 , -0.00197498 , 0.209428 , 0.00661305 , 0.549336 , 0.835567 , -0.00369188;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322319 , 0.314722 , -0.00196538 , 0.209185 , 0.00607898 , 0.54846 , 0.836145 , -0.00400756;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.42929 , -0.00194995 , 0.209181 , 0.00656426 , 0.53952 , 0.841939 , -0.00367123;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.428509 , -0.00195035 , 0.209389 , 0.00677616 , 0.539585 , 0.841897 , -0.00353671;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.327931 , 0.428529 , -0.00194683 , 0.209304 , 0.00665939 , 0.539587 , 0.841896 , -0.00359732;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340192 , 0.428515 , -0.00194683 , 0.209308 , 0.00666204 , 0.539585 , 0.841897 , -0.00359559;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340145 , 0.428523 , -0.00194919 , 0.209314 , 0.0066741 , 0.53958 , 0.8419 , -0.00359745;
    sleep(3);
    ks.setq(time,posq);
        posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);

    posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.42193 , -0.00172288 , 0.14043 , 0.00692427 , 0.460672 , 0.887539 , -0.00300866;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421956 , -0.0018446 , 0.140428 , 0.00687968 , 0.502184 , 0.864727 , -0.00326031;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421914 , -0.00192895 , 0.14043 , 0.00664415 , 0.532584 , 0.846344 , -0.00357125;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.421948 , -0.00200655 , 0.140432 , 0.006593 , 0.56367 , 0.825965 , -0.00376374;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.393062 , -0.00198458 , 0.14052 , 0.00754708 , 0.556757 , 0.830635 , -0.00306799;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360385 , -0.00195728 , 0.14041 , 0.00663055 , 0.543295 , 0.839507 , -0.00363912;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360389 , -0.00195721 , 0.140422 , 0.0066436 , 0.543288 , 0.839512 , -0.00363043;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324271 , 0.360388 , -0.00195643 , 0.140432 , 0.00665636 , 0.543294 , 0.839509 , -0.00361897;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.324099 , 0.346971 , -0.00199253 , 0.164323 , 0.00780343 , 0.544645 , 0.838625 , -0.00301351;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322271 , 0.306138 , -0.00197498 , 0.209428 , 0.00661305 , 0.549336 , 0.835567 , -0.00369188;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.322319 , 0.314722 , -0.00196538 , 0.209185 , 0.00607898 , 0.54846 , 0.836145 , -0.00400756;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.42929 , -0.00194995 , 0.209181 , 0.00656426 , 0.53952 , 0.841939 , -0.00367123;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.32231 , 0.428509 , -0.00195035 , 0.209389 , 0.00677616 , 0.539585 , 0.841897 , -0.00353671;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.327931 , 0.428529 , -0.00194683 , 0.209304 , 0.00665939 , 0.539587 , 0.841896 , -0.00359732;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340192 , 0.428515 , -0.00194683 , 0.209308 , 0.00666204 , 0.539585 , 0.841897 , -0.00359559;
    sleep(3);
    ks.setq(time,posq);
    posq<<0.340145 , 0.428523 , -0.00194919 , 0.209314 , 0.0066741 , 0.53958 , 0.8419 , -0.00359745;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421936 , -0.00153157 , 0.140449 , 0.00713437 , 0.404084 , 0.91469 , -0.00254354;
    sleep(3);
    ks.setq(time,posq);
    
    posq<<0.324271 , 0.421931 , -0.00164159 , 0.140435 , 0.00702271 , 0.436067 , 0.899883 , -0.00280177;
    sleep(3);
    ks.setq(time,posq);
    


