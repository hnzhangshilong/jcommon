/*
 * =====================================================================================
 *
 *       Filename:  SqQueue_Test.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 10:57:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#include "Public.h"
#include "SqQueue.h"

int main()
{
	SqQueue queue;
	InitQueue(&queue);
	for(int i=1;i<203;++i)
		printf("%d \n",EnQueue(&queue,&i) );
	
	
	int len = QueueLength(&queue);
	int tmpData;
	for(int i=0;i<len;++i){
		printf("%d \n",DeQueue(&queue,&tmpData) );
		
		printf("len=%d data=%d\n",QueueLength(&queue),tmpData);
	}
	printf("\n");
	return 0;
}