// 链表拆分.cpp : 定义控制台应用程序的入口点。
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
	LinkList l = new LNode();//头节点
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
void fun(LinkList l, LinkList l1, LinkList l2, LinkList l3) //全部头插法 拆分算法
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
	cout << "输入链表 z 结束" << endl;
	LinkList l = creatlist();
	//print(l);
	LinkList l1, l2, l3;
	l1 = new LNode();//数字
	l2 = new LNode();//字母
	l3 = new LNode();//其他
	l1->next = NULL; l2->next = NULL; l3->next = NULL;
	fun(l, l1, l2, l3);
	cout << "结果" << endl;
	print(l1); cout << endl;
	print(l2); cout << endl;
	print(l3); cout << endl;
	_getch();
	return 0;
}
