#include "DoublyLinkedList.h"

void MenuDoubly(List list)
{

}

void Initialize(List& list, int key)
{
	list.pHead = new Node;
	list.pTail = list.pHead;
	list.pHead->key = key;
	list.pHead->pNext = nullptr;
	list.pHead->pPrev = nullptr;
}

void AddFrontOfList(List& list, int key)
{

}

void AddBeforeNode(Node* add, int key)
{

}

void AddAfterNode(Node* add, int key)
{

}

void AddEndOfList(List& list, int key)
{

}

void RemoveFrontOfList(List& list)
{

}

void RemoveEndOfList(List& list)
{

}

void RemoveFirstValue(List& list, int value)
{

}

void PrintList(List list)
{
	Node* cur = list.pHead;
	while (cur != nullptr) {
		cout << cur->key << " ";
		cur = cur->pNext;
	}
}

void DeleteAll(List& list)
{
	Node* cur = list.pHead;
	while (list.pHead != nullptr) {
		list.pHead = list.pHead->pNext;
		delete cur;
		cur = list.pHead;
	}
}