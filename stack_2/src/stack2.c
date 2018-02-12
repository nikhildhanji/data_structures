

#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"
bool push(stack* s, int v)
{
	if (s != NULL)
	{
		/*printf("\tThe value being pushed onto the stack is: %d\n",v);*/ 
		/*When the head is empty*/
		element* new_element = (element*)malloc(sizeof(element));
		if (s->head==NULL)
		{
			s->head = new_element;
			s->head->value = v; 
			s->head->next = NULL; 
		}
		else
		{
			element* e = s->head;
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
int pull(stack* s)
{
	
	if (s!=NULL)
	{
		
		
		int sz = size(s), value;
		if(sz>0){
			if(sz==1){
				value = s->head->value;
				free(s->head);
				s->head = NULL;
			}
			else{
				int i=0;
				element* e = s->head;
				
				for (i=0;i<sz-2;i++)
				{
					e = e->next;
				}
				value = e->next->value;
				free(e->next);
				e->next = NULL;

			}
			return value;
		}
		fprintf(stderr,"Error: underflow!\n");
	}
	else{
		fprintf(stderr,"Error: The pointer to the stack was NULL\n");
	}
	exit(1);
}
int peek(stack* s)
{
		
	if (s!=NULL)
	{
		element* e = s->head;
		while (true)
		{
			if (e->next == NULL)
			{
				break;
			}
			e = e->next;
		}
		return e->value;
	}
	fprintf(stderr,"Error: The pointer to the stack was NULL\n");
	exit(1);
}
void display(stack* s)
{
	if (s != NULL)
	{
		element* e = s->head;
		while (e != NULL)
		{
			printf("[%d]->",e->value);
			e = e->next;
		}
		printf("[]\n");
	}
	return;
}
int size(stack* s)
{
	
	if (s != NULL)
	{
		int size=0;
		element* e = s->head;
		while (e != NULL)
		{
			e = e->next;
			size++;
		}
		return size;
	}
	fprintf(stderr,"Error: The pointer to the stack was NULL\n");
	exit(1);
}