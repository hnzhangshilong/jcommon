/*
 * =====================================================================================
 *
 *       Filename:  LinkQueue.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/30/2014 12:31:51 PM
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

void InitQueue(LinkQueue *queue)
{
	assert(queue);
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;
}
void DestoryQueue(LinkQueue *queue)
{
	assert(queue);
	QNode *nodePtr = queue->front;
	while(nodePtr){
		QNode *tmpNodePtr = nodePtr->next;
		free(nodePtr);
		nodePtr = tmpNodePtr;
	}
	queue->count = 0;
	queue->front = NULL;
	queue->rear = NULL;
}

void ClearQueue(LinkQueue *queue);

int QueueEmpty(LinkQueue *queue)
{
	assert(queue);
	return queue->count == 0;
}

int GetHead(LinkQueue *queue,ElemType *e)
{
	assert(queue || e);
	if(queue->count == 0)
		return ERROR;
	*e = queue->front->data;
	return SUCCESS;
}

int EnQueue(LinkQueue *queue,ElemType *e)
{
	assert(queue || e);
	QNode *newNodePtr = (QNode*)malloc(sizeof(QNode));
	newNodePtr->next = NULL;
	newNodePtr->data = *e;
	if(queue->count == 0){
		queue->front = queue->rear = newNodePtr;
	}else{
		queue->rear->next = newNodePtr;
		queue->rear = newNodePtr;
	}
	queue->count++;
	return SUCCESS;
}

int DeQueue(LinkQueue *queue,ElemType *e)
{
	assert(queue || e);
	if(queue->count == 0)
		return ERROR;
	*e = queue->front->data;
	QNode *tmpNodePtr = queue->front->next;
	free(queue->front);
	queue->front = tmpNodePtr;
	queue->count--;
	return SUCCESS;
}

int QueueLength(LinkQueue *queue)
{
	assert(queue);
	return queue->count;
}
