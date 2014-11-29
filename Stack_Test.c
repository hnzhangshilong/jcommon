/*
 * =====================================================================================
 *
 *       Filename:  Stack_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2014 08:34:00 PM
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

int main()
{
	SqStack stack;
	InitStack(&stack);
	for(int i=1;i<10;++i)
		Push(&stack,&i);
	int data;
	GetTop(&stack,&data);
	printf("--%d\n",data);
	while(!StackEmpty(&stack)){
		int tmpData;
		Pop(&stack,&tmpData);
		printf("%d\n",tmpData);
	}
	return 0;
}

