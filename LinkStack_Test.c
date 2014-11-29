/*
 * =====================================================================================
 *
 *       Filename:  LinkStack_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 09:06:34 PM
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

int main()
{
	LinkStack stack;
	InitStack(&stack);
	for(int i=1;i<1000000;++i)
		Push(&stack,&i);
	
	int tmpData;
	int len = StackLength(&stack);
	for(int i=0;i<len;++i){
		Pop(&stack,&tmpData);
		printf("%d ",tmpData);
	}
	printf("\n");
	return 0;
}