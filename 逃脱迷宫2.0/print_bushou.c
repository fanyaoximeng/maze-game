
#include"route.h" 
//                    ��ʼʱ��         ���               �켣����         ��n�� 
void print_bushou(clock_t start,float *p_stop_temp1,  Node * head,   int *p_step_num  ) //��ʾʱ�亯�����������0.1�Ż�ˢ�£�������˸ 
{	
	float duration;
	float t;
	clock_t stop = clock();    //Ŀǰʱ��
	int i=*p_step_num ;
	int temp,x,y;
	t =	((float)stop)/CLK_TCK;
	duration = ((float)(stop-start))/CLK_TCK;
	
	if( t - *p_stop_temp1 > STEPTIME )   //����0.3�벶���ƶ�һλ 
	{	
		
		if( duration > HUNTERTIME ) //��ʼ�ƶ���ʱ�� 
		{
			/*-------------------------------------------------------------*/ 
			if(*p_step_num ==1) 
			{
				temp=FindList(head, i);
				x=temp/1000;
				y=temp%1000-1;
				print_space( x,y) ;	
			}
			
			if(*p_step_num ==2) 
			{
			
				temp=FindList(head, i);
				x=temp/1000;
				y=temp%1000;
				print_hunter( x,y);
				print_wall( x, y-1);
				
			}
			else
			{
				temp=FindList(head, i-1);
				x=temp/1000;
				y=temp%1000;
				print_space( x,y);
				
				temp=FindList(head, i);
				x=temp/1000;
				y=temp%1000;
				print_hunter( x,y);	
						
			}
		
			*p_stop_temp1=t;   
			*p_step_num =*p_step_num +1; //������1 
		}
	}
			
}

