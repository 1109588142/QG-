#include "binary_sort_tree.h"
#include "LinkStack.h"
#include "LinkStack.c"
void visit (NodePtr p)
{
    if (p->value != 0x7fffffff)
    {
        printf(" %d ",p->value);
    }	
}
BST_Status BST_init(BinarySortTreePtr a){
    //bst = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    if(a==NULL)
	{
		printf("这是一个空指针");
		return false;
	}
    a->root = (Node*)malloc(sizeof(Node));
    a->root->value = 0x7fffffff;
    a->root->left = NULL;
    a->root->right = NULL;
    return succeed;
}

BST_Status BST_insert(BinarySortTreePtr a, ElemType value){
   if (a->root == NULL || a == NULL)
    {
        printf("树未初始化！\n");
        return false;
    }
    NodePtr p = a->root;
    while (1)
    {
        if (a->root->value == 0x7fffffff)
        {
            a->root->value = value;
            a->root->left = (Node*)malloc(sizeof(Node));
            a->root->right = (Node*)malloc(sizeof(Node));
            a->root->left->value =a->root->right->value = 0x7fffffff;
            break;
        }else{
            if (value < a->root->value)
            {
                a->root = a->root->left;
            }else if (value == a->root->value)
            {
                printf("该值已存在于树中！\n");
                return failed;
            }else if (value > a->root->value)
            {
                a->root = a->root->right;
            }
        }
    }
    a->root = p;
    return succeed;
}

