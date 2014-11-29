/*
 * =====================================================================================
 *
 *       Filename:  LinkStack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 09:06:28 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */
#include "Public.h"
#include "LinkStack.h"

void InitStack(LinkStack *s)
{
	assert(s);
	s->count = 0;
	s->top = NULL;
}

void DestoryStack(LinkStack *s)
{
	assert(s);
	StackNode *stackPtr = s->top;
	while(stackPtr){
		StackNode *tmpStackPtr = stackPtr->next;
		free(stackPtr);
		stackPtr = tmpStackPtr;
	}
	s->top = NULL;
	s->count = 0;
}

void ClearStack(LinkStack *s);

int StackEmpty(LinkStack *s)
{
	assert(s);
	return s->count == 0;
}

int GetTop(LinkStack *s,ElemType *e)
{
	if(s->count == 0)
		return ERROR;
	*e = s->top->data;
	return SUCCESS;
}

void Push(LinkStack *s,ElemType *e)
{
	assert(s || e);
	StackNode *nodePtr = (StackNode*)malloc(sizeof(StackNode));
	assert(nodePtr);
	nodePtr->data = *e;
	nodePtr->next = s->top;
	s->top = nodePtr;
	s->count++;
}

int Pop(LinkStack *s,ElemType *e)
{
	assert(s || e);
	if(s->count == 0)
		return ERROR;
	*e = s->top->data;
	StackNode *nodePtr = s->top;
	s->top = s->top->next;
	s->count--;
	free(nodePtr);
	return SUCCESS;
}

int StackLength(LinkStack *s)
{
	assert(s);
	return s->count;
}

