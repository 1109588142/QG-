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
	    		printf("初始化栈成功\n");
	    		system("pause");
				break;
			}
			
			
			case 2: { 	isEmptyLStack(s);
				system("pause");
				break;
			} 
			case 3:{
			getTopLStack(s,e);
					printf("栈顶数据是%d\n",*e);
					system("pause");
				break;
			}
			
			case 4:  {
				clearLStack(s);
				printf("清空栈成功\n");
				system("pause");
				break;
			}
			
			
			case 5: 	destroyLStack(s);
				printf("销毁栈成功，请重新初始化栈或者退出程序\n");
				system("pause");
				break;
			
			case 6: LStackLength(s,length);
			printf("该栈的长度是%d\n",*length); 
			system("pause");
			break;
			
			case 7: printf("请输入要入栈是数据\n");
			         scanf("%d",&data); 
			   pushLStack(s, data);
			   printf("入栈成功\n");
			   system("pause");
			   break;
			   
			case 8: 	popLStack(s,data1);
				printf("出栈的元素是%d",*data1);
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
	printf("可选择操作");
	gotoxy(45,4);
	printf("△1、初始化栈");
	gotoxy(45,5);
	printf("△2、判断栈是否为空");
	gotoxy(45,6);
	printf("△3、得到栈顶元素");
	gotoxy(45,7);
	printf("△4、清空栈");
	gotoxy(45,8);
	printf("△5、销毁栈");
	gotoxy(45,9);
	printf("△6、检测栈长度");
	gotoxy(45,10);
	printf("△7、入栈");
	gotoxy(45,11);
	printf("△8、出栈");
	gotoxy(45,12);
	printf("△9、退出程序");
	gotoxy(45,13);
	printf("请输入要进行的操作   (第一次必须初始化栈)");

}
