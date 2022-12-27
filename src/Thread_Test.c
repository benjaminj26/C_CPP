#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

int condition = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * thread_test(void * args)
{
	unsigned upp = *(unsigned*)args;
	// for (int i = 0; i < 5; ++i)
	// {
	// 	printf("Waiting...\n");
	// 	while (pthread_mutex_trylock(&lock));
	// 	while (condition);
	// 	// pthread_mutex_lock(&lock);
	// 	condition = 1;
	// 	printf("Unlocked\n");
	// 	printf("Thread ID: %lu\n", pthread_self());
	// 	printf("Hello From Thread %u\n", t_id);
	// 	sleep(5);
	// 	condition = 0;
	// 	pthread_mutex_unlock(&lock);
	// }
	for(unsigned i=0; i < upp; i++)
    {
        for(unsigned j=2;j <= sqrt(i); j+=1)
        {
            if(i % j==0)
            {
                break;
            }
        }
    }
	printf("Finished upto %u\n", upp);
	return NULL;
}

int main()
{
	pthread_t t[200];
	unsigned thread_vals[8] = {
		2000000, 5000000,
		3000000, 1000000,
		7000000, 4000000,
		8000000, 6000000
	};

	int counter = 0;
	for (unsigned i = 0; i < 200; ++i)
	{
		if (counter > 7)
		{
			counter = 0;
		}
		pthread_create(&t[i], NULL, &thread_test, &thread_vals[counter]);
		counter++;
	}
	for (unsigned i = 0; i < 200; ++i)
	{
		pthread_join(t[i], NULL);
	}
	printf("All threads have finished execution\n");
	return 0;
}