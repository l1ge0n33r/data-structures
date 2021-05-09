#include<stdio.h>
#define CAPACITY 40

typedef int DataType;


struct DynamicArray
{
	unsigned size;
	DataType buffer[CAPACITY];
};


void constructor(struct DynamicArray *the_array)
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	the_array->size = 0;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		the_array->buffer[i] = 0;
	}
}

void destructor(struct DynamicArray *the_array) 
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	the_array->size = 0;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		the_array->buffer[i] = 0;
	}
	the_array = NULL;
}

void push_back(struct DynamicArray* the_array, DataType e) {
	if (the_array == NULL) { printf("Null pointer was given"); return; } 
	if (the_array->size >= CAPACITY) { printf("Array reached limit"); return; }
	the_array->size++;
	the_array->buffer[the_array->size - 1] = e;
}

void pop_back(struct DynamicArray* the_array) 
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	if (the_array->size == 0) { printf("Array is empty"); return; }
	
	the_array->size--;
	the_array->buffer[the_array->size] = 0;
	
}

void insert(struct DynamicArray* the_array, DataType e, unsigned index)
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	if (index >= the_array->size && index < 0) { printf("Index is out of bounds"); return; }
	the_array->size++;
	for (size_t i = the_array->size-1; i >index ; i--)
	{
		the_array->buffer[i] = the_array->buffer[i - 1];
	}
	the_array->buffer[index] = e;

}

void delete(struct DynamicArray* the_array, unsigned index)
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	if (the_array->size == 0) { printf("Array is empty"); return; }
	if (index >= the_array->size && index < 0) { printf("Index is out of bounds"); return; }
	for (size_t i = index; i < the_array->size; i++)
	{
		the_array->buffer[i] = the_array->buffer[i+1];
	}
	the_array->size--;
}

void clear(struct DynamicArray* the_array)
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	the_array->size = 0;
	for (size_t i = 0; i < CAPACITY; i++)
	{
		the_array->buffer[i]=0;
	}
}

void assign(struct DynamicArray* the_array, struct DynamicArray* the_array2)
{
	if (the_array == NULL || the_array2 == NULL) { printf("Null pointer was given"); return; }

	the_array->size = the_array2->size;
	for (size_t i = 0; i < the_array->size; i++)
	{
		the_array->buffer[i] = the_array2->buffer[i];
	}
}

DataType get_element(struct DynamicArray* the_array, DataType index)
{
	if (the_array == NULL) { printf("Null pointer was given"); return; }
	if (index >= the_array->size && index < 0) { printf("Index is out of bounds"); return; }
	return the_array->buffer[index];
}

void print(struct DynamicArray *the_array) 
{
	if (the_array->size == 0) { printf("Array is empty"); return; }
	for (size_t i = 0; i < the_array->size; i++)
		{
			printf("%d: %d\n",i, the_array->buffer[i]);
		}
}

int main()
{
	struct DynamicArray a;


	constructor(&a);

	for (size_t i = 10; i > 0; i--)
	{
		push_back(&a, i);
	}
	
	print(&a);
	
	pop_back(&a);
	printf("%d\n", get_element(&a, 3));

	print(&a);
	delete(&a, 5);
	print(&a);


	struct DynamicArray a2;


	constructor(&a2);

	for (size_t i = 0; i < 4; i++)
	{
		push_back(&a2, i);
	}

	assign(&a,&a2);
	print(&a);
	clear(&a2);
	insert(&a, 32, 2);
	print(&a);
	print(&a2);
}