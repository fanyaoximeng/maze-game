
#include"maze.h"
#include"modeset.h"

//¥Ú”°√‘π¨
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
				printf("«Ω");
				color(16); 
				
			}
		}
		printf("\n");
	}
	printf("\n");
}

