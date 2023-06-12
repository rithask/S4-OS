#include <stdio.h>
#include <stdlib.h>

void first_fit();
void best_fit();
void worst_fit();

int main(void)
{
	int choice;
	
	printf("1. First fit\n2. Best fit\n3. Worst fit\n4. Exit\n");

	while ((1))
	{
		printf("Enter your choice: ");
		scanf("%d", &choice);
		printf("\n");

		switch (choice)
		{
		case 1:
			first_fit();
			break;
		case 2:
			best_fit();
			break;
		case 3:
			worst_fit();
			break;
		case 4:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}

	return 0;
}

void get_input(int *nb, int blocks[], int *np, int processes[], int allocated[])
{
	printf("Enter the number of blocks: ");
	scanf("%d", nb);
	printf("Enter the size of the blocks...\n");
	for (int i = 0; i < *nb; i++)
	{
		printf("Block %d: ", i);
		scanf("%d", &blocks[i]);
	}

	printf("Enter the number of processes: ");
	scanf("%d", np);
	printf("Enter the memory required by the processes...\n");
	for (int i = 0; i < *np; i++)
	{
		printf("Process %d: ", i);
		scanf("%d", &processes[i]);
	}

	for (int i = 0; i < *np; i++)
		allocated[i] = -1;
}

void display(int np, int processes[], int allocated[])
{
	printf("Process ID\nProcess size\nBlock No.\n");
	for (int i = 0; i < np; i++)
	{
		printf("%d\t%d\t\t", i, processes[i]);

		if (allocated[i] == -1)
			printf("Not allocated\n");
		else
			printf("%d\n", allocated[i] + 1);
	}
}