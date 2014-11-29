/*
 * =====================================================================================
 *
 *       Filename:  Stack.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 08:23:30 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#include "Public.h"
#include "Stack.h"

void InitStack(SqStack *s)
{
	assert(s);
	s->top = -1;
}

void DestoryStack(SqStack *s)
{
	assert(s);
	s->top = -1;
}

void ClearStack(SqStack *s)
{
	assert(s);
	s->top = -1;
}

int StackEmpty(SqStack *s)
{
	assert(s);
	return s->top==-1;
}

int GetTop(SqStack *s,ElemType *e)
{
	assert(s || e);
	if(s->top == -1)
		return ERROR;
	*e = s->data[s->top];
	return SUCCESS;
}

int Push(SqStack *s,ElemType *e)
{
	assert(s || e);
	if(s->top >= MAXSIZE-1)
		return ERROR;
	s->top++;
	s->data[s->top] = *e;
	return SUCCESS;
}

int Pop(SqStack *s,ElemType *e)
{
	assert(s || e);
	if(s->top == -1)
		return ERROR;
	*e = s->data[s->top--];
	return SUCCESS;
}

int StackLength(SqStack *s)
{
	assert(s);
	return s->top+1;
}
