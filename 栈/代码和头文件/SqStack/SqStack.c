#include"SqStack.h"
#include<stdio.h>
#include <stdlib.h>


Status initStack(SqStack *s,int sizes)//初始化栈
{
	(*s).elem=(ElemType *)malloc(sizes*sizeof(ElemType));
	(*s).top=0;
	(*s).size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//判断栈是否为空
{
	if((*s).top==0)
	{
		printf("该栈是一个空栈\n");
		return SUCCESS;
	}
	 printf("该栈不是一个空栈\n");
	return SUCCESS;
}

Status getTopStack(SqStack *s,ElemType *e) //得到栈顶元素
{
	if((*s).top==0)
	{
		printf("该栈是一个空栈\n");
		return ERROR;
	}
	*e=(*s).elem[(*s).top-1];
	return SUCCESS;
}

Status clearStack(SqStack *s)//清空栈
{
	if((*s).top==0)
	{
		printf("这是一个空栈\n");
		return SUCCESS;
	}
	(*s).top=0;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//销毁栈
{
	
    free ((*s).elem);
    free(s);
    return SUCCESS;
}

Status stackLength(SqStack *s,int *length)//检测栈长度
{
	if((*s).top==0)
	{
		printf("这是一个空栈\n");
		*length=0;
		return SUCCESS;
	} 
	*length=(*s).top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//入栈
{
	if((*s).top==(*s).size)
	{
		printf("这是一个满栈，无法再入栈\n");
		return ERROR;
	}
   (*s).elem[(*s).top]=data;
   (*s).top++;
   return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//出栈
{
	if((*s).top==0)
	{
		printf("这是一个空栈\n");
		return SUCCESS;
	} 
   *data=(*s).elem[(*s).top-1];
   (*s).top--;
   return SUCCESS;
}










