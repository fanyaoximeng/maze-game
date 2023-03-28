#include"guangbiao.h" 
#include"modeset.h"


void print_hunter(int x,int y)
{
	y=y-1; 
		
	gotoxy(x,2*y);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 
	HideCursor();
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 25);
	printf("");
	
	gotoxy(x,2*y+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 
	HideCursor();
	printf("捕");      
	
	

	//color(16); 
		
}
