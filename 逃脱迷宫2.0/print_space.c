
#include"guangbiao.h" 
#include"modeset.h"

void print_space(int x,int y) //��Ϊ·�� 
{	
	y=y-1;
	gotoxy(x,2*y);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
	printf("");
	
	gotoxy(x,2*y+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
	HideCursor(); 	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 256);   //����ʵ����Եõ��������� ���ֺ���ĸ�ƶ�������
	
	printf("·");			                                         //û�кܺõ����䣬Ϊ�˷���������Ե�·��ȫ�ں��֣� 			 
	//color(16); 	
}
