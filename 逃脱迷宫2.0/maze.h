
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NN 32		//�Թ������С,������Ǳ�����
#define WALL 0		//��ʾ��λ����ǽ wall
#define ROUTE 1		//��ʾ��λ����· route



void InitMaze(int(*maze)[NN]);
void CreatMaze(int(*maze)[NN], int x, int y);
void print(int(*maze)[NN]);
void CreatInAndOut(int(*maze)[NN], int*in, int*out);


 
 



