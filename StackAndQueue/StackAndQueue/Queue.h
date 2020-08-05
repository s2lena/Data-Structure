#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "Stack.h"

struct Queue {
	Node* pHead;
	Node* pTail;
	int size;
	int idx = 0;
};

void QueueMenu(Queue queue);
void Initialize(Queue& queue, int key);
bool Enqueue(int key, Queue& queue);
bool Dequeue(Queue& queue, int& result);
int Count(Queue queue);
bool IsEmpty(Queue queue);
void PrintQueue(Queue queue);
void DeleteAll(Queue& queue);

#endif // _QUEUE_H_
