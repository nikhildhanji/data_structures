#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
int main(int argc, char *argv[])
{
	queue q={NULL};
	int i=0,num_of_entries = 100000;
	time_t start, end;
	
	
	srand(time(NULL));
	time(&start);
	while (i<num_of_entries)
	{
		enqueue(&q, rand()%100);
		i++;
	}
	time(&end);
	printf("Time taken to enqueue %d numbers on the queue: %.2lf sec\n",num_of_entries, difftime(end,start));
	
	
	/*display(&q);*/
	time(&start);
	i=0;
	while (i<num_of_entries)
	{
		dequeue(&q);
		
		i++;
	}
	time(&end);
	display(&q);
	printf("Time taken to dequeue %d numbers from the queue: %.2lf sec\n",num_of_entries, difftime(end,start));
	
	return 0;
} 


