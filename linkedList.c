#include<stdio.h>
#include<stdlib.h>

typedef int DataType;

struct node
{
	DataType data;
	struct node* next;
};


void constructor(struct node* head)
{
	
	head->data = 0;
	head->next = NULL;
}

void destructor (struct node* head)
{
	free(head);
}
void push_front(struct node *head)
{
	struct node *tmp = (struct node*)malloc(sizeof(struct node));

}
void pop_front(){}
void insert_after() {}
void erase_after() {}
