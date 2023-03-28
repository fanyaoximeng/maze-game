
#include"guangbiao.h" 
#include"modeset.h"

void print_wall(int x,int y) //变为路线 
{	
	y=y-1;
	gotoxy(x,2*y);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
	printf("");
	
	gotoxy(x,2*y+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
	HideCursor(); 	
				                                         //没有很好的适配，为了方便操作，对道路用全黑汉字， 			 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 127);
	printf("墙");
					
}
