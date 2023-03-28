
#ifndef STRU_H      //���STRU_H������ȡ�ģ���������������岢�Ҳ��������ظ�
#define STRU_H

#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include"maze.h"

#define STEPTIME  0.2  //���ֵ���ʱ���� 

#define HUNTERTIME  5   //���ֿ�ʼ�ƶ���ʱ��

/*�ڵ�ṹ*/
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

void print_bushou(clock_t start,float *p_stop_temp1,  Node * head,   int *p_step_num  ) ;//��ʾʱ�亯�����������0.1�Ż�ˢ�£�������˸ 

#endif


