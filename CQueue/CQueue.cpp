#include<stdio.h>
#include<stdlib.h>
#include "CQueue.h"

void QInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue* pq)
{
	if (pq->front == pq->rear) return TRUE;
	else return FALSE;
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;

	else return pos + 1;
}

void Enqueue(Queue* pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue is full!\n");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->QueArr[pq->rear] = data;
}

Data Dequeue(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is Empty! \n");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->QueArr[pq->front];
}

Data QPeek(Queue* pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue is Empty! \n");
		exit(-1);
	}
	return pq->QueArr[NextPosIdx(pq->front)];
}