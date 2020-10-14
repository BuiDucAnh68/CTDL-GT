//Xóa các node có info bằng nhau trong danh sách.
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
	node * p = new node;
	if (p == NULL)
		exit(1);
	p->info = x;
	p->pNext = NULL;
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
		cout << "Danh sach rong !!!";
}
void Xuat(List &l)
{
	node * p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
int RemoveAfterQ(List &l,node *q)
{
	node *p;
	if (q != NULL)
	{
		p = q ->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
			delete p;
		}
		return 1;
	}
	else return 0;
}
int RemoveX(List &l)
{
	node * p;
	for (node * i = l.pHead; i != NULL; i = i->pNext) 
		for (node *j = i; j != NULL; j = j->pNext)
		{
			p = j->pNext;
			if (p == NULL) {
				p = j;
			}
			if (i->info == j->info)
			{
				if (p != NULL)
					RemoveAfterQ(l, j);
			}
		}
	return 1;
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
	p = Head;
	l.pHead = l.pTail;
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	ReverseList(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	Xuat(l);
	cout << endl;
	RemoveX(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	Xuat(l);
	return 0;
}