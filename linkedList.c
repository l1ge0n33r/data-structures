#include<stdlib.h>

typedef int DataType;

struct node
{
	DataType data;
	struct node* next;
};


void constructor(struct node* head,DataType firstElement)
{
	
	head->data = firstElement;
	head->next = NULL;
}

void destructor (struct node* head)
{
	free(head);
}
void push_front(struct node *head, DataType e)
{
	struct node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = (struct node*)malloc(sizeof(struct node));
	current->next->data = e;
	current->next->next = NULL;
}
void pop_front(struct node* head)
{
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	head->next = (struct node*)malloc(sizeof(struct node));
	tmp = head->next;
	while (tmp->next != NULL)
	{
		tmp = head->next;
	}
	tmp->next = NULL;

	free(tmp);
}
void insert_after(struct node* head, DataType e, unsigned index)
{

}
void erase_after(struct node* head, unsigned index)
{

}
