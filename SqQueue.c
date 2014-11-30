/*
 * =====================================================================================
 *
 *       Filename:  SqQueue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11%30%2014 10:57:30 AM
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

void InitQueue(SqQueue *queue)
{
	assert(queue);
	queue->front = 0;
	queue->rear = 0;
}

void DestoryQueue(SqQueue *queue)
{
	assert(queue);
	queue->front = 0;
	queue->rear = 0;
}

void ClearQueue(SqQueue *queue)
{
	assert(queue);
	queue->front = 0;
	queue->rear = 0;
}

int QueueEmpty(SqQueue *queue)
{
	assert(queue);
	return QueueLength(queue)==0;
}
int GetHead(SqQueue *queue,ElemType *e)
{
	assert(queue || e);
	if(QueueEmpty(queue))
		return ERROR;
	*e = queue->data[queue->front];
	return SUCCESS;
}

int EnQueue(SqQueue *queue,ElemType *e)
{
	assert(queue || e);
	if((queue->rear+1)%MAXSIZE == queue->front)//队满
		return ERROR;
	queue->data[queue->rear++] = *e;
	return SUCCESS;
}

int DeQueue(SqQueue *queue,ElemType *e)
{
	assert(queue || e);
	if(QueueLength(queue) == 0)
		return ERROR;
	*e = queue->data[queue->front++];
	return SUCCESS;
}

int QueueLength(SqQueue *queue)
{
	assert(queue);
	return (queue->rear-queue->front+MAXSIZE)%MAXSIZE;
}
