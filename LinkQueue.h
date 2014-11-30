/*
 * =====================================================================================
 *
 *       Filename:  LinkQueue.h
 *
 *    Description:  队列的链式存储实现
 *
 *        Version:  1.0
 *        Created:  11/30/2014 12:31:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#ifndef GIT_JCOMMON_LINKQUEUE_H
#define GIT_JCOMMON_LINKQUEUE_H

typedef int ElemType;

typedef struct QNode
{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr;

typedef struct 
{
	int count;
	QNode *front,*rear;
} LinkQueue;

void InitQueue(LinkQueue *queue);
void DestoryQueue(LinkQueue *queue);
void ClearQueue(LinkQueue *queue);
int QueueEmpty(LinkQueue *queue);
int GetHead(LinkQueue *queue,ElemType *e);
int EnQueue(LinkQueue *queue,ElemType *e);
int DeQueue(LinkQueue *queue,ElemType *e);
int QueueLength(LinkQueue *queue);

#endif
