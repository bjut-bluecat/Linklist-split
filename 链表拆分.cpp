// ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;
typedef struct LNode
{
	char data;
	struct LNode *next;
}LNode, *LinkList;
LinkList creatlist()
{
	LinkList l = new LNode();//ͷ�ڵ�
	l->next = NULL;
	LNode *p;
	char haha;
	cin >> haha;
	while (haha != 'z')
	{
		p = new LNode();
		p->data = haha;
		p->next = l->next;
		l->next = p;
		cin >> haha;
	}
	return l;
}
void print(LinkList l)
{
	LNode *p = l->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
void fun(LinkList l, LinkList l1, LinkList l2, LinkList l3) //ȫ��ͷ�巨 ����㷨
{
	LNode *q, *p = l->next;
	while (p)
	{

		if (p->data >= '0'&&p->data <= '9')
		{
			q = new LNode();
			q->data = p->data;
			q->next = l1->next;
			l1->next = q;
		}
		else if (p->data >= 'a'&&p->data <= 'z')
		{
			q = new LNode();
			q->data = p->data;
			q->next = l2->next;
			l2->next = q;
		}
		else
		{
			q = new LNode();
			q->data = p->data;
			q->next = l3->next;
			l3->next = q;
		}

		p = p->next;
	}

}

int main()
{
	cout << "�������� z ����" << endl;
	LinkList l = creatlist();
	//print(l);
	LinkList l1, l2, l3;
	l1 = new LNode();//����
	l2 = new LNode();//��ĸ
	l3 = new LNode();//����
	l1->next = NULL; l2->next = NULL; l3->next = NULL;
	fun(l, l1, l2, l3);
	cout << "���" << endl;
	print(l1); cout << endl;
	print(l2); cout << endl;
	print(l3); cout << endl;
	_getch();
	return 0;
}
