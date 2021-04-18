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
    printf("\n\n\n\t*请输入对应编号*\t");
    printf("\n\n-------1.100 * 100k数据测试--------\n");
    printf("-------2.自定义数据测试--------\n");
    printf("-------3.颜色排序展示-------\n");
    printf("-------4.寻找第几小的数字------\n");
    printf("-------5.退出--------\n\n");
    printf("注：数字为0~1000的随机数，数组定长为100\n\n\n");
    printf("请输入你的选择：");
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
		printf("100 * 100k次排序花费时间：\n");
	}
	if (choice == 2){
        printf("请输入你要测试的次数：");
        scanf("%d",&count);
        printf("自定义数据测试花费时间：\n");         
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
		printf("排序结果\n");
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
		printf("请输入第几小");
		int k;
		scanf("%d\n",&k);
	int brr=FindKthMin(color,0,7, k);
	printf("第%d小的是：%d",k,brr);
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
    printf("插入排序用时：%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        MergeSort(a,0,num-1,a);
        int end = GetTickCount();
        time += end - start;
    }
    printf("归并排序用时：%dms\n",time);
  time = 0;
    for ( i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        QuickSort_Recursion(a,0,num-1);
        int end = GetTickCount();
        time += end - start;
    }
    printf("快速排序(递归版)用时：%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        CountSort(a,num,GetMax(a,100));
        int end = GetTickCount();
        time += end - start;
    }
    printf("计数排序用时：%dms\n",time);
    time = 0;
    for (i = 0; i < count; i++)
    {
        readdata(num,a,fp);
        int start = GetTickCount();
        RadixCountSort(a,num);
        int end = GetTickCount();
        time += end - start;
    }
    printf("基数计数排序用时：%dms\n",time);    
}
