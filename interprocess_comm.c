#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int in = -1, out = -1;
int buffer[MAX];
int size;
int x = 0;

void produce();
void consume();
void display();

int main(void)
{
	int choice;

	printf("Enter the size of the buffer: ");
	scanf("%d", &size);

	printf("1. Produce\n2. Consume\n3. Exit\n");

	while(1)
	{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			produce();
			display();
			break;
		case 2:
			consume();
			display();
			break;
		case 3:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	
	return 0;
}

void produce()
{
	if ((out == size - 1 && in == 0) || out == in - 1)
	{
		printf("Buffer is full\n");
		return;
	}

	if (in == -1)
		in = 0;
	
	out = (out + 1) % size;
	++x;
	buffer[out] = x;

	printf("Producer produced item %d\n", buffer[out]);
}

void consume()
{
	if (out == -1)
	{
		printf("Buffer is empty\n");
		return;
	}

	printf("Consumer consumed item %d\n", buffer[out]);

	if (in == out)
	{
		in = -1;
		out = -1;
	}
	else
	{
		in = (in + 1) % size;
	}
}

void display()
{
	if (out == -1)
		return;

	printf("Buffer: ");
	int i;
	for (i = in; i != out; i = (i + 1) % size)
		printf("%d ", buffer[i]);
	printf("%d\n", buffer[i]);
}