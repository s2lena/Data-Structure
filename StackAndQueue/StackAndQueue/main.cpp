#include "Stack.h"
#include "Queue.h";

int main() {
	Stack stack;
	Queue queue;
	int choice;
	bool status = true;
	while (status) {
		system("cls");
		cout << "1. Stack" << endl;
		cout << "2. Queue" << endl;
		cout << "0. Out program" << endl;
		cout << "Your choice is: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Input size: ";
			cin >> stack.size;
			cout << "Input first element" << endl;
			cin >> choice;
			Initialize(stack, choice);
			StackMenu(stack);
			break;
		case 2:
			cout << "Input size: ";
			cin >> queue.size;
			cout << "Input first element" << endl;
			cin >> choice;
			Initialize(queue, choice);
			QueueMenu(queue);
			break;
		case 0:
			status = false;
			break;
		default:
			cout << "No update" << endl;
			break;
		}
	}
	return 0;
}