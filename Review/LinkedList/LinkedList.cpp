#include "LinkedList.h"

Node* CreateNode(int data)
{
	Node* cur = new Node;
	cur->data = data;
	cur->pNext = nullptr;
	return cur;
}

List* CreateList(Node* p_node)
{
	List* list = new List;
	Node* cur = p_node;
	while (cur != nullptr && cur->pNext != nullptr)
		cur = cur->pNext;
	list->p_head = p_node;
	list->p_tail = cur;
	return list;
}

bool AddHead(List*& L, int data)
{
	Node* tmp = CreateNode(data);
	tmp->pNext = L->p_head;
	L->p_head = tmp;
	return true;
}

bool AddTail(List*& L, int data)
{
	Node* tmp = CreateNode(data);
	L->p_tail->pNext = tmp;
	L->p_tail = tmp;
	return true;
}

void RemoveHead(List*& L)
{
	if (L->p_head == nullptr)
		return;
	Node* tmp = L->p_head;
	L->p_head = L->p_head->pNext;
	delete tmp;
}

void RemoveTail(List*& L)
{
	if (L->p_head == nullptr)
		return;
	Node* cur = L->p_head;
	bool check = false;
	while (cur->pNext != nullptr && cur->pNext->pNext != nullptr) {
		cur = cur->pNext;
		check = true;
	}
	delete L->p_tail;
	L->p_tail = cur;
	if (check)
		L->p_tail->pNext = nullptr;
	else {
		L->p_tail = nullptr;
		L->p_head = nullptr;
	}
}

void RemoveAll(List*& L)
{
	Node* cur = L->p_head;
	while (L->p_head != nullptr) {
		L->p_head = L->p_head->pNext;
		delete cur;
		cur = L->p_head;
	}
}

void PrintList(List* L)
{
	Node* cur = L->p_head;
	while (cur != nullptr) {
		std::cout << cur->data << " ";
		cur = cur->pNext;
	}
}

int CountElement(List* L)
{
	Node* cur = L->p_head;
	int count = 0;
	while (cur != nullptr) {
		count++;
		cur = cur->pNext;
	}
	return count;
}

List* ReverseList(List* L)
{
	List* list = new List;
	list->p_head = nullptr;
	list->p_tail = nullptr;
	Node* cur = L->p_head;
	while (cur != nullptr) {
		if (list->p_head == nullptr) {
			list->p_head = new Node;
			list->p_head->data = cur->data;
			list->p_head->pNext = nullptr;
			list->p_tail = list->p_head;
		}
		else {
			Node* tmp = new Node;
			tmp->data = cur->data;
			tmp->pNext = list->p_head;
			list->p_head = tmp;
		}
		cur = cur->pNext;
	}
	return list;
}

bool CheckDuplicate(List* L, int n)
{
	int count = 0;
	Node* cur = L->p_head;
	while (cur != nullptr) {
		if (cur->data == n)
			count++;
		cur = cur->pNext;
	}
	if (count == 1)
		return false;
	return true;
}

void RemoveDuplicate(List*& L)
{
	Node* tmp;
	while (CheckDuplicate(L, L->p_head->data)) {
		tmp = L->p_head;
		L->p_head = L->p_head->pNext;
		delete tmp;
	}
	if (L->p_head == nullptr)
		return;
	Node* cur = L->p_head;
	while (cur->pNext != nullptr) {
		if (CheckDuplicate(L, cur->pNext->data)) {
			tmp = cur->pNext;
			cur->pNext = tmp->pNext;
			delete tmp;
		}
		else {
			cur = cur->pNext;
		}
	}
}

bool RemoveElement(List*& L, int key)
{
	Node* tmp;
	bool check = false;
	while (L->p_head->data == key) {
		tmp = L->p_head;
		L->p_head = L->p_head->pNext;
		delete tmp;
		check = true;
	}

	if (L->p_head == nullptr)
		return check;

	Node* cur = L->p_head;
	while (cur->pNext != nullptr) {
		if (cur->pNext->data == key) {
			tmp = cur->pNext;
			cur->pNext = tmp->pNext;
			delete tmp;
			check = true;
		}
		else {
			cur = cur->pNext;
		}
	}
	return check;
}