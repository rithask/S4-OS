#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <unistd.h>

sem_t chopstick[5];

void *philosopher(void *n);
int eat(int);

int main(void)
{
	int n[5];
	pthread_t T[5];

	for (int i = 0; i < 5; i++)
		sem_init(&chopstick[i], 0, 1);

	for (int i = 0; i < 5; i++)
		pthread_create(&T[i], NULL, philosopher, (void *)&n[i]);

	for (int i = 0; i < 5; i++)
		pthread_join(T[i], NULL);

	return 0;
}

void *philosopher(void *n)
{
	int ph = *(int *)n;
	printf("Philosopher %d wants to eat\n", ph);
	printf("Philospher %d tries to pick left\n", ph);
	sem_wait(&chopstick[ph]);
	printf("Philosopher %d picked left\n", ph);
	printf("Philosopher %d tries to pick right\n", ph);
	sem_wait(&chopstick[(ph + 1) % 5]);
	printf("Philosopher %d picked right\n", ph);
	eat(ph);
	sleep(2);
	printf("Philosopher %d has finished eating\n", ph);
	sem_post(&chopstick[ph]);
	printf("Philosopher %d leaves\n", ph);
}

int eat(int n)
{
	printf("Philosopher %d begins to eat\n", n);
}