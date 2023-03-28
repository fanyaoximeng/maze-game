

#include"route.h" 

Node *CreatNode(Node *head,int x,int y)
{
	int con;
	con = x*1000+y;
	
    head=(Node*)malloc(sizeof(Node));//创建链表第一个结点（首元结点�?
    
    if(head == NULL)
    {
        printf("malloc error!\r\n");
        return NULL;
    }
    
    head->pre=NULL;
    head->next=NULL;
    head->data=con;
    return head;
}
