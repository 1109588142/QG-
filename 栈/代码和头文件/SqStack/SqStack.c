#include"SqStack.h"
#include<stdio.h>
#include <stdlib.h>


Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	(*s).elem=(ElemType *)malloc(sizes*sizeof(ElemType));
	(*s).top=0;
	(*s).size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if((*s).top==0)
	{
		printf("��ջ��һ����ջ\n");
		return SUCCESS;
	}
	 printf("��ջ����һ����ջ\n");
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //�õ�ջ��Ԫ��
{
	if((*s).top==0)
	{
		printf("��ջ��һ����ջ\n");
		return ERROR;
	}
	*e=(*s).elem[(*s).top-1];
	return SUCCESS;
}

Status clearStack(SqStack *s)//���ջ
{
	if((*s).top==0)
	{
		printf("����һ����ջ\n");
		return SUCCESS;
	}
	(*s).top=0;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	
    free ((*s).elem);
    free(s);
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	if((*s).top==0)
	{
		printf("����һ����ջ\n");
		*length=0;
		return SUCCESS;
	} 
	*length=(*s).top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if((*s).top==(*s).size)
	{
		printf("����һ����ջ���޷�����ջ\n");
		return ERROR;
	}
   (*s).elem[(*s).top]=data;
   (*s).top++;
   return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if((*s).top==0)
	{
		printf("����һ����ջ\n");
		return SUCCESS;
	} 
   *data=(*s).elem[(*s).top-1];
   (*s).top--;
   return SUCCESS;
}










