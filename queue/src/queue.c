#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
bool enqueue(queue* q, int v)
{
	if (q->end_index == q->capacity)
	{
		fprintf(stderr,"Error: queue is full\n");
		exit(1);
	}
	* (q->ptr_i + q->end_index) = v;
	q->end_index++;
	return true;
}
int dequeue(queue* q)
{
	int temp, i;
	if (q->end_index == 0)
	{
		fprintf(stderr,"Error: queue is empty\n");
		exit(1);
	}
	temp = * (q->ptr_i + q->start_index);
	/*
	shift the values
	*/
	for (i=q->start_index;i<q->end_index;i++)
	{
		* (q->ptr_i + i) = * (q->ptr_i + i+1);
	}
	q->end_index--;
	return temp;
}
bool is_empty(queue* q)
{
	return (q->start_index == q->end_index);	
}
void display(queue* q)
{
	if (!is_empty(q))
	{
		int i;
		for (i=q->start_index;i<q->end_index;i++)
		{
			printf("Queue[%d]=%d\n",i, *(q->ptr_i+i));
		}
	}

}
