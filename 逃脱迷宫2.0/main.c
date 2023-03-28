/************************************ 
**	名称 ：迷宫小游戏 
**	作者 ：王帅帅
**	邮箱 ：shuaishuaiwang111@gmail.com 
**	时间 ：2023年3月22日 
************************************/ 
#include"maze.h"       // 迷宫生成头文件 
#include"modeset.h"    // 窗口设置头文件 
#include"main.h"
#include"guangbiao.h"  //光标头文件 
#include"route.h"      //链表 

int main()
{	
	clock_t start;        //时间开始参数 
	int sign_skill=1;	  //技能释放标志位 
	
	/*---------------------------------------------------------------------------*/
	float stop_temp = 0;  //避免过快的刷新造成闪烁，限定时间刷新间隔 。
	float *p_stop_temp = &stop_temp;  //指针操作 
	
	 
	float stop_temp1 = 0;   //捕手运动间隔参数 
	float *p_stop_temp1 = &stop_temp1; 
	
	int step_num = 1;      //捕手移动步数 
	int *p_step_num = &step_num;  
	/*------------------------------------------------------------------------------*/ 
	
	int sign_time=1;      //时间标志位，游戏结束计时停止 
	int maze[NN][NN];     //添加的下标表示迷宫边界墙体
	int in = 0;
	int out = 0;
	int *inp = &in;       //该指针指向迷宫入口位置
	int *outp = &out;     //该指针指向迷宫出口位置
	
	int location[3][2]={0};   //存放 【捕手位置】；【入口，同时也是玩家位置】；【出口位置】 
	int (*p)[2]=NULL;  //二维数组指针 
	
	
	p=location;
	srand(time(NULL));
	InitMaze(maze);                  //初始化迷宫，给迷宫建立边界墙 
	CreatMaze(maze, 14, 14);         //从maze[14][14]的位置开始创建迷宫
	CreatInAndOut(maze, inp, outp);  //随机生成迷宫的入口与出口,将结果赋予两个指针参数	
	/*------------------    练习一下指针操作赋值  ------*/
	*(*(p)+1)=0;     //行 	
	*(*(p))=in;      //列 //追捕位置 
	*(*(p+1)+1)=1;
	*(*(p+1))=in;    //入口位置，玩家位置 
	*(*(p+2)+1)=31;  //行 
	*(*(p+2))=out;   //列   //出口位置 	
	
	maze[location[1][0]][location[1][1]] = 2; //初始化玩家位置 
	maze[location[0][0]][location[0][1]] = 3; //初始化 捕手位置 
	
	/*-----------------------------------------------------------------------------------------*/
	Node * head=NULL;                                                                           //创建双链表
	head = CreatNode(head,location[1][0],location[1][1]);  //初始化链表玩家位置 
    Node * list = head;
    
	/*-----------------------------------------------------------------------------------------*/
	
	print_main(maze);   //显示迷宫 
	modeset(110,34);	    //显示区域限制 	
	
	/**************************************************************/ 
	int i;
	gotoxy(5,33*2-1);
	printf("你将有%d秒时间进行观察，倒计时      ",TIME); 
	gotoxy(8,33*2-1);
	printf("游戏计时：    "); 
	for(i=0;i<=TIME;i++)
	{
		gotoxy(5,2*48);    	
		printf("    ");      //覆盖原来的计数
		gotoxy(5,2*48+1);   //光标数组y坐标的移动是按照char 1字节 移动 所以覆盖两个坐标才能覆盖相应的文字 	
		HideCursor(); 	
		printf("%d",TIME-i); 
		sleep(1);
	} 	
	
	start = clock();//开始计时              无堵塞键盘查询 
	/**************************************************************/ 
	while (1)
    {
    	/***********游戏计时显示*********/ 	
    	print_time(start , p_stop_temp,sign_time);	//显示游戏时间 
		
    	gotoxy(-1,-1);     //避免光标影响    
		HideCursor(); 
		
		
		/**避免输入堵塞**/ 
		if( (GetKeyState(38 )<0) ||(GetKeyState('W')<0) ||(GetKeyState('w')<0))  //上 
		{ 
			print_time(start , p_stop_temp,sign_time);	//显示游戏时间 	
			if(maze[location[1][0]-1][location[1][1]] == 1)    
			{
				maze[ location[1][0] ][ location[1][1] ] = 1;    //释放玩家当前位置为道路 1 
				print_space(location[1][0],location[1][1]);      //释放空间   不使用system("cls"); 避免卡顿							
				location[1][0]= location[1][0] - 1;              //玩家位置更新 	
				print_player( location[1][0] , location[1][1] ); //光标移动到目前玩家位置 //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2;            //更新玩家位置 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //删除重复路线 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				
				
					
				Sleep(200);			//防止键盘没有抬起时继续运行						
			}  
		}	
		 
		if( (GetKeyState(40 )<0) ||(GetKeyState('S')<0) ||(GetKeyState('s')<0)) //下 
		{ 
			print_time(start , p_stop_temp,sign_time);	//显示游戏时间 
		    if(maze[location[1][0]+1][location[1][1]] == 1)  
			{					
				maze[ location[1][0] ][ location[1][1] ] = 1; //释放玩家当前位置为道路 1 
				print_space(location[1][0],location[1][1]);   //释放空间   不使用system("cls"); 避免卡顿							
				location[1][0]= location[1][0] + 1;             // 玩家位置更新 	
				print_player( location[1][0] , location[1][1] );   //光标移动到目前玩家位置 //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2; //更新玩家位置 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //删除重复路线 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				Sleep(200);											
			} 
		} 
					
		if( (GetKeyState(37 )<0) ||(GetKeyState('A')<0) ||(GetKeyState('a')<0))	    //左 
		{ 
			print_time(start , p_stop_temp,sign_time);	//显示游戏时间 
		    if(maze[location[1][0]][location[1][1]-1] == 1)
			{	
				maze[ location[1][0] ][ location[1][1] ] = 1; //释放玩家当前位置为道路 1 
				print_space(location[1][0],location[1][1]);   //释放空间   不使用system("cls"); 避免卡顿							
				location[1][1]= location[1][1] - 1;             // 玩家位置更新 	
				print_player( location[1][0] , location[1][1] );   //光标移动到目前玩家位置 //
				maze[ *(*(p+1)) ][ *(*(p+1)+1) ] = 2; //更新玩家位置 
				
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //删除重复路线 
				list=CreatList( list , location[1][0]  , location[1][1]);	
				Sleep(200);												
			}   
		}		  
			
		if( (GetKeyState(39 )<0) ||(GetKeyState('D')<0) ||(GetKeyState('d')<0))   //右 
		{
		    print_time(start , p_stop_temp,sign_time);	//显示游戏时间 			    	
			if(maze[ location[1][0] ][ location[1][1] + 1] == 1)
			{										
				maze[ location[1][0] ][ location[1][1] ] = 1;    //释放玩家当前位置为道路 1 
				print_space(location[1][0],location[1][1]);      //释放空间   不使用system("cls"); 避免卡顿												
				location[1][1]= location[1][1]+1;                //玩家位置更新 						
				print_player( location[1][0] , location[1][1] ); //光标移动到目前玩家位置 //						
				maze[ location[1][0] ][ location[1][1] ] = 2;    //更新玩家位置 
				
				head = Storage_Del_List( head, location[1][0]  , location[1][1],p_step_num);  //删除重复路线 
				list=CreatList( list , location[1][0]  , location[1][1]);
				
				/*-------------------------------------------------------------------------------------*/ //  
			//	print_bushou(start,p_stop_temp1,  head , p_step_num );   //sign_buhuo 是否捕获标志位 
			//	print_bushou(start,p_stop_temp1,  head, p_step_num  ); //显示时间函数，间隔超过0.1才会刷新，避免闪烁 
			//	if() //判断是否捕获 
			//	{
			//		(location[0][0]-location[1][0])*(location[0][0]-location[1][0])+(location[0][1]-location[1][1])*(location[0][1]-location[1][1])<1.5
				
			//	} 
				
				/*----------------------------------------------------------------------------------------------*/
				Sleep(200);															
			} 	    
		}
		
		
		print_time(start , p_stop_temp,sign_time);	//显示游戏时间 	
		/*---------------------------------------------------------------------------------------*/
	
		print_bushou(start,p_stop_temp1,  head, p_step_num  ); //显示时间函数，间隔超过0.1才会刷新，避免闪烁 
		
		
		if(*p_step_num==2&&LengthList(head)==1) 
			goto P;
		/*--------*/   //放弃，链表方法难以实现真正的路线规划，需要重新设计，改用全图路线规划算法 ，以后再做 
		
//		if(location[1][0]>=2&&location[1][0]<=NN-3&&location[1][1]>=2&&location[1][1]<=NN-3) //在图里面才会执行 
//		{
//				
//			if(sign_skill==1)   //技能释放 
//			{			  
//			  	if( (GetKeyState('P' )<0) ||(GetKeyState('p')<0) )
//			  	{	
//					sign_skill=0;	//限定技能只有一次 
//					
//					/********炸墙技能*****但不会对最外围的墙起作用*****/ 		
//					game_skill_p(location[1][0],location[1][1],maze);
//												
//				//	Sleep(200);	
//				//	gotoxy(35,-1);
//				//	printf("技能已经释放！"); 															
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
		    	printf("你被抓到！");
		    	while(1);
			
			}		
			
		}
		
		                
	    if(location[1][1]==NN-1)   //如果出墙的范围，判定成功 
	    {
	    	sign_time = 0;
	    	
	    	//system("cls");
	    	gotoxy(12,2*39); 
	    	color(16);
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	    	printf("恭喜成功过关！");
	    	while(1);
		}   
//		//链表测试		
//		gotoxy(35,-1);     //避免光标影响   
//		printf("                                                                       "); 
//		gotoxy(35,-1);     //避免光标影响 
//		HideCursor(); 
//		PrintList( head ) ;   
	
    }
    
    return 0;
}

