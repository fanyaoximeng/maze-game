#include"main.h"

void cls()
{
	int i;
    COORD coor={0,0};    //����Windows API�Ľṹ�壬�����洢���λ��
    for(i=0; i < 25; i++)//�����Ǽ�����Ҫ��ն�ʮ���������������������Լ���
    {
      coor.x=i ;                             
      coor.y=0 ;             
      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coor);
             //�����д��뽫���λ����Ϊÿһ�еĿ�ͷ
      printf("                         ");  //��ӡ25���ո񣬸���֮ǰ�����������Ҳ���Ը�
    }
}
