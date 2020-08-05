#include "Stack.h"

void StackMenu(Stack stack)
{
	bool status = true;
	bool check;
	int choice;
	while (status) {
		system("cls");
		cout << "Stack: ";
		PrintStack(stack);
		cout << endl << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Count elements" << endl;
		cout << "4. Is stack empty" << endl;
		cout << "0. Out program" << endl;
		cout << "Your choice is: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input key: ";
			cin >> choice;
			if (!Push(choice, stack))
				cout << "Failed to push" << endl;
			else
				cout << "Push success" << endl;
			break;
		case 2:
			check = Pop(stack, choice);
			if (check)
				cout << "Result of pop: " << choice << endl;
			else
				cout << "No element to pop" << endl;
			break;
		case 3:
			cout << Count(stack) << endl;
			break;
		case 4:
			if (IsEmpty(stack))
				cout << "Stack is empty" << endl;
			else
				cout << "Stack is not empty" << endl;
			break;
		case 0:
			DeleteAll(stack);
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
void Initialize(Stack& stack, int key)
{
	if (stack.size == 0)
		return;

	stack.pHead = new Node;
	stack.pHead->key = key;
	stack.pHead->pNext = nullptr;
	stack.idx++;
}

bool Push(int key, Stack& stack)
{
	if (stack.idx == stack.size)
		return false;
	Node* tmp = new Node;
	tmp->key = key;
	tmp->pNext = stack.pHead;
	stack.pHead = tmp;
	stack.idx++;
	return true;
}

bool Pop(Stack& stack, int& result)
{
	if (stack.pHead == nullptr)
		return false;
	Node* tmp = stack.pHead;
	stack.pHead = stack.pHead->pNext;
	result = tmp->key;
	delete tmp;
	stack.idx--;
	return true;
}

int Count(Stack stack)
{
	return stack.idx;
}

bool IsEmpty(Stack stack)
{
	if (stack.pHead == nullptr || stack.idx == 0)
		return true;
	return false;
}

void PrintStack(Stack stack)
{
	Node* cur = stack.pHead;
	while (cur != nullptr) {
		cout << cur->key << " ";
		cur = cur->pNext;
	}
}

void DeleteAll(Stack& stack)
{
	Node* cur = stack.pHead;
	while (stack.pHead != nullptr) {
		stack.pHead = stack.pHead->pNext;
		delete cur;
		cur = stack.pHead;
	}
}