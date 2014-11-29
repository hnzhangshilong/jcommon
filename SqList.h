/*
 * =====================================================================================
 *
 *       Filename:  SqList.h
 *
 *    Description:  顺序存储线性表
 *
 *        Version:  1.0
 *        Created:  11/29/2014 10:00:45 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#ifndef GIT_JCOMMON_SQLIST_H
#define GIT_JCOMMON_SQLIST_H

#define MAXSIZE 20
typedef int ElemType;

typedef struct{
	ElemType data[MAXSIZE];
	int length;
}SqList;

void InitList(SqList *list);
int  ListEmpty(SqList *list);
void ClearList(SqList *list);
int GetElem(SqList *list,int i,ElemType *e);
int  LocateElem(SqList *list,ElemType *e);
int ListInsert(SqList *list,int i,ElemType *e);
int ListDelete(SqList *list,int i,ElemType *e);
int ListLength(SqList *list);

 #endif


