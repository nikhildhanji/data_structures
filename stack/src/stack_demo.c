#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack.h"

int main(int argc, char *argv[])
{
	stack s;
	int size;
	do
	{
		printf("Enter the size of the stack: ");
		scanf("%d",&size);
	}
	while (size<= 0);
	s.bottom_index = size - 1;
	s.top_index =size;
	s.ptr_i = (int*) malloc(size * sizeof(int));
	
	printf("The size of the stack is %d\n",size);
	printf("The top of the stack is %d\n",s.top_index);
	printf("The bottom of the stack is %d\n",s.bottom_index);
	printf("The starting address of the stack is %p\n",s.ptr_i);
	
	srand(time(NULL));
	while (s.top_index> 0)
	{
		push(&s, rand()%11 );
	}
	fprintf(stderr,"Stack overflow!\n");

	
	printf("The value peeked at the stack is %d\n",peek(&s));
	printf("The value pulled from the stack is %d\n",pull(&s));
	push(&s, -1);
	display(&s);
	while (s.top_index <= s.bottom_index)
	{
		printf("The value peeked at the stack is %d\n",peek(&s));
		printf("The value pulled from the stack is %d\n",pull(&s));
		display(&s);
		
	}
	fprintf(stderr,"Stack underflow!\n");
	

	free(s.ptr_i);
	return 0;
} 
