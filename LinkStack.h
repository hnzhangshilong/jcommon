/*
 * =====================================================================================
 *
 *       Filename:  LinkStack.h
 *
 *    Description:  Stack的链式存储结构
 *
 *        Version:  1.0
 *        Created:  11/29/2014 09:06:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#ifndef GIT_JCOMMON_LINKSTACK_H
#define GIT_JCOMMON_LINKSTACK_H

typedef int ElemType;

typedef struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
	LinkStackPtr top;
	int count;
}LinkStack;

void InitStack(LinkStack *s);
void DestoryStack(LinkStack *s);
void ClearStack(LinkStack *s);
int StackEmpty(LinkStack *s);
int GetTop(LinkStack *s,ElemType *e);
void Push(LinkStack *s,ElemType *e);
int Pop(LinkStack *s,ElemType *e);
int StackLength(LinkStack *s);


#endif

