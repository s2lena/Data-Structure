#include "Function.h"


Node* CreateNode(int data)
{
	Node* tmp = new Node;
	tmp->key = data;
	tmp->pLeft = nullptr;
	tmp->pRight = nullptr;
	return tmp;
}

void NLR(Node* pRoot)
{
	if (pRoot) {
		cout << pRoot->key << " ";
		NLR(pRoot->pLeft);
		NLR(pRoot->pRight);
	}
}

void LNR(Node* pRoot)
{
	if (pRoot) {
		LNR(pRoot->pLeft);
		cout << pRoot->key << " ";
		LNR(pRoot->pRight);
	}
}

void LRN(Node* pRoot)
{
	if (pRoot) {
		LRN(pRoot->pLeft);
		LRN(pRoot->pRight);
		cout << pRoot->key << " ";
	}
}

void PrintLevelOrder(Node* pRoot, int level)
{
	if (pRoot == nullptr)
		return;
	if (level == 1)
		cout << pRoot->key << " ";
	else if (level > 1) {
		PrintLevelOrder(pRoot->pLeft, level - 1);
		PrintLevelOrder(pRoot->pRight, level - 1);
	}
}

void LevelOrder(Node* pRoot)
{
	int height = Height(pRoot);
	for (int i = 1; i <= height; i++) {
		PrintLevelOrder(pRoot, i);
		cout << endl;
	}
}

Node* Search(Node* pRoot, int x)
{
	while (pRoot != nullptr) {
		if (x == pRoot->key)
			return pRoot;
		if (x > pRoot->key)
			pRoot = pRoot->pRight;
		else
			pRoot = pRoot->pLeft;
	}
	return nullptr;
}

void Insert(Node*& pRoot, int x)
{
	if (pRoot != nullptr) {
		if (x == pRoot->key)
			return;
		if (x > pRoot->key)
			return Insert(pRoot->pRight, x);
		return Insert(pRoot->pLeft, x);
	}
	pRoot = CreateNode(x);
}

void Del(Node*& pRoot, Node*& q)
{
	if (pRoot->pRight)
		Del(pRoot->pRight, q);
	else {
		q->key = pRoot->key;
		q = pRoot;
		pRoot = pRoot->pLeft;
	}
}

void Remove(Node*& pRoot, int x)
{
	if (pRoot == nullptr)
		return;
	if (x > pRoot->key)
		Remove(pRoot->pRight, x);
	else if (x < pRoot->key)
		Remove(pRoot->pLeft, x);
	else {
		Node* q = pRoot;
		if (q->pRight == nullptr)
			pRoot = q->pLeft;
		else if (q->pLeft == nullptr)
			pRoot = q->pRight;
		else
			Del(pRoot->pLeft, q);
		delete q;
	}
}

int Height(Node* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = Height(pRoot->pLeft);
	int right = Height(pRoot->pRight);
	if (left > right)
		return left + 1;
	return right + 1;
}

int CountNode(Node* pRoot)
{
	if (pRoot == nullptr)
		return 0;
	int left = CountNode(pRoot->pLeft);
	int right = CountNode(pRoot->pRight);
	return right + left + 1;
}

int Level(Node* pRoot, Node* p)
{
	if (pRoot == nullptr)
		return 0;
	if (pRoot == p)
		return 1;
	int left = Level(pRoot->pLeft, p);
	int right = Level(pRoot->pRight, p);
	if (left)
		return left + 1;
	else if (right)
		return right + 1;
	else
		return 0;
}

int CountLeaf(Node* pRoot)
{
	if (pRoot->pLeft == nullptr && pRoot->pRight == nullptr)
		return 1;
	int left = CountLeaf(pRoot->pLeft);
	int right = CountLeaf(pRoot->pRight);
	return left + right;
}

int CountLess(Node* pRoot, int x)
{
	if (pRoot == nullptr)
		return 0;
	if (x == pRoot->key)
		return CountNode(pRoot->pLeft);
	if (x > pRoot->key) {
		int total = CountNode(pRoot->pLeft) + 1;
		return total + CountLess(pRoot->pRight, x);
	}
	return CountLess(pRoot->pLeft, x);
}

int CountGreater(Node* pRoot, int x)
{
	if (pRoot == nullptr)
		return 0;
	if (x == pRoot->key)
		return CountNode(pRoot->pRight);
	if (x < pRoot->key) {
		int total = CountNode(pRoot->pRight) + 1;
		return total + CountGreater(pRoot->pLeft, x);
	}
	return CountGreater(pRoot->pRight, x);
}

bool IsBST(Node* pRoot)
{
	if (pRoot == nullptr)
		return true;
	if (pRoot->pLeft != nullptr && pRoot->pLeft->key > pRoot->key)
		return false;
	if (pRoot->pRight != nullptr && pRoot->pRight->key < pRoot->key)
		return false;
	if (!IsBST(pRoot->pLeft) || !IsBST(pRoot->pRight))
		return false;
	return true;
}

void DeleteAll(Node* pRoot)
{
	if (pRoot->pLeft != nullptr) DeleteAll(pRoot->pLeft);
	if (pRoot->pRight != nullptr) DeleteAll(pRoot->pRight);
	delete pRoot;
	pRoot = nullptr;
}