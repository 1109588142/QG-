#include "duLinkedList.h"
#include <stdlib.h>
#include<stdio.h>
void visit(ElemType e){
	int i=1;
    printf("%d->",e);
}
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList temp;
	temp = (DuLinkedList)malloc(sizeof(DuLNode));
	if (temp == NULL)
	{
		printf("分配内存失败");
		return ERROR;
	}
	temp->prior = NULL;
	temp->next = NULL;
	L = &temp;
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList temp;
	if (*L != NULL)
	{
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	DuLinkedList temp;
	temp = p->prior;
	temp->next = q;
	q->prior = temp;
	q->next = p;
	p->prior = q;
	printf("112");
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	DuLinkedList temp;
	temp = p->next;
	p->next = q;
	q->prior = p;
	q->next = temp;
	temp->prior = q;
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLinkedList temp,aemp;
	if (p->next == NULL)
	{
		printf("要删除的节点不存在");
	   return ERROR;
	}
/*	temp = p->next;
	temp->prior=NULL;
	aemp = temp->next;
	p->next = aemp;
	aemp->prior = p;
	*e = temp->data;
	free(temp);
	return SUCCESS; */
	DuLNode* t = p->next;
    *e = t->data;
    p->next = t->next;
    t->next->prior = p;
    free(t);
    return SUCCESS;
	
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList a;
	a = L;
	int i=1;
	while (a->data!= 00)
	{
		printf("第%d个数据：%d\n",i,a->data);
		i++;
		a = a->next;
	}

}
