#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <string.h>
#include <math.h>
#include <iomanip>
#include <algorithm>

using namespace std;

struct ddl_node
{
	int value;
	ddl_node *next;
	ddl_node *pre;
};

ddl_node *create_ddl_node(int data[], int len)
{
	ddl_node *head = new ddl_node();
	head = NULL;
	ddl_node *p = head;

	for (int i = 0; i < len; i++)
	{
		ddl_node *node = new ddl_node();
		node->value = data[i];
		node->next = NULL;
		node->pre = NULL;
		if (head == NULL)
			head = node;
		else
		{
			p->next = node;
			node->pre = p;
		}
		p = node;
	}
	return head;
}

void print_list(ddl_node *head)
{
	while (head != NULL)
	{
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}

void insert_node(ddl_node *p, int value)
{
	ddl_node *p_next = p->next;
	ddl_node *new_node = new ddl_node();

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

void delete_list(ddl_node *head, ddl_node *p)
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
	ddl_node *head = create_ddl_node(data, length);
	print_list(head);
	insert_node(head, 8);
	print_list(head);

	ddl_node *find = head;
	for (int i = 0; i < length; i++)
	{
		find = find->next;
		if (find->value == 3)
			insert_node(find, 23);
	}
	print_list(head);

	//delete_list(head, head);
	//print_list(head);

	delete_list(head, head->next);
	print_list(head);

	system("pause");
}