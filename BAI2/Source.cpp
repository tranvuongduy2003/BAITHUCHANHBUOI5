#include <iostream>
#include <queue>
using namespace std;

typedef struct Node Node;
struct Node
{
	int maSinhVien;
	string hoTen;
	float diemTrungBinh;
	Node* left;
	Node* right;
};

typedef struct BST BST;
struct BST
{
	Node* root;
};

void InitBST(BST&);
void Insert(BST&, Node*);
Node* Search(Node*, int);
Node* Search(Node*, string);
int Height(Node*);
Node* InPre(Node*);
Node* InSucc(Node*);
Node* Delete(BST&, Node*, Node*);
void DeleteGpaEqual5(BST&);
void PrintNode(Node*);
void PrintGpaDescending(Node*);
int Degree(Node*);




int main()
{
	return 0;
}

void InitBST(BST& t)
{
	t.root = nullptr;
}
void Insert(BST& bst, Node* p)
{
	Node* t;
	Node *q = nullptr;
	t = bst.root;
	if (t == nullptr)
	{
		bst.root = p;
		return;
	}
	while (t != nullptr)
	{ 
		q = t;
		if (p->diemTrungBinh < t->diemTrungBinh)
			t = t->left;
		else if (p->diemTrungBinh < t->diemTrungBinh)
			t = t->right;
		else
			return;
	}
	if (p->diemTrungBinh < q->diemTrungBinh)
		q->left = p;
	else
		q->right = p;
}
Node* Search(Node* p, int maSo)
{
	if (p == nullptr)
		return nullptr;
	if (maSo < p->maSinhVien)
		return Search(p->left, maSo);
	else if (maSo > p->maSinhVien)
		return Search(p->right, maSo);
	else
		return p;
}
Node* Search(Node* p, string hoTen)
{
	if (p == nullptr)
		return nullptr;
	if (hoTen < p->hoTen)
		return Search(p->left, hoTen);
	else if (hoTen > p->hoTen)
		return Search(p->right, hoTen);
	else
		return p;
}
int Height(Node* p)
{
	int x, y;
	if (p == nullptr)
		return 0;
	x = Height(p->left);
	y = Height(p->right);
	return x > y ? x + 1 : y + 1;
}
Node* InPre(Node* p)
{
	while (p && p->left != nullptr)
		p = p->left;
	return p;
}
Node* InSucc(Node* p)
{
	while (p && p->right != nullptr)
		p = p->right;
	return p;
}
Node* Delete(BST& bst, Node* p)
{
	Node* t = nullptr;
	if (p == nullptr)
		return nullptr;
	if (p->left == nullptr && p->right == nullptr)
	{
		if (p == bst.root)
			bst.root = nullptr;
		delete p;
		return nullptr;
	}

	if (Height(p->left) > Height(p->right))
	{
		t = InPre(p->left);
		p->diemTrungBinh = t->diemTrungBinh;
		p->left = Delete(bst, p->left);
	}
	else
	{
		t = InSucc(p->right);
		p->diemTrungBinh = t->diemTrungBinh;
		p->right = Delete(bst, p->right);
	}
	return p;
}
void DeleteGpaEqual5(BST& bst)
{
	queue<Node*> q;
	Node* p = nullptr;
	if (bst.root == nullptr)
		return;
	q.push(bst.root);
	while (!q.empty())
	{
		p = q.front();
		q.pop();
		if (p->diemTrungBinh == 5.0)
			Delete(bst, p);
		if (p->left != nullptr)
			q.push(p->left);
		if (p->right != nullptr)
			q.push(p->right);
	}
}
void PrintNode(Node* p)
{
	cout << "Ma so sinh vien: " << p->maSinhVien << endl;
	cout << "Ho ten sinh vien: " << p->hoTen << endl;
	cout << "Diem trung binh: " << p->diemTrungBinh << endl;
	cout << "----------------------------------------------" << endl;
}
void PrintGpaDescending(Node* p)
{
	if (p != nullptr)
	{
		PrintGpaDescending(p->right);
		PrintNode(p);
		PrintGpaDescending(p->left);
	}
}
int Degree(Node* p)
{
	if (p->left == nullptr && p->right == nullptr)
		return 0;
	else if (p->left != nullptr && p->right != nullptr)
		return 2;
	else
		return 1;
}