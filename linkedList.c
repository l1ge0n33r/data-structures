#include<stdlib.h>

typedef int DataType;

typedef struct node
{
	DataType data;
	node* next;
} node;


void constructor(node* head)
{
	head = (node*)malloc(sizeof(node));
	head->data = 0;
	head->next = NULL;
}

void destructor (node* head)
{
	free(head);
}
void push_front(){}
void pop_front(){}
void insert_after() {}
void erase_after() {}
