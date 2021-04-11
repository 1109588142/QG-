#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
void stringcopy(void* a,void* b, int size);

void InitAQueue(AQueue *Q) //��ʼ������
{
	int i;
	Q->length=MAXQUEUE;
	for(i=0;i<MAXQUEUE;i++)
	{
		Q->data[i]=(void*)malloc(21);
	}
	Q->front=Q->rear=0;
	printf("��ʼ�����гɹ�\n");
}

void DestoryAQueue(AQueue *Q) //���ٶ���
{
	int i;
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
	}
	for(i=0;i<MAXQUEUE;i++)
	{
		free(Q->data[i]);
	}
}

Status IsFullAQueue(const AQueue *Q) //�������Ƿ�����
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
	if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		return TRUE;
	}
	printf("����δ��\n");
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q) //�������Ƿ�Ϊ��
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("�ö���Ϊ��\n");
		return TRUE;
	}
	printf("�ö��в�Ϊ��\n");
	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)//�鿴��ͷԪ��
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
	stringcopy(e,Q->data[Q->front],21);
	APrint(Q->data[Q->front],datatype[Q->front]);
	return TRUE;
}

int LengthAQueue(AQueue *Q)//ȷ�����г���
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
	int count;
	count=(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
	return count;
}

Status EnAQueue(AQueue *Q, void *data)//��Ӳ���
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
		if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		printf("�����������޷����\n");
		return FALSE;
	}
	if(Q->rear==MAXQUEUE-1)
	{
		Q->rear=0;
	}
	stringcopy(Q->data[Q->rear],data,21);
	Q->rear++;
	return TRUE;
}

Status DeAQueue(AQueue *Q)//���Ӳ���
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("�ö���Ϊ��\n");
		return FALSE;
	}
	Q->front=(Q->front+1)%MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//��ն���
{
	if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
	}
		if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("�ö���Ϊ��\n");
	}
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,char Datatype))//������������
{
		if(Q->data[0]==NULL)
	{
		printf("�ö���δ��ʼ��\n");
		return FALSE;
	}
		if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("�ö���Ϊ��\n");
		return FALSE;
	}
	int i=0;
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
    		foo(Q->data[Q->front+i],datatype[Q->front+i]);
    		i = (i + 1) % MAXQUEUE;
    	}
        return TRUE;
}

void APrint(void *q,char Datatype)
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







