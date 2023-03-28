
#include"maze.h"

//创建迷宫，将其存储在二维数组maze[N][N]中(备注:迷宫创建的算法是参考CSDN上某位大佬的,
//我把链接放在这 https://blog.csdn.net/jjwwwww/article/details/106586256)
void CreatMaze(int(*maze)[NN], int x, int y)
{
	int i;
	
	if (*(*(maze + x) + y) == WALL)
	{//如果该出是墙体，则开始创建迷宫
		//判断迷宫是否会形成环
		if (*(*(maze + x + 1) + y) + *(*(maze + x - 1) + y) + *(*(maze + x) + y + 1) + *(*(maze + x) + y - 1) <= ROUTE) 
		{
			*(*(maze + x) + y) = ROUTE;//调用成功，将该位置设置为:路
			int direction[4] = { 0, 1, 2, 3 };
			
			for ( i = 4; i > 0; --i)
			{//四个方向都要尝试
				int ret = rand() % i;//随机生成 0 -- i-1 中的数  (0,1,2,3)
				//交换，防止重复
				int tmp = direction[ret];
				direction[ret] = direction[i - 1];
				direction[i - 1] = tmp;
 
				//由于每次循环i都会变化，故不会出现重复的下标
				switch (direction[i - 1])
				{
					case 0:CreatMaze(maze, x - 1, y); break;//数组标记上移一位
					case 1:CreatMaze(maze, x + 1, y); break;//数组标记下移一位
					case 2:CreatMaze(maze, x, y - 1); break;//数组标记左移一位
					case 3:CreatMaze(maze, x, y + 1); break;//数组标记右移一位
					default:{printf("CreatMaze函数出错!"); return; }
				}
			}
		}
	}
	
	
}
