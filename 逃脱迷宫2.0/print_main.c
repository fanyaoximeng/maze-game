#include"maze.h"

#include"modeset.h"

//��ӡ�Թ�
void print_main( int(*maze)[NN] )
{
	int i,j;
	for (i = 0; i < NN; i++)
	{
		for (j = 0; j < NN; j++)
		{
			if (*(*(maze + i) + j) == ROUTE)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);   //����ʵ����Եõ��������� ���ֺ���ĸ�ƶ�������
				                                                                 //û�кܺõ����䣬Ϊ�˷���������Ե�·��ȫ�ں��֣� 
				printf("·");
				
				
			}
			else if(*(*(maze + i) + j) == 2)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
				printf("��");
					
			}
			else if(*(*(maze + i) + j) == 3)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 25);
				printf("��");
				
					
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
	color(16); 	 //�ָ���ɫ 
	
}

