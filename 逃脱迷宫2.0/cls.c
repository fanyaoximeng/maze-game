#include"main.h"

void cls()
{
	int i;
    COORD coor={0,0};    //这是Windows API的结构体，用来存储光标位置
    for(i=0; i < 25; i++)//这里是假设你要清空二十五行命令行输出，你可以自己改
    {
      coor.x=i ;                             
      coor.y=0 ;             
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
             //这三行代码将光标位置设为每一行的开头
      printf("                         ");  //打印25个空格，覆盖之前的输出，这里也可以改
    }
}
