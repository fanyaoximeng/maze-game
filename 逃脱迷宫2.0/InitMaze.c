 
 
#include"maze.h"
//��ʼ���Թ�
void InitMaze(int(*maze)[NN])
{
	int i ,j; 
	//����ǽ��
	for ( i = 0; i < NN; i++)
	{
		for (j = 0; j < NN; j++)
		{
			*(*(maze + i) + j) = WALL;
		}
	}
	
	//�Թ���Χ��������ֹ�ڴ�
	for (i = 0; i < NN; i++)
	{
		*(*(maze)+i) = ROUTE;
		*(*(maze + NN - 1) + i) = ROUTE;
		*(*(maze + i)) = ROUTE;
		*(*(maze + i) + NN - 1) = ROUTE;
	}
//		//���� 
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
