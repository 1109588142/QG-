#include<stdio.h>
#include"linkedList.h"
#include <stdlib.h>
#include "linkedList.c"
#include"windows.h"
LinkedList creat(); 
void creattemp();
void creattemp2();
int i;
int k=1;
int num=0;
LinkedList p1;
void visit(ElemType e);
LinkedList getNode(LinkedList h,int n);//��ȡ��Ӧ�ڵ�
LinkedList createNode();//����һ���ڵ�
ElemType *e;
int main()
{  
    creattemp();
    if(i==1)
    {  
       system("cls");
    	LinkedList head=(LinkedList)creat();
    	p1=head;
    	LinkedList* head1;
    	head1=&head;
    	system("cls");
       TraverseList(head,visit);
    creattemp2();
   	switch(k)
	{
		case 1:   DestroyList(head1);  printf("����ɾ���ɹ�\n");break; 
		case 2:   {
		
			
		      LinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (LinkedList)malloc(sizeof(LNode));
		       
			printf("���������ĸ��ڵ�ĺ�����ӽڵ�\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("������Ҫ��ӵ�ֵ\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertList(p1, p3)==SUCCESS){
		
			printf("���������ʾ\n");
			TraverseList(head,visit);} 
	
			break;
	}
	case 3:{
	
		printf("����ɾ���ڼ����ڵ�֮��Ľڵ㣺");
                scanf("%d",&num);
                if(DeleteList(getNode(head,num),e)==SUCCESS)
                {
                    printf("ɾ���ɹ�,��ɾ���Ľڵ�����Ϊ%d\n",*e);
                }
                else
                {
                	printf("ɾ��ʧ��\n");
                }
                break;
	}
	case 4:{
		TraverseList(head,visit);
		break;
	}
	case 5:{
	ElemType a=0;
	LinkedList p2;
	p2=p1;
	printf("��������Ҫ�ҵ�����");
		scanf("%d",&a); 
	 	SearchList(p2, a);
	 	int i=1;
	 	while(p1->data!=a)
	 	{
	 		i++;
	 		p1=p1->next;
		 }
	 	printf("�ҵ����ǵ�%d���ڵ������",i);
	
		break;
	}
	case 6:{
		LinkedList *L;
		L=&p1;
	if(	ReverseList(L)==SUCCESS)
	{   LinkedList p5=(LinkedList)malloc(sizeof(LNode));
	p5=*L;
	*L=(*L)->next;
	free(p5);
	int i=1;
	   	while((*L)!=NULL)
	   	{   
				  printf("��%d�����ݣ�%d\n",i,(*L)->data);
				  i++;
	   		  (*L)=(*L)->next;
		   }
		}
		break;
	}
	case 7:{
		if(IsLoopList(p1)==SUCCESS)
		{
			printf("������ɻ�");
		}else printf("�������ɻ�");
		break;
	}
	case 8:{
		 TraverseList(ReverseEvenList(head1),visit);
		break;
	}
	case 9:{
	  LinkedList p1=FindMidNode(head1);
	  printf("P1�����м�ڵ��ָ��\n");
	  printf("p1->data=%d",p1->data);
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
LinkedList creat()
{
	printf("������Ҫ�洢������ ������00ʱ�����洢\n");
	LinkedList head;
	LinkedList p1, p2;
	int n = 0;
	p1 = p2 = (LinkedList)malloc(sizeof(LNode));
	scanf_s("%d", &p1->data);
	head = NULL;
	while (p1->data!= 00)
	{
		n = n + 1;
		if (n == 1)
		{
			head = p1;
		}
		else p2->next = p1;
		p2 = p1;
		p1 = (LinkedList)malloc(sizeof(LNode));
		scanf_s("%d", &p1->data);

	}
	p2->next = p1;
	p1->next=NULL;
return head;
}
void seedata(LinkedList head)
{
	int i=1; 
	LinkedList temp;
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
	printf("��2������������ӽڵ�");
	gotoxy(45,6);
	printf("��3��ɾ��ĳ�ڵ���һ���ڵ㣬������ɾ���Ľڵ��ֵ�ó���");
	gotoxy(45,7);
	printf("��4����������");
	gotoxy(45,8);
	printf("��5���������ݲ������ڵĽڵ�");
	gotoxy(45,9);
	printf("��6����������");
	gotoxy(45,10);
	printf("��7���ж������Ƿ�ɻ�");
	gotoxy(45,11);
	printf("��8������ż�ڵ㻥��");
	gotoxy(45,12);
	printf("��9���ҵ�������м�ڵ�");
	gotoxy(45,13);
	printf("������Ҫ���еĲ���");
	gotoxy(64,13);
	scanf("%d",&k);
	 
	
}
LinkedList getNode(LinkedList h,int n)//��ȡ��Ҫ�õ��Ľڵ�
{
    if(n<1) return NULL;
    LinkedList p = h;
 int i;
    for( i = 1;i < n;i++)
    {
        p = p->next;
        if(i < n-1 && p->next == NULL)
            return NULL;
    }

    return p;
}

LinkedList createNode()//����һ���½ڵ�
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("��������Ҫ��������ݣ�");
    scanf("%d",q->data);
    return q;
}