BST_Status BST_delete(BinarySortTreePtr a, ElemType b)
 {
 	if(a==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(a->root->value==0x7fffffff)
	{
		printf("delete is false\n ");
		return false;
	}
	if(a->root->value==b)
	{
		if(a->root->left->value==0x7fffffff&&a->root->right->value==0x7fffffff)
		{
			a->root->value=0x7fffffff;
			printf("delete is successful");
			return true;
		}
		if(a->root->left->value!=0x7fffffff&&a->root->right->value==0x7fffffff)
		{
			a->root=a->root->left;
			printf("delete is successful");
			return true;
		}
		if(a->root->left->value==0x7fffffff&&a->root->right->value!=0x7fffffff)
		{
			a->root=a->root->right;
			printf("delete is successful");
			return true;
		}
		if(a->root->left->value!=0x7fffffff&&a->root->right->value!=0x7fffffff)
		{
			NodePtr temp=(NodePtr)malloc(sizeof(Node));
			temp=a->root->left;
			while(temp->right!=NULL)
			{
				temp=temp->right;
			}
			a->root->value=temp->value;
			temp->value=0x7fffffff;
			/*
			while(a->root->right!=NULL)
			{
				a->root=a->root->right; 
			}
			a->root=NULL; */
			printf("delete is successful");
			return true;
			
		}
	}
	if(b<a->root->value)
	{
		BinarySortTreePtr temp2;
	 	temp2=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp2->root=a->root->left;
		BST_delete( temp2, b);
	}
	if(b>a->root->value)
	{
		BinarySortTreePtr temp3;
	 	temp3=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp3->root=a->root->right;
		BST_delete( temp3, b);
	}
 }

BST_Status BST_search(BinarySortTreePtr a, ElemType b)
 {
 	if(a==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(a->root->value==b)
	{
		printf("what you search is exist\n");
		return true;
	}

	if(b>a->root->value)
	{
		BinarySortTreePtr temp;
	 	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp->root=a->root->right;
	 	if(a->root->right->value==0x7fffffff)
	 	{
	 		return false;
		 }
		BST_search(temp,b);
	}
	if(b<a->root->value)
	{
		BinarySortTreePtr temp2;
	 	temp2=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	 	temp2->root=a->root->left;
	 	if(a->root->left->value==0x7fffffff)
	 	{
	 		return false;
		 }
		BST_search(temp2,b);
	}
	if(a->root->value==0x7fffffff)
	{
		return false;
	}
 }

BST_Status BST_preorderI(BinarySortTreePtr a, void (*visit)(NodePtr b)) //先序 without recursion
 {
 	if(a==NULL)
 	{
 		printf("这是一个空指针\n");
		return false; 
	}
	if(a->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	LinkStack s;
    initLStack(&s);
     pushLStack(&s,a->root);
    while (!isEmptyLStack(&s))
    {
        NodePtr node = popLStack(&s);
        visit(node);
        if (node->right->value!= 0x7fffffff)
        {
            pushLStack(&s,node->right);
        }
        if (node->left->value!= 0x7fffffff)
        {
            pushLStack(&s,node->left);
        }        
    }
    return succeed;

 }

BST_Status BST_preorderR(BinarySortTreePtr a, void (*visit)(NodePtr)) {
    if (a->root == NULL || a == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (a->root->value == 0x7fffffff)
    {
        return false;
    }
    visit(a->root);
    BinarySortTreePtr b = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    b->root = a->root->left;
    BST_preorderR(b, visit);
    b->root = a->root->right;
    BST_preorderR(b, visit);
    return true;
}

BST_Status BST_inorderI(BinarySortTreePtr a, void (*visit)(NodePtr b))//中序 without recursion
 {
 	if(a==NULL)
 	{
 		printf("这是一个空指针\n");
 		return false;
	}
	if(a->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
    NodePtr node = a->root;
    LinkStack s;
    initLStack(&s);
    pushLStack(&s,node);
    while(!isEmptyLStack(&s))
    {
    	if(node->left->value!=0x7fffffff)
    	{
    		pushLStack(&s,node->left);
    		node=node->left;
		}else{
			NodePtr temp=popLStack(&s);
			visit(temp);
			if(temp->right->value=0x7fffffff)
			{
				node=temp->right;
				pushLStack(&s,node);
			}
		}
	}
 }
 
 BST_Status BST_inorderR(BinarySortTreePtr a, void (*visit)(NodePtr b))//中序 with recursion
 {
 	if(a==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	 if (a->root->value == 0x7fffffff)
    {
        return false;
    }
	BinarySortTreePtr temp;
	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	temp->root=a->root->left;
	BST_inorderR(temp,visit);
	visit(a->root);
	temp->root=a->root->right;
	BST_inorderR(temp,visit);
	return true;
 }
 
 BST_Status BST_postorderI(BinarySortTreePtr a, void (*visit)(NodePtr b))//后序 without recursion
 {
 	if(a==NULL)
 	{
 		printf("这是一个空指针\n");
 		return false;
	}
	if(a->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	  LinkStack s1;
    LinkStack s;
    initLStack(&s);
    initLStack(&s1);
    pushLStack(&s,a->root);
     while (!isEmptyLStack(&s))
    {
        NodePtr node = popLStack(&s);
        pushLStack(&s1,node);
        if (node->left->value != 0x7fffffff)
        {
            pushLStack(&s,node->left);
        }
        if (node->right->value!=0x7fffffff)
        {
            pushLStack(&s,node->right);
        }        
    }
     while (!isEmptyLStack(&s1))
    {
        NodePtr node = popLStack(&s1);
        visit(node);
    }
    return true;
 }
 
  BST_Status BST_postorderR(BinarySortTreePtr a, void (*visit)(NodePtr b))//后序 with recursion
 {
 	if(a==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(a->root->value==0x7fffffff)
	{
		return false;
	}
	BinarySortTreePtr temp;
	temp=(BinarySortTreePtr)malloc(sizeof(BinarySortTree));
	temp->root=a->root->left;
 	BST_postorderR(temp,visit);
	temp->root=a->root->right;
 	BST_postorderR(temp,visit);
 	visit(a->root);
 	return true;
 }
 
 BST_Status BST_levelOrder(BinarySortTreePtr a, void (*visit)(NodePtr b))//层序 
 {
 	if(a==NULL)
	{
		printf("这是一个空指针\n");
		return false;
	}
	if(a->root->value==0x7fffffff)
	{
		printf("这是一个空树\n");
		return false;
	}
	 Node* Queue[100] = {NULL};
    Node* left = NULL;
    Node* right = NULL;
    int i = 1,j = 0;
    Queue[0] = a->root;
    while (i > j)
    {
        if (Queue[j]->value != 0x7fffffff)
        {
            visit(Queue[j]);
            left = Queue[j]->left;
            right = Queue[j]->right;
            if (left){Queue[i++] = left;}
            if (right){Queue[i++] = right;}
        }
        j++;
    }
    return succeed;

 }

