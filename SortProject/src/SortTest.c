#include "qgsort.h"
#include "qgsort.c"
#include<stdio.h>
#include <windows.h>
#include <time.h>
void temp();
void readdata(int num,int *a,FILE *fp);
void testtime(int choice);
int main()
{
	int choice=0;
     do{
        temp();
        scanf("%d",&choice);
        printf("\n\n");
        testtime(choice);
    } while (choice != 5);
	return 0;
 } 
 
 void temp()
 {
    printf("\n\n\n\t*�������Ӧ���*\t");
    printf("\n\n-------1.100 * 100k���ݲ���--------\n");
    printf("-------2.�Զ������ݲ���--------\n");
    printf("-------3.��ɫ����չʾ-------\n");
    printf("-------4.Ѱ�ҵڼ�С������------\n");
    printf("-------5.�˳�--------\n\n");
    printf("ע������Ϊ0~1000������������鶨��Ϊ100\n\n\n");
    printf("���������ѡ��");
 }
 
 void readdata(int num,int *a,FILE *fp)
 {
    fp = fopen("testdata.txt","r");
    if (fp == NULL)
    {
        printf("file is not exsits!\n");
    }
    int j;
    for (j = 0; j < num; j++)
    {
        fscanf(fp,"%d ",&a[j]);
    }
    fclose(fp);
}

void testtime(int choice)
{
	int num=100;
	int a[100],count;
	count=1000;
	if(choice==1)
	{
		printf("100 * 100k�����򻨷�ʱ�䣺\n");
	}
	if (choice == 2){
        printf("��������Ҫ���ԵĴ�����");
        scanf("%d",&count);
        printf("�Զ������ݲ��Ի���ʱ�䣺\n");         
    }
    if(choice == 5){
        exit(0);
    }
    if(choice==3)
    {
    	int color[8]={1,2,0,0,2,1,2,0};
    	int i;
    	for(i=0;i<8;i++)
    	{
    		printf("%d ",color[i]);
		}
		ColorSort(color,8);
		printf("������\n");
		for(i=0;i<8;i++)
    	{
    		printf("%d ",color[i]);
		}
		exit(0);
	}
	if(choice==4)
	{
		int color[8]={2,5,6,2,8,2,3,1};
		int i;
		for(i=0;i<8;i++)
    	{
    		printf("%d ",color[i]);
		}
		printf("������ڼ�С");
		int k;
		scanf("%d\n",&k);
	int brr=FindKthMin(color,0,7, k);
	printf("��%dС���ǣ�%d",k,brr);
		exit(0);
	}
     FILE *fp;
    int time = 0;
    int i=0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        insertSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("����������ʱ��%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        MergeSort(a,0,num-1,a);
        int end = GetTickCount();
        time += end - start;
    }
    printf("�鲢������ʱ��%dms\n",time);
  time = 0;
    for ( i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        QuickSort_Recursion(a,0,num-1);
        int end = GetTickCount();
        time += end - start;
    }
    printf("��������(�ݹ��)��ʱ��%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        CountSort(a,num,GetMax(a,100));
        int end = GetTickCount();
        time += end - start;
    }
    printf("����������ʱ��%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        RadixCountSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("��������������ʱ��%dms\n",time);    
}
