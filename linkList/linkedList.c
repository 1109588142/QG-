#include "linkedList.h"
#include <stdlib.h>
#include<stdio.h>

void visit(ElemType e){
	int i=1;
    printf("%d->",e);
}


/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LinkedList leap;
	leap = (LinkedList)malloc(sizeof(LNode));
	if(leap==NULL)
	{
		printf("分配存储空间失败");
		return ERROR;
	}
	leap->next = NULL;
	*L = leap;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList leap;
	leap = *L;
	while (*L != NULL)
	{
		leap = *L;
		*L = (*L)->next;
		free(leap);
		
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	/*LinkedList a;
	a = p->next;
	p->next = q;
	q->next = a;*/
	q->next = p->next;
    p->next = q;
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	 if (!p) 
    {
        printf("指定节点不存在！");
        return ERROR; 
    }
    if (!(p->next)) 
    { 
        printf("该节点已是最后一个节点！"); 
        return ERROR; 
    }
    LNode *t = p->next;
    e = &(t->data);
    p->next = t->next;
    free(t);
    return SUCCESS;

}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L,void (*visit)(ElemType e)) {
	LinkedList a;
	a = L;
	int i=1;
	while (a->data!= 00)
	{
		printf("第%d个数据：%d\n",i,a->data);
		i++;
		a = a->next;
	}
}

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList a;
	a = L;
	while (a != NULL)
	{
		if (a->data == e)
		{
			return SUCCESS;
		}
		a = a->next;
	
	}
	if (a == NULL)
	{ 
		return ERROR;
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p1;
	LinkedList p2;
	LinkedList nex;
	p1 = *L;
	while (p1 != NULL)
	{
		nex = p1->next;
	
		if (p1 == *L)
		{
			p1->next = NULL;
		}
		else p1->next = p2;
		if(nex->data==00)
		{
			L=&p1;
			break;
		}
		p2 = p1;
		p1 = nex;
	}
 	*L = p2;
	return SUCCESS;

}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList p1, p2;
	p1 = L;
	p2 = L;
	if (L == NULL)
	{
		printf("该链表不存在");
		return ERROR;
	}
	while (p1->next != NULL && p1->next->next != NULL && p2->next != NULL)
	{
		p1 = p1->next->next;
		p2 = p2->next;
		if (p1 == p2)
		{
			return SUCCESS;
		}
	}

}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
	LinkedList p1, p2, p3, p4;
	int n = 0;
	p3 = p1 = *L;
	while (p1->next!=NULL)
	{
		p2 = p1->next;
		p1->next = p2->next;
		p2->next = p1;
		if (++n == 1) {
			p3 = p2;
		}
		else {
			p4->next = p2;
		}
		p4 = p1;
		p1 = p1->next;
		if (p1!=NULL)break;
	}
	return p3;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
	LinkedList p1, p2;
	p1 = p2 = *L;
	while (1)
	{
	//	p1 = p1->next;
		p2 = p2->next->next;
		if (p2->next == NULL || p2->next->next == NULL||p2->data==00||p2->next->data==00)
		{
			return p1;
		}else p1 = p1->next;
	}
}

