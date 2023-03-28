
#include"route.h" 


int FindList(Node * head,int n)
{
	int i;
	
	int data;
	
	Node * temp;
	Node * body=(Node*)malloc(sizeof(Node));
    temp = head;
	for(i=1;i<n;i++)
	{
		temp = temp->next; 	
	}	
	data=temp->data;
        
    return data; 
	  

}

