
#include"maze.h"
#include"modeset.h"

//��ӡ�Թ�
void print(int(*maze)[NN])
{
	int i,j;
	for (i = 0; i < NN; i++)
	{
		for (j = 0; j < NN; j++)
		{
			if (*(*(maze + i) + j) == ROUTE)
			{
				
				color(16); 
				printf("  ");		
			}
			else 
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 127);
				printf("ǽ");
				color(16); 
				
			}
		}
		printf("\n");
	}
	printf("\n");
}

