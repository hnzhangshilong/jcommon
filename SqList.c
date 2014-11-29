/*
 * =====================================================================================
 *
 *       Filename:  SqList.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 10:00:51 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#include "Public.h"
#include "SqList.h"

void InitList(SqList *list)
{
	assert(list);
	list->length = 0;
}

int  ListEmpty(SqList *list)
{
	assert(list);
	return list->length == 0;
}

void ClearList(SqList *list)
{
	list->length = 0;
}

int GetElem(SqList *list,int i,ElemType *e)
{
	assert(list && e);
	if(list->length < i)
		return ERROR;
	*e = list->data[i-1];
	return SUCCESS;
}

int  LocateElem(SqList *list,ElemType *e)
{
	assert(list && e);
	for(int i=0;i<list->length;++i){
		if(list->data[i] == *e){
			return i+1;
		}
	}
	return 0;
}

int ListInsert(SqList *list,int i,ElemType *e)
{
	assert(list && e);
	if(list->length == MAXSIZE ||  i < 1)
		return ERROR;
	for(int index=list->length-1;index>=i-1;--index)
		list->data[index+1] = list->data[index]; 
	list->data[i-1] = *e;
	list->length++;
	return SUCCESS;
}

int ListDelete(SqList *list,int i,ElemType *e)
{
	assert(list && e);
	if(list->length == MAXSIZE ||  i < 1)
		return ERROR;
	*e = list->data[i-1];
	for(int index=i;index<list->length;++index)
		list->data[index-1] = list->data[index];
	list->length--;
	return SUCCESS;
}

int ListLength(SqList *list)
{
	assert(list);
	return list->length;
}
