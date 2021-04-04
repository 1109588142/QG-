#include<stdio.h>
#include <stdlib.h>
#include"LinkStack.h"
#include"LinkStack.C"
LinkStack *s;
LinkStack *s2;
int compare(char a,char b);
	
int q=1;
int main()
{
	s=(LinkStack *)malloc(sizeof(LinkStack));
	s2=(LinkStack *)malloc(sizeof(LinkStack));
		ElemType *data3;
		ElemType *data4;
		ElemType2*data5;
		ElemType2*undata;
		data3=(ElemType *)malloc(sizeof(ElemType));
		data4=(ElemType *)malloc(sizeof(ElemType));
		data5=(ElemType2 *)malloc(sizeof(ElemType2));
		undata=(ElemType2 *)malloc(sizeof(ElemType2));
	initLStack(s);
	initLStack(s2);
	char a[100]={"gdut"};
	int i;
		double math;
  printf("------------这是一个计算器（不支持多位数）-------------\n");
  while(1){
  printf("请输入要计算的式子\n");
  scanf("%s",a);
	 i=0;
	char k;
	k='0';
	double temp2;
	for(i=0;a[i]!='\0';i++)
	{
	    double temp;
		if(a[i]>='0'&&a[i]<='9')
		{
		
			math=(double)(a[i]-'0');
			pushLStack(s,math);
			continue ;
		}
		if(a[i]=='(')
		{
			pushLStack2(s2,a[i]);
			for(;a[i]!='\0';i++)
			{  
			if(a[i]==')')
			{
				break;
			}
			if(a[i]>='0'&&a[i]<='9')
		    {
			math=(a[i]-'0');
			pushLStack(s,math);
			continue ;
	     	}
	     	if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		   {
			if(a[i-2]=='(')
			{
				pushLStack2(s2,a[i]);
				continue ;
			}
			if(compare(a[i],s2->top->data2)==1)
			{
				pushLStack2(s2,a[i]);
				continue;
			}
			if(compare(a[i],s2->top->data2)==0)
			{
			   	popLStack2(s2,data5);
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			if(compare(a[i],s2->top->data2)==-1)
			{
				popLStack2(s2,data5);
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			
		}
			switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data3+*data4;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data4-*data3;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
	     	
			}
			
			while(s2->top->data2!='(')
	{
		popLStack2(s2,data5);
		k=*data5;
			switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)+(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)-(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}	
		}
		popLStack2(s2,undata);
		continue;
	}
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/')
		{
			if(s2->count==0)
			{
				pushLStack2(s2,a[i]);
				continue ;
			}
			if(compare(a[i],s2->top->data2)==1)
			{
				pushLStack2(s2,a[i]);
				continue;
			}
			if(compare(a[i],s2->top->data2)==0)
			{
			   	popLStack2(s2,data5);
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			if(compare(a[i],s2->top->data2)==-1)
			{
				popLStack2(s2,data5);
				k=*data5;
				pushLStack2(s2,a[i]);
			}
			
		}
		
		switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data3+*data4;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=*data4-*data3;
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
		k='0';
	}
	
	while(s2->count!=0)
	{
		popLStack2(s2,data5);
		k=*data5;
			switch(k)
		{
			case '+':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)+(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '-':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)-(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '*':{
				if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data3)*(*data4);
					pushLStack(s,temp2);
					
				}
				break;
			}
			case '/':{
					if(s->count>=2)
				{
					popLStack(s,data3);
					popLStack(s,data4);
					temp2=(*data4)/(*data3);
					pushLStack(s,temp2);
					
				}
				break;
			}
			default:
				break;
		}
	k='0';
		
		
		
	} 

  double finalmath;
	ElemType *final1;
	final1=(ElemType *)malloc(sizeof(ElemType));
	popLStack(s,final1);
	finalmath=*final1;
	printf("计算结果是%f\n",finalmath);
	q=0;
	printf("输入1可再次进行计算\n");
	printf("输入0退出\n");
	scanf("%d",&q);
	if(q==0)
	{
		break;
	}
	
}

return 0;	
}

int compare(char a,char b)
{
	if((a=='*'||a=='/')&&(b=='*'||b=='/'))
	{
		return 0;
	}
		if((a=='+'||a=='-')&&(b=='+'||b=='-'))
	{
		return 0;
	}
		if((a=='*'||a=='/')&&(b=='-'||b=='+'))
	{
		return 1;
	}
		if((a=='-'||a=='+')&&(b=='*'||b=='/'))
	{
		return -1;
	}
	
}
