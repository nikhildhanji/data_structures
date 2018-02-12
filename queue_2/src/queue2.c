#include<stdio.h>
#include <stdlib.h>
#include "queue2.h"

bool enqueue(queue* q,int v)
{
	if (q != NULL)
	{
		
		/*printf("\tThe value being enqueued onto the queue is: %d\n",v);*/ 
		/*When the head is empty*/
		element* new_element = (element*)malloc(sizeof(element));
		if (q->head==NULL)
		{
			q->head = new_element;
			q->head->value = v; 
			q->head->next = NULL; 
		}
		else
		{
			element* e = q->head;
			while (true)
			{
				if (e->next == NULL)
				{
					break;
				}
				e = e->next;
			}
			e->next = new_element;
			new_element->next = NULL;
			new_element->value = v;
		}
		return true;
	}
	return false;
}
int dequeue(queue* q)
{
	if (q != NULL)
	{	
		int sz=size(q);
		if (sz!=0)
		{   
			int value=0;
			element* e = q->head;
			if (sz==1)
			{
				value = q->head->value;
				free(q->head);
				q->head = NULL;
			}
			else
			{
				e=q->head->next;
				value = q->head->value;
				free(q->head);
				q->head = e;
			}
			return value;
		}
		fprintf(stderr,"Error: There is nothing to be dequeued\n");
	}
	else{
		fprintf(stderr,"Error: The pointer to the queue was NULL\n");
	}
	exit(1);
}
bool is_empty(queue* q)
{
	return size(q) == 0;
}
void display(queue* q)
{
	if (q != NULL)
	{
		element* e = q->head;
		while (e != NULL)
		{
			printf("[%d]->",e->value);
			e = e->next;
		}
		printf("[]\n");
	}
	return;
}
int size(queue* q)
{
	if (q != NULL)
	{
		int size=0;
		element* e = q->head;
		while (e != NULL)
		{
			e = e->next;
			size++;
		}
		return size;
	}
	fprintf(stderr,"Error: The pointer to the queue was NULL\n");
	exit(1);
}