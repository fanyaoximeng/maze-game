
#include"route.h" 

Node* CreatList(Node * list ,int x ,int y)
{
	int con;
	con = x*1000+y;
	
    Node * body=(Node*)malloc(sizeof(Node));
    body->pre=NULL;
    body->next=NULL;
    body->data = con;
	/*直接前趋结点的next指针指向新结点*/
    list->next=body;
    /*新结点指向直接前趋结点*/
    body->pre=list;
    /*把body指针给list返回*/
    list=list->next;
        
    return list;
}

