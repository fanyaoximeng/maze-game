
#include"route.h" 

Node* CreatList(Node * list ,int x ,int y)
{
	int con;
	con = x*1000+y;
	
    Node * body=(Node*)malloc(sizeof(Node));
    body->pre=NULL;
    body->next=NULL;
    body->data = con;
	/*ֱ��ǰ������nextָ��ָ���½��*/
    list->next=body;
    /*�½��ָ��ֱ��ǰ�����*/
    body->pre=list;
    /*��bodyָ���list����*/
    list=list->next;
        
    return list;
}

