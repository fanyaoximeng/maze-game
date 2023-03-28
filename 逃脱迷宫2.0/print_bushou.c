
#include"route.h" 
//                    开始时间         间隔               轨迹链表         第n步 
void print_bushou(clock_t start,float *p_stop_temp1,  Node * head,   int *p_step_num  ) //显示时间函数，间隔超过0.1才会刷新，避免闪烁 
{	
	float duration;
	float t;
	clock_t stop = clock();    //目前时间
	int i=*p_step_num ;
	int temp,x,y;
	t =	((float)stop)/CLK_TCK;
	duration = ((float)(stop-start))/CLK_TCK;
	
	if( t - *p_stop_temp1 > STEPTIME )   //超过0.3秒捕手移动一位 
	{	
		
		if( duration > HUNTERTIME ) //开始移动的时间 
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
			*p_step_num =*p_step_num +1; //步长＋1 
		}
	}
			
}

