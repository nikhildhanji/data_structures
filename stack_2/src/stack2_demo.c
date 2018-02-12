#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack2.h"

int main(int argc, char *argv[])
{
	int i = 0,num_of_entries = 100000;
	time_t start, end;
	stack s = {NULL};
	
	
	srand(time(NULL));
	time(&start);
	while (i<num_of_entries)
	{
		push(&s, rand()%100);
		i++;
	}
	time(&end);
	printf("Time taken to push %d numbers on the stack: %.2lf sec\n",num_of_entries, difftime(end,start));
	/*display(&s);*/
	printf("The size of the stack is %d\n",size(&s));
	i=0;
	time(&start);
	while (i<num_of_entries)
	{
		pull(&s);
		/*printf("The value peeked at is %d\n",peek(&s));*/
		/*display(&s);*/
		i++;
	}
	time(&end);
	printf("Time taken to pull %d numbers off the stack: %.2lf sec\n",num_of_entries, difftime(end,start));
	printf("The size of the stack is %d\n",size(&s));
	return 0;
} 
