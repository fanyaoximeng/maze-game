
#include"route.h" 

/*headΪԭ˫����elem��ʾ������Ԫ��*/


Node* Storage_Del_List(Node * head,int x,int y, int *p_step_num)
{
	int val;
	
	int step=*p_step_num;//�����Ѿ��ߵĲ��� 
	
	val = x*1000+y;
	Node * temp;
	Node * body=(Node*)malloc(sizeof(Node));
    temp = head;
    
    int len=1;
    
    while (temp->next != NULL)
    {
    	
    	
        temp = temp->next; 
        
		len = LengthList(head);
		
//		//���� 
//		//system("cls");
//    	gotoxy(40,18); 
//    	color(16);
//    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//    	printf("%d    %d",step,len);
		
		
		//  ������ǰ�����ͬ��                           
	    if (temp->data == val && step < len )  //���������ͬ���Ҳ��ֵĲ���С������� 
	    {
	    	temp->next = NULL;
	        //printf("ɾ�������\n");
	        return head; 
		}
		
	
	
	    if (temp->next == NULL)
	    {
	       // printf("û����ͬ����������\n");
	        //û����ͬ�ľ���ĩβ�����½ڵ� 
	      //==================================================
			Node * body=(Node*)malloc(sizeof(Node));
		    body->pre=NULL;
		    body->next=NULL;
		    body->data = val;
			/*ֱ��ǰ������nextָ��ָ���½��*/
		    temp->next=body;
		    /*�½��ָ��ֱ��ǰ�����*/
		    body->pre=temp;

		  //================================================== 
	        
	        return head; 
	    }    		
		    
	}
  	return head;
}

