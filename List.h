/*
 * =====================================================================================
 *
 *       Filename:  List.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 03:14:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#ifndef GIT_JCOMMON_LIST_H
#define GIT_JCOMMON_LIST_H

typedef int ElemType;

typedef struct Node{
	ElemType data;
	struct Node *next;
}Node;

typedef struct Node *LinkList; 

void InitList(LinkList *list);
int  ListEmpty(LinkList list);
int ClearList(LinkList list);
int GetElem(LinkList list,int i,ElemType *e);
int  LocateElem(LinkList list,ElemType *e);
int ListInsert(LinkList list,int i,ElemType *e);
int ListDelete(LinkList list,int i,ElemType *e);
int ListLength(LinkList list);

 #endif