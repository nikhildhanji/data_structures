
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif

typedef int bool;
typedef struct  
{
	int* ptr_i;
	int bottom_index;
	int top_index;
}stack;
extern bool push(stack*, int);
extern int pull(stack*);
extern int peek(stack*);
extern void display(stack*);