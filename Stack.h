/*
 * =====================================================================================
 *
 *       Filename:  Stack.h
 *
 *    Description:  顺序存储结构栈
 *
 *        Version:  1.0
 *        Created:  11/29/2014 08:23:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#ifndef GIT_JCOMMON_STACK_H
#define GIT_JCOMMON_STACK_H

#define MAXSIZE 20
typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int top;
}SqStack;

void InitStack(SqStack *s);
void DestoryStack(SqStack *s);
void ClearStack(SqStack *s);
int StackEmpty(SqStack *s);
int GetTop(SqStack *s,ElemType *e);
int Push(SqStack *s,ElemType *e);
int Pop(SqStack *s,ElemType *e);
int StackLength(SqStack *s);

#endif