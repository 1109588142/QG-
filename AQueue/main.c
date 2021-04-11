#include"AQueue.h"
#include"AQueue.c"
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
void createtemp();
AQueue Q;
int choise=0; 
void *e;
int main()
{    e=(void *)malloc(sizeof(void ));
	while(1)
	{
		createtemp();
		system("cls");
		switch(choise)
		{
			case 1:{
				InitAQueue(&Q);
				system("pause");
				break;
			}
			case 2:{
				DestoryAQueue(&Q);
				printf("销毁队列成功\n");
				system("pause");
				break;
			}
			case 3:{
				if(IsFullAQueue(&Q)==TRUE)
				{
					printf("该队列已满\n");
				}
				system("pause");
				break;
			}
			case 4:{
				IsEmptyAQueue(&Q);
				system("pause");
				break;
			}
			case 5:{
				GetHeadAQueue(&Q, e);
				system("pause");
				break;
			}
			case 6:{
				printf("队列长度%d\n",LengthAQueue(&Q));
				system("pause");
				break;
			}
			case 7:{
				int t;
				printf("你想入队哪种类型？:\n");
                printf("1. 整型 2. 字符型 3. 浮点型 4. 字符串\n");
                scanf("%d", &t);
                printf("请输入数据");
                switch(t)
                {
                	case 1:{
                		int a;
			            scanf("%d", &a);
			            datatype[Q.rear]='i';
			            EnAQueue(&Q, &a);
						break;
					}
					case 2:{
						fflush(stdin);
						char a;
						scanf("%c",&a);
						datatype[Q.rear]='c';
						EnAQueue(&Q, &a);
						break;
					}
					case 3:{
						double a;
						scanf("%lf",&a);
						datatype[Q.rear]='d';
						EnAQueue(&Q, &a);
						break;
					}
					case 4:{
						fflush(stdin);
						char a[20];
						scanf("%s", a);
						datatype[Q.rear]='s';
						EnAQueue(&Q, a);
						break;
					}
				}
				printf("入队成功\n");
				system("pause");
				break;
			}
			case 8:{
				DeAQueue(&Q);
				printf("出队成功\n");
				system("pause");
				break;
			}
			case 9:{
				ClearAQueue(&Q);
				printf("清空队列成功\n");
				system("pause");
				break;
			}
			case 10:{
				TraverseAQueue(&Q, APrint);
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
	printf("△3、检查队列是否已满");
	gotoxy(45,7);
	printf("△4、检查队列是否为空");
	gotoxy(45,8);
	printf("△5、查看队头元素");
	gotoxy(45,9);
	printf("△6、确定队列长度");
	gotoxy(45,10);
	printf("△7、入队操作");
	gotoxy(45,11);
	printf("△8、出队操作");
	gotoxy(45,12);
	printf("△9、清空队列");
	gotoxy(45,13);
	printf("△10、遍历队列");
	gotoxy(45,14);
	printf("请输入要进行的操作");
	gotoxy(64,14);
	scanf("%d",&choise);
	
	
}
