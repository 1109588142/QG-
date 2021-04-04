#include"LinkStack.h"
#include<stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//初始化栈
{
	s->top=(StackNode*)malloc(sizeof(StackNode));
	s->count=0;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//判断栈是否为空
{
  if(s->count==0)
  {
  	printf("这是一个空栈");
  	return SUCCESS;
  }
  printf("这不是一个空栈");
  return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)//得到栈顶元素
{
  if(s->count==0)
  {
  	printf("这是一个空栈");
  	return SUCCESS;
  }
  *e=s->top->data;
  return SUCCESS;
}
  
Status clearLStack(LinkStack *s)//清空栈
{
	if(s->count==0)
  {
  	printf("这是一个空栈");
  	return ERROR;
  }
	s->count=0;
	s->top->next=NULL;
	return SUCCESS;
	
}

Status destroyLStack(LinkStack *s)//销毁栈
{
	free(s->top);
	free(s);
	return SUCCESS;
}

Status LStackLength(LinkStack *s,int *length)//检测栈长度
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//入栈
{
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data=data;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}

Status pushLStack2(LinkStack *s,ElemType2 data2)//入栈
{
	StackNode* sn=(StackNode*)malloc(sizeof(StackNode));
	sn->data2=data2;
	sn->next=s->top;
	s->top=sn;
	s->count++;
	return SUCCESS;
}
Status popLStack(LinkStack *s,ElemType *data)//出栈
{
	*data=s->top->data;
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}

Status popLStack2(LinkStack *s,ElemType2 *data2)//出栈
{
	*data2=s->top->data2;
	s->top=s->top->next;
	s->count--;
	return SUCCESS;
}
