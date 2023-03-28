
#include"route.h" 

/*输出链表的功能函数*/
void PrintList(Node * head)
{
    Node * temp=head;
    while (temp) 
    {
        /*如果该节点无后继节点，说明此节点是链表的最后一个节点*/
        if (temp->next==NULL) 
        {
            printf("%d\n",temp->data);
        }
        else
        {
            printf("%d->",temp->data);
        }
        temp=temp->next;
    }
}


