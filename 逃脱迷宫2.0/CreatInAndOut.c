#include"maze.h"
//��������Թ�����������,�������������ָ�����
void CreatInAndOut(int(*maze)[NN], int*in, int*out) 
{
	int a, b;
	int flag_a = 0;
	int flag_b = 0;   //ǽ��0 ·��1 
	int temp1=1,temp2=1; //��Ϊ����ڳ��ڳ�ʼ���ı�־ 
	
	while (1)
	{
		if (flag_a + flag_b == 2) 
		{
			break;
		}
		//�����±����Թ����������������,�����ų��±�Ϊ1��N-2��λ��
		a = 2 + rand() % (NN - 4);//������� 2 -- N-3 ֮�����
		b = 2 + rand() % (NN - 4);
		
		if(temp1==1)
		{
			//���ڴ������ָ�룬�����践��ֵ
			if (*(*(maze + a) + 2) == ROUTE)
			{//��������������ʹָ��inָ������±�a
				*in = a;
				*(*(maze + a) + 1) = ROUTE;
				flag_a = 1;
				temp1=0;
			}	
		}
			
		if(temp2==1)
		{
			if (*(*(maze + b) + NN - 3) == ROUTE) 
			{//��������������ʹָ��outָ������±�b
				*out = b;
				*(*(maze + b) + NN - 2) = ROUTE;
				flag_b = 1;
				temp2=0;
			}
		}	
				
	}
}
