#include <dos.h>
#include <windows.h>
#include<stdio.h>
#include <time.h>


#include"modeset.h"
#include"route.h" 
#include"maze.h"       // 迷宫生成头文件 
#include"guangbiao.h" 




#define TIME  10   //倒计时时间 




void menu_main();

void game_skill_p(int x,int y,int(*maze)[NN]);

void print_main( int(*maze)[NN] );

void print_time(clock_t start,float *,int);




