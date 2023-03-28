#include"maze.h"

#include"modeset.h"

//打印迷宫
void print_main( int(*maze)[NN] )
{
	int i,j;
	for (i = 0; i < NN; i++)
	{
		for (j = 0; j < NN; j++)
		{
			if (*(*(maze + i) + j) == ROUTE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);   //大量实验测试得到，光标针对 汉字和字母移动有区别，
				                                                                 //没有很好的适配，为了方便操作，对道路用全黑汉字， 
				printf("路");
				
				
			}
			else if(*(*(maze + i) + j) == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				printf("我");
					
			}
			else if(*(*(maze + i) + j) == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 25);
				printf("捕");
				
					
			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 127);
				printf("墙");
				color(16); 	
			}
					
		}
		printf("\n");
	}
	color(16); 	 //恢复颜色 
	
}

