#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
int main(int argc, char *argv[])
{
	queue q;
	int size;
	do
	{
		printf("Enter the size of the queue: ");
		scanf("%d",&size);
	}
	while (size<= 0);
	q.ptr_i = (int*) malloc(size * sizeof(int));
	q.start_index = q.end_index = 0;
	q.capacity = size;
	printf("Is the queue empty?: %s\n", is_empty(&q)?"true":"false");
	srand(time(NULL));
	while (q.end_index < q.capacity)
	{
		enqueue(&q, rand()%11);
	}
	fprintf(stderr,"Queue is full\n");
	
	
	display(&q);
	printf("The value dequeued is %d\n",dequeue(&q));
	display(&q);
	enqueue(&q, -1);
	display(&q);
	while (q.end_index > 0){
		printf("The value dequeued is %d\n",dequeue(&q));
		display(&q);
	}
	fprintf(stderr,"Queue is empty\n");
	
	printf("Is the queue empty?: %s\n", is_empty(&q)?"true":"false");
	
	free(q.ptr_i);
	return 0;
} 


