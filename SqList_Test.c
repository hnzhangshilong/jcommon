/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 10:22:34 AM
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

int main()
{
	SqList list;
	InitList(&list);
	for(int i=1;i<10;++i)
		ListInsert(&list,i,&i);
	for(int i=1;i<=list.length;++i){
		int tmp ;
		GetElem(&list,i,&tmp);
		printf("第%d个元素是%d\n",i,tmp);
	}
	int ret;
	ListDelete(&list,2,&ret);
	for(int i=1;i<=list.length;++i){
		int tmp ;
		GetElem(&list,i,&tmp);
		printf("第%d个元素是%d\n",i,tmp);
	}
	return 0;
}
