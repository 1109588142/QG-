#include"LQueue.h"
#include"LQueue.c"
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
void createtemp();
LQueue Q;
int choise=0; 
void *e;
int main()
{
	e=(void *)malloc(sizeof(void ));
	while(1)
	{
		createtemp();
		system("cls");
		switch(choise)
		{
			case 1:{
				InitLQueue(&Q);
				printf("初始化队列成功\n");
				system("pause");
				break;
			}
			case 2:{
				DestoryLQueue(&Q);
				printf("销毁队列成功\n");
				system("pause");
				break;
			}
			case 3:{
				if(IsEmptyLQueue(&Q)==TRUE)
				{
					printf("队列为空\n");
				}
				system("pause");
				break;
			}
			case 4:{
				GetHeadLQueue(&Q, e);
				system("pause");
				break;
			}
			case 5:{
				if(LengthLQueue(&Q)!=FALSE)
				{
					printf("队列长度：%d\n",LengthLQueue(&Q));
				}
				system("pause");
				break;
			}
			case 6:{
				int t;
				printf("你想入队哪种类型？:\n");
                printf("1. 整型 2. 字符型 3. 浮点型 4. 字符串\n");
                scanf("%d", &t);
                printf("请输入数据\n");
                switch(t)
                {
                	case 1:{
                		int a;
			            scanf("%d", &a);
			            Q.rear->type='i';
			            EnLQueue(&Q, &a);
						break;
					}
					case 2:{
						fflush(stdin);
						char b;
						scanf("%c",&b);
						Q.rear->type='c';
						EnLQueue(&Q, &b);
						break;
					}
					case 3:{
						double c;
						scanf("%lf",&c);
						Q.rear->type='d';
						EnLQueue(&Q, &c);
						break;
					}
					case 4:{
						fflush(stdin);
						char d[20];
						scanf("%s", d);
						Q.rear->type='s';
						EnLQueue(&Q, d);
						break;
					}
				}
				system("pause");
				break;
			}
			case 7:{
				DeLQueue(&Q);
				system("pause");
				break;
			}
			case 8:{
				ClearLQueue(&Q);
				system("pause");
				break;
			}
			case 9:{
				TraverseLQueue(&Q,LPrint);
				system("pause");
				break;
			}
		}
	}
	return 0;
}

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
 } 
void createtemp()
{
		gotoxy(47,3);
	printf("可选择操作");
	gotoxy(45,4);
	printf("△1、初始化队列");
	gotoxy(45,5);
	printf("△2、销毁队列");
	gotoxy(45,6);
	printf("△3、检查队列是否为空");
	gotoxy(45,7);
	printf("△4、查看队头元素");
	gotoxy(45,8);
	printf("△5、确定队列长度");
	gotoxy(45,9);
	printf("△6、入队操作");
	gotoxy(45,10);
	printf("△7、出队操作");
	gotoxy(45,11);
	printf("△8、清空队列");
	gotoxy(45,12);
	printf("△9、遍历队列");
	gotoxy(45,13);
	printf("请输入要进行的操作");
	gotoxy(64,13);
	scanf("%d",&choise);
	
	
}
