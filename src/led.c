#include <REG52.H>
#include <INTRINS.H>
#include "./utils.h"
void startLed(){
    unsigned char tmp = 0x7f;
    while(1){
        tmp=_crol_(tmp,1);
        P2=tmp;
        sleep(2);
        // P2=0xff;
        // sleep(2);
    }
}