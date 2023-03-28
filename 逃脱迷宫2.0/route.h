
#ifndef STRU_H      //这个STRU_H是随意取的，但是最好是有意义并且不与其他重复
#define STRU_H

#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"maze.h"

#define STEPTIME  0.2  //捕手单步时间间隔 

#define HUNTERTIME  5   //捕手开始移动的时间

/*节点结构*/
typedef struct Node
{
    struct Node *pre;
    int data;
    struct Node *next;
}Node;

Node* CreatList(Node * list ,int ,int);

Node *CreatNode(Node *head,int  ,int);

Node*  Storage_Del_List(Node * head,int  ,int, int *p_step_num);

Node * InsertListEnd(Node * head,int add,int data);

Node * InsertListHead(Node * head,int add,int data);

Node *ModifyList(Node * p,int add,int newElem);

void PrintList(Node * head);

int FindList(Node * head,int);

int LengthList(Node * head);

void print_bushou(clock_t start,float *p_stop_temp1,  Node * head,   int *p_step_num  ) ;//显示时间函数，间隔超过0.1才会刷新，避免闪烁 

#endif


