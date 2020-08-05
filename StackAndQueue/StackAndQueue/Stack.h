#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* pNext;
};

struct Stack {
	Node* pHead;
	int size;
	int idx = 0;
};

void StackMenu(Stack stack);
void Initialize(Stack& stack, int key);
bool Push(int key, Stack& stack);
bool Pop(Stack& stack, int& result);
int Count(Stack stack);
bool IsEmpty(Stack stack);
void PrintStack(Stack stack);
void DeleteAll(Stack& stack);

#endif // _STACK_H_
