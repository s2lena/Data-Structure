#include "Function.h"

int main() {
	bool status = true, stop = true;
	Node* pRoot, * search;
	int choice, n;
	cout << "Create first node of tree, input key: ";
	cin >> n;
	pRoot = CreateNode(n);
	while (status) {
		system("cls");
		cout << "The tree: " << endl;
		LevelOrder(pRoot);
		cout << "1. Pre-order Traversal" << endl;
		cout << "2. In-order Traversal" << endl;
		cout << "3. Post-order Traversal" << endl;
		cout << "4. Level-order Traversal" << endl;
		cout << "5. Search a value" << endl;
		cout << "6. Insert a node" << endl;
		cout << "7. Remove a node" << endl;
		cout << "8. Calculate height of tree" << endl;
		cout << "9. Calculate the number of node of tree" << endl;
		cout << "10. Calculate the level of a node" << endl;
		cout << "11. Calculate the number of leaves of tree" << endl;
		cout << "12. Calculate the number of node which less than a value" << endl;
		cout << "13. Calculate the number of node which greater than a value" << endl;
		cout << "14. Is it a Binary Search Tree" << endl;
		cout << "0. Out program" << endl;
		cout << "Your choice is: ";
		cin >> choice;
		system("cls");
		cout << "The tree: " << endl;
		LevelOrder(pRoot);
		switch (choice) {
		case 1:
			NLR(pRoot);
			cout << endl;
			break;
		case 2:
			LNR(pRoot);
			cout << endl;
			break;
		case 3:
			LRN(pRoot);
			cout << endl;
			break;
		case 4:
			LevelOrder(pRoot);
			break;
		case 5:
			cout << "Input value to search: ";
			cin >> n;
			search = Search(pRoot, n);
			if (search)
				cout << "This value exist" << endl;
			else
				cout << "This value does not exist" << endl;
			break;
		case 6:
			cout << "Input value to insert: ";
			cin >> n;
			Insert(pRoot, n);
			break;
		case 7:
			cout << "Input value to remove: " << endl;
			cin >> n;
			Remove(pRoot, n);
			break;
		case 8:
			cout << "The height of tree: " << Height(pRoot) << endl;
			break;
		case 9:
			cout << "The number of node of tree: " << CountNode(pRoot) << endl;
			break;
		case 10:
			cout << "Input value to calculate: ";
			cin >> n;
			search = Search(pRoot, n);
			if (search)
				cout << "The level of node: " << Level(pRoot, search) << endl;
			else
				cout << "This value is not exist in tree" << endl;
			break;
		case 11:
			cout << "The number of leaves of tree: " << CountLeaf(pRoot) << endl;
			break;
		case 12:
			cout << "Input value: ";
			cin >> n;
			cout << "The node is less than this value is: " << CountLess(pRoot, n) << endl;
			break;
		case 13:
			cout << "Input value: ";
			cin >> n;
			cout << "The node is greater than this value is: " << CountGreater(pRoot, n) << endl;
			break;
		case 14:
			if (IsBST(pRoot))
				cout << "This is a Binary Search Tree" << endl;
			else
				cout << "This is not a Binary Search Tree" << endl;
			break;
		case 0:
			status = false;
			break;
		default:
			break;
		}
		if (choice != 0 && choice != 6 && choice != 7) {
			stop = true;
			while (stop) {


				cout << "Input 0 to back! ";
				cin >> n;
				if (n == 0)
					stop = false;
			}
		}
	}
	DeleteAll(pRoot);
	return 0;
}