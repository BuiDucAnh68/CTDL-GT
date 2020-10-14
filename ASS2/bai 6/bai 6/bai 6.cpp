//Viết chương trình nhập danh sách liên kết đơn l với mỗi phần tử là một số nguyên(khác 0), việc nhập kết thúc khi giá trị nhập vào là 0. đảo ngược danh sách(không dùng danh sách phụ)
#include<iostream>
using namespace std;
struct node
{
	int info;
	node * pNext;
};
struct List
{
	node *pHead;
	node * pTail;
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
		cout << "Danh sach rong!!!";
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
	if (l.pHead != NULL)
	{
		ReverseList(l);
		cout << "Danh sach sau khi dao nguoc la : ";
		Xuat(l);
	}
	return 0;
}