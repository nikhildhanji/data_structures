#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
bool push(stack* s, int v)
{
	printf("\tThe value being pushed onto the stack is %d\n",v);
	
	if (s->top_index== 0)
	{
		fprintf(stderr,"Error: stack overflow!\n");
		exit(1);
	}
	
	printf("\tThe address of the stack to write to is %p\n",s->ptr_i+s->top_index);
	s->top_index = s->top_index-1;
	*(s->ptr_i+s->top_index)= v;
	/*s->top_index = s->top_index-1;*/
	return true;
}
int pull(stack* s)
{
	int n;
	if (s->top_index > s->bottom_index)
	{
		fprintf(stderr,"Error: stack underflow!\n");
		exit(1);
	}
	n = *(s->ptr_i+s->top_index);
	s->top_index = s->top_index+1;
	return n;
	
}
int peek(stack* s)
{
	 
	if (s->top_index >=0 && s->top_index<=s->bottom_index )
	{
		return *(s->ptr_i+s->top_index);
	}
	fprintf(stderr,"Error: pulling will result in stack underflow!");
	exit(1);
	 
}
void display(stack* s)
{
	int i;
	if(s!=NULL){
		for (i=s->top_index;i<=s->bottom_index;i++)
		{
			printf("stack[%d]=%d\n",i, *(s->ptr_i+i));
		}
	
	}
}