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
				printf("���ٶ��гɹ�\n");
				system("pause");
				break;
			}
			case 3:{
				if(IsFullAQueue(&Q)==TRUE)
				{
					printf("�ö�������\n");
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
				printf("���г���%d\n",LengthAQueue(&Q));
				system("pause");
				break;
			}
			case 7:{
				int t;
				printf("��������������ͣ�:\n");
                printf("1. ���� 2. �ַ��� 3. ������ 4. �ַ���\n");
                scanf("%d", &t);
                printf("����������");
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
				printf("��ӳɹ�\n");
				system("pause");
				break;
			}
			case 8:{
				DeAQueue(&Q);
				printf("���ӳɹ�\n");
				system("pause");
				break;
			}
			case 9:{
				ClearAQueue(&Q);
				printf("��ն��гɹ�\n");
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
	printf("��ѡ�����");
	gotoxy(45,4);
	printf("��1����ʼ������");
	gotoxy(45,5);
	printf("��2�����ٶ���");
	gotoxy(45,6);
	printf("��3���������Ƿ�����");
	gotoxy(45,7);
	printf("��4���������Ƿ�Ϊ��");
	gotoxy(45,8);
	printf("��5���鿴��ͷԪ��");
	gotoxy(45,9);
	printf("��6��ȷ�����г���");
	gotoxy(45,10);
	printf("��7����Ӳ���");
	gotoxy(45,11);
	printf("��8�����Ӳ���");
	gotoxy(45,12);
	printf("��9����ն���");
	gotoxy(45,13);
	printf("��10����������");
	gotoxy(45,14);
	printf("������Ҫ���еĲ���");
	gotoxy(64,14);
	scanf("%d",&choise);
	
	
}
