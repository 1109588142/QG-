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
DuLinkedList getNode(DuLinkedList h,int n);//��ȡ��Ӧ�ڵ�
DuLinkedList createNode();//����һ���ڵ�
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
		case 1:   DestroyList_DuL(head1);  printf("����ɾ���ɹ�\n");break; 
		case 2:   {
		      DuLinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (DuLinkedList)malloc(sizeof(DuLNode));
		       
			printf("���������ĸ��ڵ��ǰ����ӽڵ�(�����ڵ�һ���ڵ�ǰ���)\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("������Ҫ��ӵ�ֵ\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertBeforeList_DuL(p1, p3)==SUCCESS){
		
			printf("���������ʾ\n");
			TraverseList_DuL(head,visit);} 
	
			break;
	}
	case 3:{
	 DuLinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (DuLinkedList)malloc(sizeof(DuLNode));
		       
			printf("���������ĸ��ڵ�ĺ�����ӽڵ�\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("������Ҫ��ӵ�ֵ\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertAfterList_DuL(p1, p3)==SUCCESS){
		
			printf("���������ʾ\n");
			TraverseList_DuL(head,visit);} 
	
			break;
	
	}
	case 4:{
	   int a;
	   ElemType *e;
	   printf("��������ɾ���Ľڵ��ǰһ���ڵ�\n");
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
			printf("����������ɹ�");
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
	printf("������Ҫ�洢������ ������00ʱ�����洢\n");
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
		printf("��%d�����ݣ�%d\n",i,temp->data);
		temp=temp->next;
		i++;
	}
}
void creattemp()
{
	gotoxy(45,4);
	printf("�������������������󤦤�������");
	gotoxy(50,8);
	printf("����һ�����ݴ洢��");
	gotoxy(48,10);
	printf("����1��ʼ�洢����");
	gotoxy(45,14);
	printf("�������������Ƥ����������Ƥ���");
	gotoxy(67,10);
	scanf("%d",&i);
	gotoxy(25,20);
}
void creattemp2()
{
	
	gotoxy(47,3);
	printf("��ѡ�����");
	gotoxy(45,4);
	printf("��1��ɾ������");
	gotoxy(45,5);
	printf("��2����ĳ�ڵ�֮ǰ���һ���ڵ�");
	gotoxy(45,6);
	printf("��3����ĳ�ڵ�֮�����һ���ڵ�");
	gotoxy(45,7);
	printf("��4��ɾ��ĳ�ڵ�ĺ�һ���ڵ㣬������ɾ���Ľڵ㸳ֵ��e");
	gotoxy(45,8);
	printf("��5����������");
	gotoxy(45,9);
	printf("��6������һ��������");
	gotoxy(45,10);
	printf("������Ҫ���еĲ���");
	gotoxy(64,10);
	scanf("%d",&k);
	 
	
}
DuLinkedList getNode(DuLinkedList h,int n)//��ȡ��Ҫ�õ��Ľڵ�
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

DuLinkedList createNode()//����һ���½ڵ�
{
    DuLinkedList q;
    q = (DuLinkedList)malloc(sizeof(DuLNode));
    printf("��������Ҫ��������ݣ�");
    scanf("%d",q->data);
    return q;
}
