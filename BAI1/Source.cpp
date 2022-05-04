#include <iostream>
#include <queue>
using namespace std;

struct Node
{
	int key;
	Node* left;
	Node* right;
};

struct Tree
{
	Node* root;
};

void InitTree(Tree&);
void Insert(Tree&, int key);
void CreateBST(Tree&);
void PrintLNR(Node*);
void PrintLRN(Node*);
void PrintNLR(Node*);
void PrintNRL(Node*);
void PrintRNL(Node*);
void PrintRLN(Node*);
Node* SearchNode(Node*, int);
bool IsPrimeNumber(int);
void DeletePrimeNode(Tree&, int);
int CountNode(Node*);


int main()
{
	int quantityOfNodes;
	Node* p;
	Tree t;
	InitTree(t);
	CreateBST(t);
	cout << "Print LNR: ";
	PrintLNR(t.root);
	cout << "\nPrint LRN: ";
	PrintLRN(t.root);
	cout << "\nPrint NLR: ";
	PrintNLR(t.root);
	cout << "\nPrint RNL: ";
	PrintRNL(t.root);
	cout << "\nPrint RLN: ";
	PrintRLN(t.root);
	
	p = SearchNode(t.root, 6);
	if (p != nullptr)
		cout << "\nTim thay " << p->key << endl;
	else
		cout << "\nKhong tim thay" << endl;

	quantityOfNodes = CountNode(t.root);
	cout << "Quantity of Nodes: " << quantityOfNodes << endl;


	return 0;
}

void InitTree(Tree& t)
{
	t.root = nullptr;
}
void Insert(Tree& t, int key)
{
	Node* r = nullptr, *p, *q;
	p = t.root;
	while (p != nullptr)
	{
		r = p;
		if (key == p->key)
			return;
		else if (key < p->key)
			p = p->left;
		else
			p = p->right;
	}
	q = new Node;
	if (q == nullptr)
		return;
	q->key = key;
	q->left = q->right = nullptr;
	if (t.root == nullptr)
		t.root = q;
	else
	{
		if (q->key < r->key)
			r->left = q;
		else
			r->right = q;
	}
}
void CreateBST(Tree& t)
{
	int x;
	do
	{
		cout << "Enter node value: ";
		cin >> x;
		if (x == -1)
			return;
		Insert(t, x);
	} while (x != -1);
}
void PrintLNR(Node* p)
{
	if (p != nullptr)
	{
		PrintLNR(p->left);
		cout << p->key << " ";
		PrintLNR(p->right);
	}
}
void PrintLRN(Node* p)
{
	if (p != nullptr)
	{
		PrintLRN(p->left);
		PrintLRN(p->right);
		cout << p->key << " ";
	}
}
void PrintNLR(Node* p)
{
	if (p != nullptr)
	{
		cout << p->key << " ";
		PrintNLR(p->left);
		PrintNLR(p->right);
	}
}
void PrintNRL(Node* p)
{
	if (p != nullptr)
	{
		cout << p->key << " ";
		PrintNRL(p->right);
		PrintNRL(p->left);
	}
}
void PrintRNL(Node* p)
{
	if (p != nullptr)
	{
		PrintRNL(p->right);
		cout << p->key << " ";
		PrintRNL(p->left);
	}
}
void PrintRLN(Node* p)
{
	if (p != nullptr)
	{
		PrintRLN(p->right);
		PrintRLN(p->left);
		cout << p->key << " ";
	}
}
Node* SearchNode(Node* p, int x)
{
	if (p == nullptr)
		return nullptr;
	if (x == p->key)
		return p;
	else if (x < p->key)
		return SearchNode(p->left, x);
	else
		return SearchNode(p->right, x);
}
bool IsPrimeNumber(int x)
{
	if (x > 2)
	{
		for (int i = 2; i <= sqrt(x); i++)
			if (x % i == 0)
				return false;
	}
	return x >= 2;
}
void DeletePrimeNode(Tree& t, int x)
{
	
}
int CountNode(Node* p)
{
	int x, y;
	if (p != nullptr)
	{
		x = CountNode(p->left);
		y = CountNode(p->right);
		return x + y + 1;
	}
	return 0;
}