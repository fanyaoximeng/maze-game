
#include"maze.h"

//�����Թ�������洢�ڶ�ά����maze[N][N]��(��ע:�Թ��������㷨�ǲο�CSDN��ĳλ���е�,
//�Ұ����ӷ����� https://blog.csdn.net/jjwwwww/article/details/106586256)
void CreatMaze(int(*maze)[NN], int x, int y)
{
	int i;
	
	if (*(*(maze + x) + y) == WALL)
	{//����ó���ǽ�壬��ʼ�����Թ�
		//�ж��Թ��Ƿ���γɻ�
		if (*(*(maze + x + 1) + y) + *(*(maze + x - 1) + y) + *(*(maze + x) + y + 1) + *(*(maze + x) + y - 1) <= ROUTE) 
		{
			*(*(maze + x) + y) = ROUTE;//���óɹ�������λ������Ϊ:·
			int direction[4] = { 0, 1, 2, 3 };
			
			for ( i = 4; i > 0; --i)
			{//�ĸ�����Ҫ����
				int ret = rand() % i;//������� 0 -- i-1 �е���  (0,1,2,3)
				//��������ֹ�ظ�
				int tmp = direction[ret];
				direction[ret] = direction[i - 1];
				direction[i - 1] = tmp;
 
				//����ÿ��ѭ��i����仯���ʲ�������ظ����±�
				switch (direction[i - 1])
				{
					case 0:CreatMaze(maze, x - 1, y); break;//����������һλ
					case 1:CreatMaze(maze, x + 1, y); break;//����������һλ
					case 2:CreatMaze(maze, x, y - 1); break;//����������һλ
					case 3:CreatMaze(maze, x, y + 1); break;//����������һλ
					default:{printf("CreatMaze��������!"); return; }
				}
			}
		}
	}
	
	
}
