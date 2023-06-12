// Write a C program that prints hello world to implement system calls fork(), exec(), getpid(), exec(), wait() and exit().

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int ch;

	printf("1. fork()\n2. getpid()\n3. wait() and exit()\n4. exec()\n5. Exit\n");

	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d", &ch);
		printf("\n");

		switch (ch)
		{
		case 1:
			pid = fork();
			if (pid == 0)
			{
				printf("Hello from child %d\n", getpid());
			}
			else
			{
				wait(NULL);
				printf("Hello from parent %d\n", getpid());
			}
			break;
		case 2:
			printf("Process ID of calling function: %d\n", getpid());
			break;
		case 3:
			pid = fork();
			int status;
			if (pid == 0)
			{
				printf("Hello from child\n");
				sleep(10);
				exit(10);
			}
			else
			{
				printf("Hello from parent\n");
				wait(&status);
				printf("Exit status is %d\n", WEXITSTATUS(status));
			}
			break;
		case 4:
			execlp("ls", "-l", NULL);
			break;
		case 5:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}
}