#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencv よりあと)

int main(){
    KAROperator ks;
    sleep(3);
    ks.calib();
}