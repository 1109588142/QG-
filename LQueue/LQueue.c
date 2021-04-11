#include"LQueue.h"
#include<stdio.h>
#include<stdlib.h>
void stringcopy(void* a,void* b, int size);

void InitLQueue(LQueue *Q)//��ʼ������
{
	Q->front=(Node *)malloc(sizeof(Node));
	Q->front->next=(Node *)malloc(sizeof(Node));
	Q->front->data=(void*)malloc(21);
	Q->front->next=NULL;
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->rear->next=NULL;
	}
	Q->length=0;
}

void DestoryLQueue(LQueue *Q)//���ٶ���
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
	}
	ClearLQueue(Q);
	free(Q->front);

}

Status IsEmptyLQueue(const LQueue *Q)//�������Ƿ�Ϊ��
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(Q->length==0)
	{
		return TRUE;
	}
	printf("���в�Ϊ��\n");
	return FALSE;
}

Status GetHeadLQueue(LQueue *Q, void *e)//�鿴��ͷԪ��
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
		return FALSE;
	}
	stringcopy(e,Q->front->data,21);
	LPrint(Q->front->data,Q->front->type);
	return TRUE;
}

int LengthLQueue(LQueue *Q)//ȷ�����г���
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	return Q->length;
}

Status EnLQueue(LQueue *Q, void *data)//��Ӳ���
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	p->data=(void*)malloc(21);
	stringcopy(p->data,data,21);
	p->next=NULL;
	if(Q->length==0)
	{
		Q->front=p;
	}else {
		Q->rear->next=p;
	}
	Q->rear=p;
	Q->length++;
	printf("��ӳɹ�\n");
	return TRUE;
}

Status DeLQueue(LQueue *Q)//���Ӳ���
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
		return FALSE;
	}
	Q->front=Q->front->next;
	Q->length--;
	printf("���ӳɹ�\n");
	return TRUE;
}

void ClearLQueue(LQueue *Q)//��ն���
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
	}
	Q->front=Q->rear;
	Q->length=0;
	printf("��ն��гɹ�\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q,char Datatype))//��������
{
	if(Q->front==NULL)
	{
		printf("����δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyLQueue(Q)==TRUE)
	{
		printf("����һ���ն���\n");
		return FALSE;
	}
   	Node *p=NULL;
	p=(Node *)malloc(sizeof(Node));
	p->data=(void*)malloc(21);
	p=Q->front;
	while(p->next!=NULL)
	{
		foo(p->data,p->type);
		p=p->next;
	}
	foo(p->data,p->type);
	return TRUE;
 } 


void LPrint(void *q,char Datatype)
    {
        if(Datatype == 'd')
            printf("--> %.2lf", *(double*)q);
        if(Datatype == 'c')
            printf("--> %c", *(char*)q);
        if(Datatype == 'i')
            printf("--> %d ", *(int*)q);
        if(Datatype == 's')
            printf("--> %s ", (char*)q);
    }
void stringcopy(void* a,void* b, int size){
	int i;
    for( i = 0 ; i < size ; i ++){
        ((char*)a)[i] = ((char*)b)[i];
    }
}
