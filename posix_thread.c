/*Program implementing POSIX threads*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

int sum;	/*global sum accessed by both the threads */

void *f1();	/*functions for implementing the threads */
void *f2();

main(int argc, char *argv[])
{
	pthread_t thread1;	/*thread indentifiers*/
	pthread_t thread2;
	pthread_attr_t att;	/*thread attributes*/
	pthread_attr_t att2;

	if(argc!=3)		/*argument count check*/
	{
	printf("error1\n");
	return -1;
	}
	
	pthread_attr_init(&att);	/*applying default thread attributes*/
	pthread_attr_init(&att2);
	sum=atoi(argv[1]);
	int n = atoi(argv[2]);
	int i;
	printf("Now, 1 and 2 will be parallely added to %d (%d times each) using POSIX multithreading \n",sum,n);
	for(i=0;i<n;i++)
	{
     		pthread_create( &thread1, &att, f1, NULL);	
		pthread_create( &thread2, &att2, f2, NULL);
		pthread_join( thread1, NULL);
		pthread_join(thread2,NULL);
	}	
	exit(0);
}

void *f1()
{
	pthread_mutex_lock(&lock);
	sum+=1;printf("Adding 1 : %d\n",sum);
	pthread_mutex_unlock(&lock);
}

void *f2()
{
	pthread_mutex_lock(&lock);	
	sum+=2;printf("Adding 2 : %d\n",sum);
	pthread_mutex_unlock(&lock);
}
