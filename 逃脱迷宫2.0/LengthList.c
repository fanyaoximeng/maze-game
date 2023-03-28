
#include"route.h" 


int LengthList(Node * head)
{
	int length = 1;
	Node * temp;
    temp = head;
	while (temp->next != NULL)
    {	
        temp = temp->next;
		length += 1;
		
	    if (temp->next == NULL)
	    {  
	        return length; 
	    }		
		    
	}
  	return length;  
}

