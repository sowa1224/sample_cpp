#include <iostream>
#include <KAR/KARoperator.h>//順番に気をつけろ(opencvとか　よりうしろ)

class MyJoypad : public Joypadxy{//joystickが環境依存した場合に関数をオーバーライドする
    public:
        MyJoypad();
        MyJoypad(std::string fn);//デバイスファイル指定
        void joypadread();//オーバーライド
};

MyJoypad::MyJoypad() : Joypadxy(){}
MyJoypad::MyJoypad(std::string fn) : Joypadxy(fn){}

int main(){
    KAROperator ks;
#if 0
    //joystickの配置変更が不要な場合
    ks.joypadcontrol();
#else
    //joystickの配置変更が必要な場合
    std::string filename("/dev/input/js0");
    MyJoypad *joy = new MyJoypad(filename);
    ks.joypadcontrol(joy);
#endif
    ks.waittoexitq();//'q'キーを押すまで待機
}



void MyJoypad::joypadread(){
    int ret;
    int endflll = 0;
    struct js_event js;
    int old_jsnum = 0;
    VectorXd l_point;
    pthread_mutex_lock(&readtex);
    l_point = point;
    pthread_mutex_unlock(&readtex);
    while(1){
        //std::cout << "overrided=============================== " << std::endl;
        ret = read(fd, &js, sizeof(js));
        if ((fd>0)&&(ret != sizeof(js))){
            std::cout << "ba-ka!! size is not same" << std::endl;
        }
        if(0){//(int)js.number<23){
            std::cout << "jsnum : " << (int)js.number << " js value : "<< (double)js.value << std::endl;
        }

        //ここから下を書き換える
        switch ((int)js.number){
        case 0 :
            l_point(0) = cc*(double)js.value;
            break;
        case 1 :
            l_point(1) = cc*(double)js.value;
            break;
        case 3 :
            l_point(2) = cc*(double)js.value;
            break;
        case 4 :
            if(js.value==1){
                bottumflag[2] = 1;
            }else if(js.value==0){
                bottumflag[2] = 0;
                l_point(3) = 0;
            }else{
                l_point(3) = -cc*(double)js.value;
            }
            break;
        case 15 :
            if(js.value==1){
                bottumflag[0] = 1;
            }else{
                bottumflag[0] = 0;
            }
            break;
        case 16 :
            if(js.value==1){
                bottumflag[0] = 2;
            }else{
                bottumflag[0] = 0;
            }
            break;
            case 13 :
            if(js.value==1){
                bottumflag[1] = 2;
            }else{
                bottumflag[1] = 0;
            }
            break;
        case 14 :
            if(js.value==1){
                bottumflag[1] = 1;
            }else{
                bottumflag[1] = 0;
            }
            break;
        case 5 :
            if(js.value==1){
                bottumflag[2] = 2;
            }else{
                bottumflag[2] = 0;
            }
            break;
        default:
            if(std::abs((int)js.value)<10){
                bottumflag[0] = 0;
                bottumflag[1] = 0;
                bottumflag[2] = 0;
            }
            break;
        }
        if(bottumflag[0]==2){
            l_point(5) = cc*(double)(1000.0d);
        }else if(bottumflag[0]==1){
            l_point(5) = cc*(double)(-1000.0d);
        }else{
            l_point(5) = 0;
        }
        if(bottumflag[1]==2){
            l_point(4) = cc*(double)(1000.0d);
        }else if(bottumflag[1]==1){
            l_point(4) = cc*(double)(-1000.0d);
        }else{
            l_point(4) = 0;
        }
        if(bottumflag[2]==2){
            l_point(6) = cc*(double)(1000.0d);
        }else if(bottumflag[2]==1){
            l_point(6) = cc*(double)(-1000.0d);
        }else{
            l_point(6) = 0;
        }
        //ここから上を書き換える

        pthread_mutex_lock(&readtex);
        point = l_point;
        pthread_mutex_unlock(&readtex);
        if(endflll>40){break;}
    }
    pthread_mutex_lock(&breaktex);
    endflag = 1;
    pthread_mutex_unlock(&breaktex);
}