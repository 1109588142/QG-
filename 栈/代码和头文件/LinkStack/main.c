#include<stdio.h>
#include"LinkStack.h"
#include"LinkStack.C"
#include"windows.h"
void creattemp();
void gotoxy(int x,int y);
LinkStack *s;
 int count;
 int *length;
 ElemType data;
 ElemType *data1;
 ElemType *e;
 int a=0;
int main()
{
	length=(int *)malloc(sizeof(int)); 
	e=(ElemType *)malloc(sizeof(ElemType));
	data1=(ElemType *)malloc(sizeof(ElemType));
	s=(LinkStack *)malloc(sizeof(LinkStack));
		while(1)
	{  	
	 creattemp();
	gotoxy(64,13);
	scanf("%d",&a);
		switch(a)
		{
			case 1:   {
			initLStack(s);
	    		printf("��ʼ��ջ�ɹ�\n");
	    		system("pause");
				break;
			}
			
			
			case 2: { 	isEmptyLStack(s);
				system("pause");
				break;
			} 
			case 3:{
			getTopLStack(s,e);
					printf("ջ��������%d\n",*e);
					system("pause");
				break;
			}
			
			case 4:  {
				clearLStack(s);
				printf("���ջ�ɹ�\n");
				system("pause");
				break;
			}
			
			
			case 5: 	destroyLStack(s);
				printf("����ջ�ɹ��������³�ʼ��ջ�����˳�����\n");
				system("pause");
				break;
			
			case 6: LStackLength(s,length);
			printf("��ջ�ĳ�����%d\n",*length); 
			system("pause");
			break;
			
			case 7: printf("������Ҫ��ջ������\n");
			         scanf("%d",&data); 
			   pushLStack(s, data);
			   printf("��ջ�ɹ�\n");
			   system("pause");
			   break;
			   
			case 8: 	popLStack(s,data1);
				printf("��ջ��Ԫ����%d",*data1);
				system("pause");
				break;
			        
			case 9: {
				exit(0);  
				break;
			}      
		}
		system("cls");
		
		
	}
	return 0;
}

void gotoxy(int x,int y)
{
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
 } 
 
 void creattemp()
{
	
	gotoxy(47,3);
	printf("��ѡ�����");
	gotoxy(45,4);
	printf("��1����ʼ��ջ");
	gotoxy(45,5);
	printf("��2���ж�ջ�Ƿ�Ϊ��");
	gotoxy(45,6);
	printf("��3���õ�ջ��Ԫ��");
	gotoxy(45,7);
	printf("��4�����ջ");
	gotoxy(45,8);
	printf("��5������ջ");
	gotoxy(45,9);
	printf("��6�����ջ����");
	gotoxy(45,10);
	printf("��7����ջ");
	gotoxy(45,11);
	printf("��8����ջ");
	gotoxy(45,12);
	printf("��9���˳�����");
	gotoxy(45,13);
	printf("������Ҫ���еĲ���   (��һ�α����ʼ��ջ)");

}
