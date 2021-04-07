#include <REG52.H>
#include "./utils.h"
#include "./tube.h"
// 译码器输入端
sbit A0 = P2 ^ 2;
sbit A1 = P2 ^ 3;
sbit A2 = P2 ^ 4;
sbit K1 = P3 ^ 1;
// 数码管数字显示对应表
unsigned char table[] = {
    0x3f, //0
    0x06, //1
    0x5b, //2
    0x4f, //3
    0x66, //4
    0x6d, //5
    0x7d, //6
    0x07, //7
    0x7f, //8
    0x6f, //9
    0x77, //a
};

void loopSeqshow()
{
    // 数码管
    unsigned char loop = 1;
    openLed(1);
    while (loop)
    {
        P0 = table[loop - 1];
        sleep(2);
        loop++;
        if (!(loop - 11))
        {
            loop = 1;
        }
    }
}
void tubeShowSeq(unsigned char index){
    P0 = table[index];
}
void startTube()
{
    unsigned char loop = 1;
    openLed(1);
    while (loop)
    {
        while (!K1)
        {
           return;
        }
        openLed(loop);
        P0 = table[loop - 1];
        sleepMin(10); // 防抖？
        P0=0x00; // 消隐
        loop++;
        if (!(loop - 9))
        {
            loop = 1;
        }
    }
}
// 通过译码器控制led的开关/位选，打开第seq个数码管
void openLed(unsigned char seq)
{
    seq = 7 - (seq - 1);
    switch (seq)
    {
    case 0:
        A0 = 0;
        A1 = 0;
        A2 = 0;
        break;
    case 1:
        A0 = 1;
        A1 = 0;
        A2 = 0;
        break;
    case 2:
        A0 = 0;
        A1 = 1;
        A2 = 0;
        break;
    case 3:
        A0 = 1;
        A1 = 1;
        A2 = 0;
        break;
    case 4:
        A0 = 0;
        A1 = 0;
        A2 = 1;
        break;
    case 5:
        A0 = 1;
        A1 = 0;
        A2 = 1;
        break;
    case 6:
        A0 = 0;
        A1 = 1;
        A2 = 1;
        break;
    default:
        A0 = 1;
        A1 = 1;
        A2 = 1;
        break;
    }
}