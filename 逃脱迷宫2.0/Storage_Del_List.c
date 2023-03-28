
#include"route.h" 

/*head为原双链表，elem表示被查找元素*/


Node* Storage_Del_List(Node * head,int x,int y, int *p_step_num)
{
	int val;
	
	int step=*p_step_num;//捕手已经走的步数 
	
	val = x*1000+y;
	Node * temp;
	Node * body=(Node*)malloc(sizeof(Node));
    temp = head;
    
    int len=1;
    
    while (temp->next != NULL)
    {
    	
    	
        temp = temp->next; 
        
		len = LengthList(head);
		
//		//测试 
//		//system("cls");
//    	gotoxy(40,18); 
//    	color(16);
//    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    	printf("%d    %d",step,len);
		
		
		//  数据与前面的相同且                           
	    if (temp->data == val && step < len )  //如果数据相同，且捕手的步长小于了玩家 
	    {
	    	temp->next = NULL;
	        //printf("删除后面的\n");
	        return head; 
		}
		
	
	
	    if (temp->next == NULL)
	    {
	       // printf("没有相同的数，结束\n");
	        //没有相同的就在末尾插入新节点 
	      //==================================================
			Node * body=(Node*)malloc(sizeof(Node));
		    body->pre=NULL;
		    body->next=NULL;
		    body->data = val;
			/*直接前趋结点的next指针指向新结点*/
		    temp->next=body;
		    /*新结点指向直接前趋结点*/
		    body->pre=temp;

		  //================================================== 
	        
	        return head; 
	    }    		
		    
	}
  	return head;
}

