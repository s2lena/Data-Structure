#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* pLeft;
	Node* pRight;
};

Node* CreateNode(int data);
void NLR(Node* pRoot);
void LNR(Node* pRoot);
void LRN(Node* pRoot);
void PrintLevelOrder(Node* pRoot, int level);
void LevelOrder(Node* pRoot);
Node* Search(Node* pRoot, int x);
void Insert(Node*& pRoot, int x);
void Del(Node* &pRoot, Node* &q);
void Remove(Node*& pRoot, int x);
int Height(Node* pRoot);
int CountNode(Node* pRoot);
int Level(Node* pRoot, Node* p);
int CountLeaf(Node* pRoot);
int CountLess(Node* pRoot, int x);
int CountGreater(Node* pRoot, int x);
bool IsBST(Node* pRoot);
void DeleteAll(Node* pRoot);

#endif // _FUNCTION_H_
