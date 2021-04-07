#include <REG52.H>
#include "./tube.h"

int ms=0;
void openTimer(){
    EA=1; // 开启总中断 
    EX0=1; // 开启外部中断0
    TMOD=0x01; // 设置定时器模式
    TH0=0;
    TR0=1; // 开始运行定时器
    TL0=0;
    ET0=1; // 开启定时/计数器（0)中断允许
    // ET1=1; // 开启定时/计数器（1)中断允许
    /**
     * 控制触发外部中断方式
     * 1、低电平触发：指的是保证逻辑门的输入为低电平时所允许的最大输入低电平
     * 2、下降沿触发：数字电平从高电平（数字“1”）变为低电平（数字“0”）的那一瞬间。
     * */
    IT0=1; // 外部中断0 下降沿 详情见文档
}
static void init(){
    TH0=24; // (2^16+1 - 1000)%256
    TH0=252;//(2^16+1 - 1000)/256
}
static void run(){
    // ms++;
    // if(ms && !(ms%2000)){
    //      openLed(1);
    // }
    // if(ms && !(ms%3000)){
    //      openLed(3);
    // }
    // if(ms && !(ms%5000)){
    //     openLed(5);
    // }


    // if(ms>10){
    //      openLed(7);
    // }
    // if(ms>20){
    //      openLed(6);
    // }
    // if(ms>30){
    //      openLed(5);
    // }
}
// 外部中断0
void interrupt0() interrupt 0{
    openLed(5);
}
// // 如使用c语言，中断查询次序号就是中断号，详情见文档
// void timer0() interrupt 1{
//     init();
// }

