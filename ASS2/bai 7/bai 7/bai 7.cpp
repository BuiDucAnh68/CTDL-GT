//Nhập số nguyên y, xóa số y đầu tiên trong danh sách.
#include<iostream>
using namespace std;
struct node
{
	int info;
	node *pNext;
};
struct List
{
	node *pHead;
	node *pTail;
};
void CreateList(List &l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node *CreateNode(int x)
{
	node *p = new node;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext =NULL;
	return p;
}
void AddTail(List &l, node *p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List &l)
{
	int x;
	while (1)
	{
		cin >> x;
		if (x == 0)
			break;
		node * p = CreateNode(x);
		AddTail(l, p);
	}
	if (l.pHead == NULL)
		cout << " Danh sach rong !!!";
}
void Xuat(List &l)
{
	node *p = l.pHead;
	while (p != NULL) {
		cout << p->info << " ";
		p = p->pNext;
	}
}
void ReverseList(List &l)
{
	node *p = l.pHead;
	node *Head = NULL;
	node *Tail = NULL;
	while (p != NULL)
	{
		Head = p;
		p = p->pNext;
		Head->pNext = Tail;
		Tail = Head;
	}
	Head = p;
	l.pHead = l.pTail;
}
int RemoveAfterQ(List &l, node * q, int &x)
{
	node *p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
			x = p->info;
			delete p;
		}
		return 1;
	}
	else return 0;
}
int RemoveHead(List &l, int &x)
{
	node *p;
	if (l.pHead != NULL)
	{
		p = l.pHead;
		x = p->info;
		l.pHead = l.pHead->pNext;
		delete p;
		if (l.pHead == NULL)
			l.pTail = NULL;
		return 1;
	}
	return 0;
}
int RemoveX(List &l, int x)
{
	node *p, *q = NULL; p = l.pHead;
	while ((p != NULL) && (p->info != x))
	{
		q = p;
		p = p->pNext;
	}
	if (p == NULL)
		return 0;
	if (q != NULL)
		RemoveAfterQ(l, q, x);
	else RemoveHead(l, x);
	return 1;
}
int main()
{
	List l;
	int x;
	CreateList(l);
	Nhap(l);
	cin >> x;
	if (l.pHead != NULL)
	{
		if (RemoveX(l, x) != x)
		{
			cout << endl;
			cout << "Khong tim thay " << x << " trong danh sach!!";
		}
		if (l.pHead == NULL)
			cout << "Danh sach rong !!";
		else
			ReverseList(l);
			Xuat(l);
	}
}