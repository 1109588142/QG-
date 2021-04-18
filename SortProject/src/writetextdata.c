#include <stdio.h>
#include <stdlib.h> 
#define testdata1 10000
#define testdata2 50000
#define testdata3 200000
#define testdata4 100000
#define Max 1000
void show();
int main()
{
	int choice;
	FILE*fp;
	show();
	scanf("%d",&choice);
	optionwrite(choice,fp);
	return 0;
}
void show()
{
    printf("\t*请输入对应编号生成测试数据*\t");
    printf("\n\n--------1.生成%d个0~%d的随机数--------\n",testdata1,Max);
    printf("--------2.生成%d个0~%d的随机数--------\n",testdata2,Max);
    printf("--------3.生成%d个0~%d的随机数--------\n",testdata3,Max);    
    printf("请输入你的选择：");
}
void optionwrite(int choice,FILE *fp)
{
	int num;
	switch(choice)
	{
		case 1:{
			fp = fopen("testdata.txt","w");
			int i;
			for(i=0;i<testdata1;i++)
			{
				num=rand_number();
				fprintf(fp,"%d",num);
			}
			fclose(fp);
		 printf("成功生成%d个0~%d的随机数",testdata1,Max);  
			break;
		}
		case 2:{
			fp=fopen("testdata.txt","w");
			int i;
			for(i=0;i<testdata2;i++)
			{
				num=rand_number();
				fprintf(fp,"%d",num);
			}
			fclose(fp);
		 printf("成功生成%d个0~%d的随机数",testdata2,Max);  
			break;
		}
		case 3:{	
		    fp=fopen("testdata.txt","w");
			int i;
			for(i=0;i<testdata3;i++)
			{
				num=rand_number();
				fprintf(fp,"%d",num);
			}
			fclose(fp);
		 printf("成功生成%d个0~%d的随机数",testdata3,Max);  
			
			break;
		}
	}
}

int rand_number()
{
	int num;
	num=rand()%Max;
	return num;
}
