#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* callback(void* arg)
{
	for(int i=0;i<5;++i)
	{
		printf("Subthread : %d \n",i);
	}
	printf("Subthread code : %d \n",pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	pthread_create(&tid,NULL,callback,NULL);
	for(int i=0;i<5;++i)
	{
		printf("Mainthrad : %d \n",i);
	}
	printf("mainthread code : %d \n",pthread_self());
	sleep(3);
	return 0;
}
