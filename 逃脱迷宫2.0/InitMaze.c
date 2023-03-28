 
 
#include"maze.h"
//初始化迷宫
void InitMaze(int(*maze)[NN])
{
	int i ,j; 
	//生成墙体
	for ( i = 0; i < NN; i++)
	{
		for (j = 0; j < NN; j++)
		{
			*(*(maze + i) + j) = WALL;
		}
	}
	
	//迷宫外围保护，防止挖穿
	for (i = 0; i < NN; i++)
	{
		*(*(maze)+i) = ROUTE;
		*(*(maze + NN - 1) + i) = ROUTE;
		*(*(maze + i)) = ROUTE;
		*(*(maze + i) + NN - 1) = ROUTE;
	}
//		//测试 
//	for ( i = 0; i < NN; i++)
//	{
//		for (j = 0; j < NN; j++)
//		{
//			printf("%d",maze[i][j] );
//			//printf("%d",j );
//		}
//		printf("\n");
//	}
//	while(1);
 
}
