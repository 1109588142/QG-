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
LinkedList getNode(LinkedList h,int n);//获取对应节点
LinkedList createNode();//创建一个节点
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
		case 1:   DestroyList(head1);  printf("链表删除成功\n");break; 
		case 2:   {
		
			
		      LinkedList p2,p3;
	             	int a,b; 
	             	a=0;b=0;
	            	int j;
		      p3 = (LinkedList)malloc(sizeof(LNode));
		       
			printf("请输入在哪个节点的后面添加节点\n");
			scanf("%d",&a);
			for( j=0;j<a-1;j++)
			{
				p1=p1->next;
			}
			printf("请输入要添加的值\n");
			scanf("%d",&b);
			p3->data=b;
		if(InsertList(p1, p3)==SUCCESS){
		
			printf("操作结果显示\n");
			TraverseList(head,visit);} 
	
			break;
	}
	case 3:{
	
		printf("你想删除第几个节点之后的节点：");
                scanf("%d",&num);
                if(DeleteList(getNode(head,num),e)==SUCCESS)
                {
                    printf("删除成功,被删除的节点数据为%d\n",*e);
                }
                else
                {
                	printf("删除失败\n");
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
	printf("请输入你要找的数据");
		scanf("%d",&a); 
	 	SearchList(p2, a);
	 	int i=1;
	 	while(p1->data!=a)
	 	{
	 		i++;
	 		p1=p1->next;
		 }
	 	printf("找到了是第%d个节点的数据",i);
	
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
				  printf("第%d个数据：%d\n",i,(*L)->data);
				  i++;
	   		  (*L)=(*L)->next;
		   }
		}
		break;
	}
	case 7:{
		if(IsLoopList(p1)==SUCCESS)
		{
			printf("该链表成环");
		}else printf("该链表不成环");
		break;
	}
	case 8:{
		 TraverseList(ReverseEvenList(head1),visit);
		break;
	}
	case 9:{
	  LinkedList p1=FindMidNode(head1);
	  printf("P1就是中间节点的指针\n");
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
	printf("请输入要存储的数据 当输入00时结束存储\n");
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
	printf("△2、在链表中添加节点");
	gotoxy(45,6);
	printf("△3、删除某节点后的一个节点，并将被删除的节点的值拿出来");
	gotoxy(45,7);
	printf("△4、遍历链表");
	gotoxy(45,8);
	printf("△5、根据数据查找所在的节点");
	gotoxy(45,9);
	printf("△6、将链表反向");
	gotoxy(45,10);
	printf("△7、判断链表是否成环");
	gotoxy(45,11);
	printf("△8、将奇偶节点互换");
	gotoxy(45,12);
	printf("△9、找到链表的中间节点");
	gotoxy(45,13);
	printf("请输入要进行的操作");
	gotoxy(64,13);
	scanf("%d",&k);
	 
	
}
LinkedList getNode(LinkedList h,int n)//获取需要用到的节点
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

LinkedList createNode()//创建一个新节点
{
    LinkedList q;
    q = (LinkedList)malloc(sizeof(LNode));
    printf("请输入你要插入的数据：");
    scanf("%d",q->data);
    return q;
}
