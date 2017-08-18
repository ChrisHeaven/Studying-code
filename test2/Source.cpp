#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

struct dll_node
{
	int value;
	dll_node *next;
	dll_node *pre;
};

dll_node *create_dll_node(int data[], int len)
{
	dll_node *p = new dll_node();
	p->pre = NULL;
	p->next = NULL;
	p->value = data[0];
	dll_node *head = p;

	for (int i = 1; i < len; i++)
	{
		dll_node *new_node = new dll_node();
		new_node->value = data[i];
		new_node->pre = p;
		new_node->next = NULL;
		p->next = new_node;
		p = new_node;
	}
	return head;
}

void print_list(dll_node *head)
{
	for (dll_node *i = head; i != NULL; i = i->next)
		cout << i->value << " ";
	cout << endl;
}

dll_node *insert_node_before(dll_node *p, int value, dll_node *head)
{
	dll_node *p_pre = p->pre;
	dll_node *new_node = new dll_node();

	if (p_pre != NULL)
	{
		p->pre = new_node;
		new_node->next = p;
		new_node->pre = p_pre;
		p_pre->next = new_node;
		new_node->value = value;
	}
	else
	{
		p->pre = new_node;
		new_node->next = p;
		new_node->pre = NULL;
		new_node->value = value;
		head = new_node;
	}
	return head;
}

void insert_node_behind(dll_node *p, int value)
{
	dll_node *p_next = p->next;
	dll_node *new_node = new dll_node();

	if (p_next != NULL)
	{
		p->next = new_node;
		new_node->pre = p;
		new_node->next = p_next;
		p_next->pre = new_node;
		new_node->value = value;
	}
	else
	{
		p->next = new_node;
		new_node->next = NULL;
		new_node->pre = p;
		new_node->value = value;
	}
}

dll_node *delete_list(dll_node *head, dll_node *delete_node)
{
	dll_node *p = delete_node;
	dll_node *p_next = p->next;

	if (p->next == NULL)
		p->pre->next = p->next;
	else if (p == head)
	{
		head = head->next;
		delete p;
		p = NULL;
	}
	else
	{
		if (p_next->next != NULL)
			p_next->next->pre = p;
		p->next = p_next->next;
		p->value = p_next->value;
		delete p_next;
		p_next = NULL;
	}

	return head;
}

void main()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 6, 6, 7, 7 };
	int length = sizeof(data) / sizeof(int);
	dll_node *head = create_dll_node(data, length);
	print_list(head);
	head = insert_node_before(head, 8, head);
	print_list(head);

	for (dll_node *i = head; i != NULL; i = i->next)
	{
		if (i->value == 3)
			insert_node_behind(i, 23);
	}
	print_list(head);

	head = delete_list(head, head);
	print_list(head);

	for (dll_node *i = head; i != NULL; i = i->next)
	{
		if (i->value == 7)
		{
			head = delete_list(head, i);
			i = i->pre;
		}
	}
	print_list(head);

	system("pause");
}