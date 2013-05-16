/* Solving the producer-consumer problem using semaphores */

#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

typedef int buffer_item;
#define BUFFER_SIZE 5
buffer_item buffer[BUFFER_SIZE];

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void display()
{
	int i=0;
	while(i<BUFFER_SIZE)
		printf("%d",buffer[i++]);
	printf("\n");
}
int addp()
{
int k=0;
while(k<BUFFER_SIZE)
{
	if(buffer[k] == 0)
	{	
		buffer[k]=1;printf("Product added to pool by PRODUCER \n");display();
		return 0;
	}
	else 
		k++;
}
if (k>=BUFFER_SIZE)
	return -1;
}

int removec()
{
int i=0;
while(i<=BUFFER_SIZE)
{
	if(buffer[i]==0 && buffer[i-1]==1 && i)
	{
		buffer[i-1]=0;printf("Product removed from pool by CONSUMER\n");display();
		return 0;
	}
	else i++;
}
if(i>BUFFER_SIZE)
	return -1;
}

void *producer();
void *consumer();

main()
{
	pthread_t thread1;	/*thread indentifiers*/
	pthread_t thread2;
	pthread_attr_t att;	/*thread attributes*/
	pthread_attr_t att2;

	pthread_attr_init(&att);	/*applying default thread attributes*/
	pthread_attr_init(&att2);

	pthread_create( &thread1, &att, producer, NULL);	
	pthread_create( &thread2, &att2, consumer, NULL);
	pthread_join( thread1, NULL);
	pthread_join(thread2,NULL);
	exit(0);
	
}

void *producer()
{
	int m=0;
	while(m<(rand()%5))
	{
		sleep(rand()%2);
		pthread_mutex_lock(&mutex);
		if(addp()) 
			printf("PRODUCER Error\n");
		pthread_mutex_unlock(&mutex);
	}
}
void *consumer()
{
	int n=0;
	while(n<(rand()%5))
	{
		sleep(rand()%2);
		pthread_mutex_lock(&mutex);
		if(removec())
			printf("CONSUMER Error\n");
		pthread_mutex_unlock(&mutex);
	}
}

