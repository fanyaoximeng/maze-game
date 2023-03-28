#include"maze.h"
//随机生成迷宫的入口与出口,将结果赋予两个指针参数
void CreatInAndOut(int(*maze)[NN], int*in, int*out) 
{
	int a, b;
	int flag_a = 0;
	int flag_b = 0;   //墙是0 路是1 
	int temp1=1,temp2=1; //作为对入口出口初始化的标志 
	
	while (1)
	{
		if (flag_a + flag_b == 2) 
		{
			break;
		}
		//产生下标与迷宫最外层相符的随机数,可以排除下标为1和N-2的位置
		a = 2 + rand() % (NN - 4);//随机产生 2 -- N-3 之间的数
		b = 2 + rand() % (NN - 4);
		
		if(temp1==1)
		{
			//由于传入的是指针，故无需返回值
			if (*(*(maze + a) + 2) == ROUTE)
			{//若条件成立，则使指针in指向入口下标a
				*in = a;
				*(*(maze + a) + 1) = ROUTE;
				flag_a = 1;
				temp1=0;
			}	
		}
			
		if(temp2==1)
		{
			if (*(*(maze + b) + NN - 3) == ROUTE) 
			{//若条件成立，则使指针out指向入口下标b
				*out = b;
				*(*(maze + b) + NN - 2) = ROUTE;
				flag_b = 1;
				temp2=0;
			}
		}	
				
	}
}
