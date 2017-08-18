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
	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void insert_node(dll_node *p, int value)
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

void delete_list(dll_node *head, dll_node *p)
{
	if (p->next == NULL)
	{
		delete p;
		p = NULL;
	}
	else if (p == head)
	{
		head = head->next;
		delete p;
		p = NULL;
	}
	else
	{
		p->pre->next = p->next;
		p->next->pre = p->pre;
		delete p;
		p = NULL;
	}
}

void main()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 7 };
	int length = sizeof(data) / sizeof(int);
	dll_node *head = create_dll_node(data, length);
	print_list(head);
	insert_node(head, 8);
	print_list(head);

	dll_node *find = head;
	for (int i = 0; i < length; i++)
	{
		find = find->next;
		if (find->value == 3)
			insert_node(find, 23);
	}
	print_list(head);

	delete_list(head, head);
	print_list(head);

	delete_list(head, head->next);
	print_list(head);

	system("pause");
}