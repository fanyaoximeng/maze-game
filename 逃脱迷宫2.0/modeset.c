
#include"modeset.h"

void modeset(int w,int h) //界面大小 ,给的数不用太大
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//获取标准输出的句柄，命令行的程序会把字符输出到屏幕上。
    COORD size = {w, h};//设置窗口的大小。
    SetConsoleScreenBufferSize(hOut,size);//重新设置缓冲区大小。
    SMALL_RECT rc = {0,0, w, h};//重置窗口位置和大小。
    SetConsoleWindowInfo(hOut ,1 ,&rc);//重置窗口大小
     
    //system("cls");//清理屏幕
    return;
}




