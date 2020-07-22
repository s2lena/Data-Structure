#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>

struct Node {
	int data;
	Node* pNext;
};

struct List {
	Node* p_head;
	Node* p_tail;
};

Node* CreateNode(int data);
List* CreateList(Node* p_node);
bool AddHead(List*& L, int data);
bool AddTail(List*& L, int data);
void RemoveHead(List*& L);
void RemoveTail(List*& L);
void RemoveAll(List*& L);
void PrintList(List* L);
int CountElement(List* L);
List* ReverseList(List* L);
bool CheckDuplicate(List* L, int n);
void RemoveDuplicate(List*& L);
bool RemoveElement(List*& L, int key);

#endif // _LINKEDLIST_H_
