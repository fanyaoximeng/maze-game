/************************************ 
**	���� ���Թ�С��Ϸ 
**	���� ����˧˧
**	���� ��shuaishuaiwang111@gmail.com 
**	ʱ�� ��2023��3��22�� 
************************************/ 
#include"maze.h"       // �Թ�����ͷ�ļ� 
#include"modeset.h"    // ��������ͷ�ļ� 
#include"main.h"
#include"guangbiao.h"  //���ͷ�ļ� 
#include"route.h"      //���� 

int main()
{	
	clock_t start;        //ʱ�俪ʼ���� 
	int sign_skill=1;	  //�����ͷű�־λ 
	
	/*---------------------------------------------------------------------------*/
	float stop_temp = 0;  //��������ˢ�������˸���޶�ʱ��ˢ�¼�� ��
	float *p_stop_temp = &stop_temp;  //ָ����� 
	
	 
	float stop_temp1 = 0;   //�����˶�������� 
	float *p_stop_temp1 = &stop_temp1; 
	
	int step_num = 1;      //�����ƶ����� 
	int *p_step_num = &step_num;  
	/*------------------------------------------------------------------------------*/ 
	
	int sign_time=1;      //ʱ���־λ����Ϸ������ʱֹͣ 
	int maze[NN][NN];     //��ӵ��±��ʾ�Թ��߽�ǽ��
	int in = 0;
	int out = 0;
	int *inp = &in;       //��ָ��ָ���Թ����λ��
	int *outp = &out;     //��ָ��ָ���Թ�����λ��
	
	int location[3][2]={0};   //��� ������λ�á�������ڣ�ͬʱҲ�����λ�á���������λ�á� 
	int (*p)[2]=NULL;  //��ά����ָ�� 
	
	
	p=location;
	srand(time(NULL));
	InitMaze(maze);                  //��ʼ���Թ������Թ������߽�ǽ 
	CreatMaze(maze, 14, 14);         //��maze[14][14]��λ�ÿ�ʼ�����Թ�
	CreatInAndOut(maze, inp, outp);  //��������Թ�����������,�������������ָ�����	
	/*------------------    ��ϰһ��ָ�������ֵ  ------*/
	*(*(p)+1)=0;     //�� 	
	*(*(p))=in;      //�� //׷��λ�� 
	*(*(p+1)+1)=1;
	*(*(p+1))=in;    //���λ�ã����λ�� 
	*(*(p+2)+1)=31;  //�� 
	*(*(p+2))=out;   //��   //����λ�� 	
	
	maze[location[1][0]][location[1][1]] = 2; //��ʼ�����λ�� 
	maze[location[0][0]][location[0][1]] = 3; //��ʼ�� ����λ�� 
	
	/*-----------------------------------------------------------------------------------------*/
	Node * head=NULL;                                                                           //����˫����
	head = CreatNode(head,location[1][0],location[1][1]);  //��ʼ���������λ�� 
    Node * list = head;
    
	/*-----------------------------------------------------------------------------------------*/
	
	print_main(maze);   //��ʾ�Թ� 
	modeset(110,34);	    //��ʾ�������� 	
	
	/**************************************************************/ 
	int i;
	gotoxy(5,33*2-1);
	printf("�㽫��%d��ʱ����й۲죬����ʱ      ",TIME); 
	gotoxy(8,33*2-1);
	printf("��Ϸ��ʱ��    "); 
	for(i=0;i<=TIME;i++)
	{
		gotoxy(5,2*48);    	
		printf("    ");      //����ԭ���ļ���
		gotoxy(5,2*48+1);   //�������y������ƶ��ǰ���char 1�ֽ� �ƶ� ���Ը�������������ܸ�����Ӧ������ 	
		HideCursor(); 	
		printf("%d",TIME-i); 
		sleep(1);
	} 	
	
	start = clock();//��ʼ��ʱ              �޶������̲�ѯ 
	/**************************************************************/ 
	while (1)
    {
    	/***********��Ϸ��ʱ��ʾ*********/ 	
    	print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 
		
    	gotoxy(-1,-1);     //������Ӱ��    
		HideCursor(); 
		
		
		/**�����������**/ 
		if( (GetKeyState(38 )<0) ||(GetKeyState('W')<0) ||(GetKeyState('w')<0))  //�� 
		{ 
			print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 	
			if(maze[location[1][0]-1][location[1][1]] == 1)    
			{
				maze[ location[1][0] ][ location[1][1] ] = 1;    //�ͷ���ҵ�ǰλ��Ϊ��· 1 
				print_space(location[1][0],location[1][1]);      //�ͷſռ�   ��ʹ��system("cls"); ���⿨��							
				location[1][0]= location[1][0] - 1;              //���λ�ø��� 	
				print_player( location[1][0] , location[1][1] ); //����ƶ���Ŀǰ���λ�� //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2;            //�������λ�� 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //ɾ���ظ�·�� 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				
				
					
				Sleep(200);			//��ֹ����û��̧��ʱ��������						
			}  
		}	
		 
		if( (GetKeyState(40 )<0) ||(GetKeyState('S')<0) ||(GetKeyState('s')<0)) //�� 
		{ 
			print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 
		    if(maze[location[1][0]+1][location[1][1]] == 1)  
			{					
				maze[ location[1][0] ][ location[1][1] ] = 1; //�ͷ���ҵ�ǰλ��Ϊ��· 1 
				print_space(location[1][0],location[1][1]);   //�ͷſռ�   ��ʹ��system("cls"); ���⿨��							
				location[1][0]= location[1][0] + 1;             // ���λ�ø��� 	
				print_player( location[1][0] , location[1][1] );   //����ƶ���Ŀǰ���λ�� //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2; //�������λ�� 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //ɾ���ظ�·�� 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				Sleep(200);											
			} 
		} 
					
		if( (GetKeyState(37 )<0) ||(GetKeyState('A')<0) ||(GetKeyState('a')<0))	    //�� 
		{ 
			print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 
		    if(maze[location[1][0]][location[1][1]-1] == 1)
			{	
				maze[ location[1][0] ][ location[1][1] ] = 1; //�ͷ���ҵ�ǰλ��Ϊ��· 1 
				print_space(location[1][0],location[1][1]);   //�ͷſռ�   ��ʹ��system("cls"); ���⿨��							
				location[1][1]= location[1][1] - 1;             // ���λ�ø��� 	
				print_player( location[1][0] , location[1][1] );   //����ƶ���Ŀǰ���λ�� //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2; //�������λ�� 
				
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //ɾ���ظ�·�� 
				list=CreatList( list , location[1][0]  , location[1][1]);	
				Sleep(200);												
			}   
		}		  
			
		if( (GetKeyState(39 )<0) ||(GetKeyState('D')<0) ||(GetKeyState('d')<0))   //�� 
		{
		    print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 			    	
			if(maze[ location[1][0] ][ location[1][1] + 1] == 1)
			{										
				maze[ location[1][0] ][ location[1][1] ] = 1;    //�ͷ���ҵ�ǰλ��Ϊ��· 1 
				print_space(location[1][0],location[1][1]);      //�ͷſռ�   ��ʹ��system("cls"); ���⿨��												
				location[1][1]= location[1][1]+1;                //���λ�ø��� 						
				print_player( location[1][0] , location[1][1] ); //����ƶ���Ŀǰ���λ�� //						
				maze[ location[1][0] ][ location[1][1] ] = 2;    //�������λ�� 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //ɾ���ظ�·�� 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				/*-------------------------------------------------------------------------------------*/ //  
			//	print_bushou(start,p_stop_temp1,  head , p_step_num );   //sign_buhuo �Ƿ񲶻��־λ 
			//	print_bushou(start,p_stop_temp1,  head, p_step_num  ); //��ʾʱ�亯�����������0.1�Ż�ˢ�£�������˸ 
			//	if() //�ж��Ƿ񲶻� 
			//	{
			//		(location[0][0]-location[1][0])*(location[0][0]-location[1][0])+(location[0][1]-location[1][1])*(location[0][1]-location[1][1])<1.5
				
			//	} 
				
				/*----------------------------------------------------------------------------------------------*/
				Sleep(200);															
			} 	    
		}
		
		
		print_time(start , p_stop_temp,sign_time);	//��ʾ��Ϸʱ�� 	
		/*---------------------------------------------------------------------------------------*/
	
		print_bushou(start,p_stop_temp1,  head, p_step_num  ); //��ʾʱ�亯�����������0.1�Ż�ˢ�£�������˸ 
		
		
		if(*p_step_num==2&&LengthList(head)==1) 
			goto P;
		/*--------*/   //����������������ʵ��������·�߹滮����Ҫ������ƣ�����ȫͼ·�߹滮�㷨 ���Ժ����� 
		
//		if(location[1][0]>=2&&location[1][0]<=NN-3&&location[1][1]>=2&&location[1][1]<=NN-3) //��ͼ����Ż�ִ�� 
//		{
//				
//			if(sign_skill==1)   //�����ͷ� 
//			{			  
//			  	if( (GetKeyState('P' )<0) ||(GetKeyState('p')<0) )
//			  	{	
//					sign_skill=0;	//�޶�����ֻ��һ�� 
//					
//					/********ըǽ����*****�����������Χ��ǽ������*****/ 		
//					game_skill_p(location[1][0],location[1][1],maze);
//												
//				//	Sleep(200);	
//				//	gotoxy(35,-1);
//				//	printf("�����Ѿ��ͷţ�"); 															
//				} 		    
//			}			
//		}	

		if(step_num>2) 
		{
			if ( LengthList(head)-step_num ==-1 	 )   // 
			{
P:				//system("cls");
		    	gotoxy(12,2*39); 
		    	color(16);
		    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		    	printf("�㱻ץ����");
		    	while(1);
			
			}		
			
		}
		
		                
	    if(location[1][1]==NN-1)   //�����ǽ�ķ�Χ���ж��ɹ� 
	    {
	    	sign_time = 0;
	    	
	    	//system("cls");
	    	gotoxy(12,2*39); 
	    	color(16);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	    	printf("��ϲ�ɹ����أ�");
	    	while(1);
		}   
//		//�������		
//		gotoxy(35,-1);     //������Ӱ��   
//		printf("                                                                       "); 
//		gotoxy(35,-1);     //������Ӱ�� 
//		HideCursor(); 
//		PrintList( head ) ;   
	
    }
    
    return 0;
}

