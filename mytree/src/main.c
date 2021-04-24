#include "binary_sort_tree.h"
#include "binary_sort_tree.c"
#include <windows.h>

BinarySortTree a;

void show();
int main()
{
	int choice=0;
	 ElemType value = 0;
    do
    {
        show();
        scanf("%d",&choice);
        system("cls");
        switch (choice)
        {
            case 1:
            {
                if(BST_init(&a)){
                    printf("树初始化成功！\n");
                }
                break;
            }
            case 2:
            {
                printf("请输入一个整数：");
                scanf("%d",&value);
                if (BST_insert(&a,value))
                {
                    printf("插入成功！\n");
                }else{
                    printf("插入失败！\n");
                }
                break;
            }
            case 3:
            {
               printf("请输入要删除的数字: ");
               scanf("%d",&value);
               BST_delete(&a,value);
                break;
            }
            case 4:
            {
               printf("请输入要查找的数字：");
               scanf("%d",&value);
               if(BST_search(&a,value)==false)
               {
               	printf("What you're looking for doesn't exist\n");
			   }
                break;
            }
            case 5:
            {
                printf("递归前序遍历:");
                if (!BST_preorderR(&a,visit))
                {
                    printf("遍历失败");
                }
                break;
            }
            case 6:
            {
               printf("迭代前序遍历:");
               BST_preorderI(&a,visit);
                break;
            }
            case 7:
            {
            	printf("递归中序遍历:");
               BST_inorderR(&a,visit);
                break;
            }
            case 8:
            {
               printf("迭代中序遍历:");
               BST_inorderI(&a,visit);
                break;
            }
            case 9:
            {
               printf("递归后序遍历:");
               BST_postorderR(&a,visit);
                break;
            }
            case 10:
            {
            	printf("迭代后序遍历:");
            	BST_postorderI(&a,visit);
               break;
            }
            case 11:
            {
               printf("层序遍历:");
               BST_levelOrder(&a,visit);
                break;
            }
            case 12:
            {
                break;
            }                                                                          
            default:
            {
                printf("请重新输入数字!(1-12)\n");
                break;
            }
        }
    } while (choice != 12);
    return 0;

}

void show(){
    printf("\n\n\n二叉查找树ADT\n\n");
    printf("1.初始化树\n");
    printf("2.插入数字\n");
    printf("3.删除数字\n");
    printf("4.查找数字\n");
    printf("5.递归前序遍历\n");
    printf("6.迭代前序遍历\n");
    printf("7.递归中序遍历\n");
    printf("8.迭代中序遍历\n");
    printf("9.递归后序遍历\n");
    printf("10.迭代后序遍历\n");
    printf("11.层序遍历\n");
    printf("12.退出程序\n");
    printf("请直接输入数字进行对应操作\n");
}

