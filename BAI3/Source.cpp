#include <iostream>
using namespace std;

struct Tnode
{
	int key;
	struct Tnode* left;
	struct Tnode* right;
};
typedef struct Tnode treeNode;

int countLeaft(treeNode* Root)
{
	int x, y;
	if (Root == nullptr)
		return 0;
	x = countLeaft(Root->left);
	y = countLeaft(Root->right);
	if (Root->left == nullptr && Root->right == nullptr)
		return x + y + 1;
	return x + y;
}

int OddSum(treeNode* Root)
{
	int x, y;
	if (Root == nullptr)
		return 0;
	x = OddSum(Root->left);
	y = OddSum(Root->right);
	return Root->key % 2 ? x + y + Root->key : x + y;
}

int Sum(treeNode* Root)
{
	int x, y;
	if (Root = nullptr)
		return 0;
	x = Sum(Root->left);
	y = Sum(Root->right);
	return x + y + Root->key;
}

int EvenLeaft(treeNode* Root)
{
	int x, y;
	if (Root == nullptr)
		return 0;
	x = EvenLeaft(Root->left);
	y = EvenLeaft(Root->right);
	return Root->key % 2 ? x + y : x + y + 1;
}

int countNodes(treeNode* Root, int k)
{
	int x, y;
	if (Root == nullptr)
		return 0;
	x = countNodes(Root->left, k);
	y = countNodes(Root->right, k);
	return Root->key > k ? x + y + 1 : x + y;
}

int main()
{
	
	return 0;
}