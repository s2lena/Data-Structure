// NAME: PHAM THI NGOC HA
// ID:19125089
// CLASS: 19CTT1

#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {

	int data;
	cout << "Input first data: ";
	cin >> data;
	List* list = CreateList(CreateNode(data));
	List* reverse = new List;
	reverse->p_head = nullptr;
	reverse->p_tail = nullptr;
	bool status = true;
	while (status) {
		system("cls");
		cout << "List: ";
		PrintList(list);
		cout << endl;
		cout << "1. Add data to the head of list" << endl;
		cout << "2. Add data to the tail of list" << endl;
		cout << "3. Remove one data from head" << endl;
		cout << "4. Remove one data from tail" << endl;
		cout << "5. Remove all list" << endl;
		cout << "6. Count element in list" << endl;
		cout << "7. Reverse list" << endl;
		cout << "8. Remove duplicate in list" << endl;
		cout << "9. Remove specific element" << endl;
		cout << "0. Out program" << endl;
		cout << "Your choice is: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Data: ";
			cin >> data;
			AddHead(list, data);
			break;
		case 2:
			cout << "Data: ";
			cin >> data;
			AddTail(list, data);
			break;
		case 3:
			RemoveHead(list);
			break;
		case 4:
			RemoveTail(list);
			break;
		case 5:
			RemoveAll(list);
			break;
		case 6:
			cout << "Total elements in list: " << CountElement(list) << endl;
			cout << "Input 0 to return menu. ";
			while (data) {
				cin >> data;
			}
			break;
		case 7:
			reverse = ReverseList(list);
			cout << "Reverse list: ";
			PrintList(reverse);
			cout << endl;
			cout << "Input 0 to return menu. ";
			while (data) {
				cin >> data;
			}
			RemoveAll(reverse);
			break;
		case 8:
			RemoveDuplicate(list);
			break;
		case 9:
			cout << "Input a specific element: ";
			cin >> data;
			RemoveElement(list, data);
			break;
		case 0:
			status = false;
			break;
		default:
			break;
		}
	}
	if (list != nullptr)
		RemoveAll(list);
	return 0;
}