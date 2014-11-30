/*
 * =====================================================================================
 *
 *       Filename:  LinkQueue_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 12:31:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */


#include "Public.h"
#include "LinkQueue.h"

int main()
{
	LinkQueue queue;
	InitQueue(&queue);
	for(int i=1;i<1000000;++i)
		EnQueue(&queue,&i);
	
	int len = QueueLength(&queue);
	int tmpData;
	for(int i=0;i<len;++i){
		DeQueue(&queue,&tmpData);
		printf("%d ",tmpData);
	}
	DestoryQueue(&queue);
	printf("\n");
	return 0;
}
