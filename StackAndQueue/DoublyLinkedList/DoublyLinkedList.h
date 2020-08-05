#ifndef _DOUBLY_LINKED_LIST_H_
#define _DOUBLY_LINKED_LIST_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* pNext;
	Node* pPrev;
};

struct List {
	Node* pHead;
	Node* pTail;
};

void MenuDoubly(List list);
void Initialize(List& list, int key);
void AddFrontOfList(List& list, int key);
void AddBeforeNode(Node* add, int key);
void AddAfterNode(Node* add, int key);
void AddEndOfList(List& list, int key);
void RemoveFrontOfList(List& list);
void RemoveEndOfList(List& list);
void RemoveFirstValue(List& list, int value);
void PrintList(List list);
void DeleteAll(List& list);

#endif // _DOUBLY_LINKED_LIST_H_
