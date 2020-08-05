#include "Queue.h"

void QueueMenu(Queue queue)
{
	bool status = true;
	bool check;
	int choice;
	while (status) {
		system("cls");
		cout << "Queue: ";
		PrintQueue(queue);
		cout << endl << "1. Enqueue" << endl;
		cout << "2. Dequeue" << endl;
		cout << "3. Count elements" << endl;
		cout << "4. Is Queue empty" << endl;
		cout << "0. Out program" << endl;
		cout << "Your choice is: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input key: ";
			cin >> choice;
			if (!Enqueue(choice, queue))
				cout << "Failed to Enqueue" << endl;
			else
				cout << "Enqueue success" << endl;
			break;
		case 2:
			check = Dequeue(queue, choice);
			if (check)
				cout << "Result of dequeue: " << choice << endl;
			else
				cout << "No element to dequeue" << endl;
			break;
		case 3:
			cout << Count(queue) << endl;
			break;
		case 4:
			if (IsEmpty(queue))
				cout << "Queue is empty" << endl;
			else
				cout << "Queue is not empty" << endl;
			break;
		case 0:
			DeleteAll(queue);
			status = false;
			break;
		default:
			break;
		}
		int point = 1;
		while (point) {
			cout << "Input 0 to back!" << endl;
			cin >> point;
		}
	}
}

void Initialize(Queue& queue, int key)
{
	queue.pHead = new Node;
	queue.pTail = queue.pHead;
	queue.pHead->key = key;
	queue.pHead->pNext = nullptr;
	queue.pTail->pNext = nullptr;
	queue.idx++;
}

bool Enqueue(int key, Queue& queue)
{
	if (queue.idx == queue.size)
		return false;
	queue.pTail->pNext = new Node;
	queue.pTail = queue.pTail->pNext;
	queue.pTail->key = key;
	queue.pTail->pNext = nullptr;
	queue.idx++;
	return true;
}

bool Dequeue(Queue& queue, int& result)
{
	if (queue.idx == 0)
		return false;
	Node* tmp = queue.pHead;
	queue.pHead = queue.pHead->pNext;
	result = tmp->key;
	delete tmp;
	queue.idx--;
	return true;
}

int Count(Queue queue)
{
	return queue.idx;
}

bool IsEmpty(Queue queue)
{
	if (queue.pHead == nullptr || queue.idx == 0)
		return true;
	return false;
}

void PrintQueue(Queue queue)
{
	Node* cur = queue.pHead;
	while (cur != nullptr) {
		cout << cur->key << " ";
		cur = cur->pNext;
	}
}

void DeleteAll(Queue& queue)
{
	Node* cur = queue.pHead;
	while (queue.pHead != nullptr) {
		queue.pHead = queue.pHead->pNext;
		delete cur;
		cur = queue.pHead;
	}
}