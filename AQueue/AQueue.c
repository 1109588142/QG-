#include"AQueue.h"
#include<stdio.h>
#include<stdlib.h>
void stringcopy(void* a,void* b, int size);

void InitAQueue(AQueue *Q) //初始化队列
{
	int i;
	Q->length=MAXQUEUE;
	for(i=0;i<MAXQUEUE;i++)
	{
		Q->data[i]=(void*)malloc(21);
	}
	Q->front=Q->rear=0;
	printf("初始化队列成功\n");
}

void DestoryAQueue(AQueue *Q) //销毁队列
{
	int i;
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
	}
	for(i=0;i<MAXQUEUE;i++)
	{
		free(Q->data[i]);
	}
}

Status IsFullAQueue(const AQueue *Q) //检查队列是否已满
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
	if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		return TRUE;
	}
	printf("队列未满\n");
	return FALSE;
}

Status IsEmptyAQueue(const AQueue *Q) //检查队列是否为空
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
	if(Q->front==Q->rear)
	{
		printf("该队列为空\n");
		return TRUE;
	}
	printf("该队列不为空\n");
	return FALSE;
}

Status GetHeadAQueue(AQueue *Q, void *e)//查看队头元素
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
	stringcopy(e,Q->data[Q->front],21);
	APrint(Q->data[Q->front],datatype[Q->front]);
	return TRUE;
}

int LengthAQueue(AQueue *Q)//确定队列长度
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
	int count;
	count=(Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
	return count;
}

Status EnAQueue(AQueue *Q, void *data)//入队操作
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
		if(Q->front==(Q->rear+1)%MAXQUEUE)
	{
		printf("队列已满，无法入队\n");
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

Status DeAQueue(AQueue *Q)//出队操作
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
	if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("该队列为空\n");
		return FALSE;
	}
	Q->front=(Q->front+1)%MAXQUEUE;
	return TRUE;
}

void ClearAQueue(AQueue *Q)//清空队列
{
	if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
	}
		if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("该队列为空\n");
	}
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q,char Datatype))//遍历函数操作
{
		if(Q->data[0]==NULL)
	{
		printf("该队列未初始化\n");
		return FALSE;
	}
		if(IsEmptyAQueue(Q)==TRUE)
	{
		printf("该队列为空\n");
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







