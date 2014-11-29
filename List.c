/*
 * =====================================================================================
 *
 *       Filename:  List.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 03:14:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#include "Public.h"
#include "List.h"

void InitList(LinkList *list)
{
	*list = (LinkList)malloc(sizeof(struct Node));
	assert(*list);
	(*list)->next = NULL;
	(*list)->data = 0;
}

int ListEmpty(LinkList list)
{
	assert(list);
	return list->data == 0;
}

int ClearList(LinkList list)
{
	assert(list);
	Node *NodePtr = list->next;
	while(NodePtr){
		Node *tmpNodePtr = NodePtr->next;
		free(NodePtr);
		NodePtr = tmpNodePtr;
		list->data--;
	}
	if(list->data != 0)
		return ERROR;
	list->next = NULL;
	return SUCCESS;
}

int GetElem(LinkList list,int i,ElemType *e)
{
	assert(list && e);
	if(i<1 || i>list->data)
		return ERROR;
	Node *foundNodePtr = list->next;
	while(--i)
		foundNodePtr = foundNodePtr->next;
	*e = foundNodePtr->data;
	return SUCCESS;
}

int  LocateElem(LinkList list,ElemType *e)
{
	assert(list && e);
	Node *nodePtr = list->next;
	int pos = 0;
	while(nodePtr){
		++pos;
		if(nodePtr->data == *e)
			break;
		nodePtr = nodePtr->next;
	}
	return nodePtr!=NULL?pos:0;
}

int ListInsert(LinkList list,int i,ElemType *e)
{
	assert(list && e);
	if(i<1)
		return ERROR;
	if(i>list->data)
		i = list->data+1; //插入到最后
	Node *nodePtr = list;
	while(--i)
		nodePtr = nodePtr->next;
	Node *newNodePtr = (Node*)malloc(sizeof(struct Node));
	newNodePtr->data = *e;
	Node *tmpNodePtr = nodePtr->next;
	nodePtr->next = newNodePtr;
	newNodePtr->next = tmpNodePtr;
	list->data++;
	return SUCCESS;
}

int ListDelete(LinkList list,int i,ElemType *e)
{
	assert(list && e);
	if(i<1 || i>list->data)
		return ERROR;
	Node *nodePtr = list;
	Node *parentNode = list;
	while(i--){
		parentNode = nodePtr;
		nodePtr = nodePtr->next;
	}
	*e = nodePtr->data;
	parentNode->next = nodePtr->next;
	free(nodePtr);
	list->data--;
	return SUCCESS;
}

int ListLength(LinkList list)
{
	assert(list);
	return list->data;
}