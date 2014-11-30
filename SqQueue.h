/*
 * =====================================================================================
 *
 *       Filename:  SqQueue.h
 *
 *    Description:  顺序存储循环队列
 *
 *        Version:  1.0
 *        Created:  11/30/2014 10:57:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  张世龙 (mn), jack_zsl@163.com
 *        Company:  free
 *
 * =====================================================================================
 */

#ifndef GIT_JCOMMON_SQQUEUE_H
#define GIT_JCOMMON_SQQUEUE_H

#define MAXSIZE 200
typedef int ElemType;

typedef struct 
{
	ElemType data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue *queue);
void DestoryQueue(SqQueue *queue);
void ClearQueue(SqQueue *queue);
int QueueEmpty(SqQueue *queue);
int GetHead(SqQueue *queue,ElemType *e);
int EnQueue(SqQueue *queue,ElemType *e);
int DeQueue(SqQueue *queue,ElemType *e);
int QueueLength(SqQueue *queue);

#endif
