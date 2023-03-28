
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NN 32		//迷宫区域大小,最外层是保护区
#define WALL 0		//表示该位置是墙 wall
#define ROUTE 1		//表示该位置是路 route



void InitMaze(int(*maze)[NN]);
void CreatMaze(int(*maze)[NN], int x, int y);
void print(int(*maze)[NN]);
void CreatInAndOut(int(*maze)[NN], int*in, int*out);


 
 



