#include<stdio.h>
#include"duLinkedList.h"
#include <stdlib.h>
#include "duLinkedList.c"
#include"windows.h"
DuLinkedList creat(); 
void creattemp();
void creattemp2();
int i;
int k=1;
int num=0;
DuLinkedList p1;
void visit(ElemType e);
DuLinkedList getNode(DuLinkedList h,int n);//获取对应节点
DuLinkedList createNode();//创建一个节点
ElemType *e;
int main()
{  
    creattemp();
    if(i==1)
    {  
       system("cls");
    	DuLinkedList head=(DuLinkedList)creat();
    	p1=head;
    	DuLinkedList* head1;
    	head1=&head;
    	system("cls");
       TraverseList_DuL(head,visit);
    creattemp2();
   	switch(k)
	{
		case 1:   DestroyList_DuL(head1);  printf("链表删除成功\n");break; 
		case 2:   {
		      DuLinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (DuLinkedList)malloc(sizeof(DuLNode));
		       
			printf("请输入在哪个节点的前面添加节点(不可在第一个节点前添加)\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("请输入要添加的值\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertBeforeList_DuL(p1, p3)==SUCCESS){
		
			printf("操作结果显示\n");
			TraverseList_DuL(head,visit);} 
	
			break;
	}
	case 3:{
	 DuLinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (DuLinkedList)malloc(sizeof(DuLNode));
		       
			printf("请输入在哪个节点的后面添加节点\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("请输入要添加的值\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertAfterList_DuL(p1, p3)==SUCCESS){
		
			printf("操作结果显示\n");
			TraverseList_DuL(head,visit);} 
	
			break;
	
	}
	case 4:{
	   int a;
	   ElemType *e;
	   printf("输入你想删除的节点的前一个节点\n");
	   scanf("%d",&a);
	   int j;
	   for(i=0;j<a-1;j++)
	   {
	   	  p1=p1->next;
	   }
	    if( DeleteList_DuL(p1, e)==SUCCESS){
	    	
		}
	    TraverseList_DuL(head,visit);
		break;
	}
	case 5:{
	
	TraverseList_DuL(head,visit);
		break;
	}
	case 6:{
		DuLinkedList *L;
		if(InitList_DuL(L)==SUCCESS)
		{
			printf("创建空链表成功");
		}
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
DuLinkedList creat()
{
	printf("请输入要存储的数据 当输入00时结束存储\n");
	DuLinkedList head;
	DuLinkedList p1, p2;
	int n = 0;
	p1 = p2 = (DuLinkedList)malloc(sizeof(DuLNode));
	scanf_s("%d", &p1->data);
	head = NULL;
	while (p1->data!= 00)
	{
		n = n + 1;
		if (n == 1)
		{
			head = p1;
		}
		else {
		p2->next = p1;
		p1->prior=p2;
	}
		p2 = p1;
		p1 = (DuLinkedList)malloc(sizeof(DuLNode));
		scanf_s("%d", &p1->data);

	}
	p2->next = p1;
	p1->next=NULL;
return head;
}
void seedata(DuLinkedList head)
{
	int i=1; 
	DuLinkedList temp;
	temp=head;
	while(temp->data!=00)
	{
		printf("第%d个数据：%d\n",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void creattemp()
{
	gotoxy(45,4);
	printf("かすうきけせかす△◇うくきかす");
	gotoxy(50,8);
	printf("这是一个数据存储器");
	gotoxy(48,10);
	printf("输入1开始存储数据");
	gotoxy(45,14);
	printf("せきちせけきてたしすせせてちつ");
	gotoxy(67,10);
	scanf("%d",&i);
	gotoxy(25,20);
}
void creattemp2()
{
	
	gotoxy(47,3);
	printf("可选择操作");
	gotoxy(45,4);
	printf("△1、删除链表");
	gotoxy(45,5);
	printf("△2、在某节点之前添加一个节点");
	gotoxy(45,6);
	printf("△3、在某节点之后添加一个节点");
	gotoxy(45,7);
	printf("△4、删掉某节点的后一个节点，并将被删除的节点赋值给e");
	gotoxy(45,8);
	printf("△5、遍历链表");
	gotoxy(45,9);
	printf("△6、创建一个空链表");
	gotoxy(45,10);
	printf("请输入要进行的操作");
	gotoxy(64,10);
	scanf("%d",&k);
	 
	
}
DuLinkedList getNode(DuLinkedList h,int n)//获取需要用到的节点
{
    if(n<1) return NULL;
    DuLinkedList p = h;
 int i;
    for( i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)
            return NULL;
    }

    return p;
}

DuLinkedList createNode()//创建一个新节点
{
    DuLinkedList q;
    q = (DuLinkedList)malloc(sizeof(DuLNode));
    printf("请输入你要插入的数据：");
    scanf("%d",q->data);
    return q;
}
