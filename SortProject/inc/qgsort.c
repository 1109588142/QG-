#include "qgsort.h"
#include <time.h>
void insertSort(int *a,int n) //插入排序 
{
	if (n < 2)
   {
       return;
   }
   int i; 
    for ( i = 0; i < n - 1; i++)
    {
        int end = i;
        int temp = a[end + 1];
        while (end >= 0 && a[end] > temp)
        {
            a[end + 1] = a[end];
            --end;
        }
        a[end + 1] = temp;
    }
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)//归并排序（合并数组）
{
		int i=begin;
 	int j=mid+1;
 	int t=0;
 	while(i<=mid&&j<=end)
 	{
 		if(*(a+i)<*(a+j))
 		{
 			*(temp+t)=*(a+i);
 			i++;
 			t++;
		 }else {
		 	*(temp+t)=*(a+j);
		 	t++;
		 	j++;
		 }
	 }
	 while(i<=mid)
	 {
	 	*(temp+t)=*(a+i);
	 	i++;
	 	t++;
	 }
	 while(j<=end)
	 {
	 	*(temp+t)=*(a+j);
	 	j++;
	 	t++;
	 }
	 t=0;
	 int tempLeft=begin;
	 while(tempLeft<=end)
	 {
	 	*(a+tempLeft)=*(temp+t);
	 	tempLeft++;
	 	t++;
	 }
 } 
 
 void MergeSort(int *a,int begin,int end,int *temp)//归并排序
 {
 	if(begin<end)
 	{
 		int mid=(begin+end)/2;
 		MergeSort(a,begin,mid,temp);
 		MergeSort(a,mid+1,end,temp);
 		MergeArray(a,begin,mid,end,temp);
	 }
 }
 
 void QuickSort_Recursion(int *a, int begin, int end)//快速排序（递归版）
 {
   int left;
    if(begin < end){
        left = Partition(a,begin,end);
        QuickSort_Recursion(a,begin,left - 1);
        QuickSort_Recursion(a,left + 1,end);
    }else{
        return;
    }
 }
 
 void QuickSort(int *a,int size);//快速排序（非递归版）
 
 int Partition(int *a, int begin, int end)//快速排序（枢轴存放）
 {
  int left = begin;
    int right = end;
    int temp = a[left];
    while (left < right)
    {
        while ((a[right] >= temp) && (left < right))
        {
            right--;
        }
        a[left] = a[right];
        while ((a[left] <= temp) && (left < right))
        {
            left++;
        }
        a[right] = a[left];
    }
    a[left] = temp;
    return left;
 }
 void CountSort(int *a, int size , int max)//计数排序
 {
	 int t[1024];
    int i,j = 0;
    for ( i = 0; i <= max; i++)
    {
        t[i] = 0;
    }
    for ( i = 0; i < size; i++)
    {
        t[a[i]]++;
    }
    for ( i = 0; i <= max; i++)
    {
        while ((t[i]--) > 0)
        {
            a[j++] = i;
        }
    } 
  }
  
  void RadixCountSort(int *a,int size)//基数计数排序
  {
  	int MAXN=1e5;
  	int b[MAXN];
  	int key=1;
  	int i;
  	for(i=0;i<size;i++)
  	{
  		while(key<*(a+i))
  		{
  		  key=key*10;
		}
	}
	int count[10];
	int k;
	for(k=1;k<=key;k*=10)
	{
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
		for(i=0;i<size;i++)
		{
			count[*(a+i)/k%10]++;
		}
		for(i=1;i<10;i++)
		{
			count[i]+=count[i-1];
		}
		for(i=size-1;i>=0;i--)
		{
			int dex=*(a+i)/k%10;
			b[count[dex]-1]=*(a+i);
			count[dex]--;
		}
		for(i=0;i<size;i++)
		{
			*(a+i)=b[i];
		}
	} 

  }
  
void ColorSort(int *a,int size)//颜色排序
{
	 int red = 0,blue = size - 1,temp;
	 int i;
    for ( i = 0; i <= blue; i++)
    {
        if (a[i] == 0)
        {
            temp = a[i];
            a[i] = a[red]; 
            a[red] = temp;
            red++;
        }else if(a[i] == 2){
            temp = a[i];
            a[i] = a[blue]; 
            a[blue] = temp;
            i--;
            blue--;
        }
    }
}

int FindKthMin(int *a,int begin,int end,int k)
{
	 int pos;
    if (k > 0 && k <= end)
    {
        pos = Partition(a,begin,end);
        if (pos - begin == k - 1)
        {
            return a[pos];
        }
        if (pos - begin > k - 1)
        {
            return FindKthMin(a,begin,pos - 1,k);
        }
        return FindKthMin(a,pos + 1,end,k - pos + begin - 1);
    }
    return GetMax(a,end + 1);
}
 
 int GetMax(int *a,int size)
 {
    int i,max;
    max = a[0];
    for ( i = 0; i < size; i++)
    {
        if (a[i] > max)
        {
            max = a[i];
        }
    }
    return max;
}
