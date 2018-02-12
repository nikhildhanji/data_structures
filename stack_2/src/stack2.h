
#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif

typedef int bool;
typedef struct Element 
{
	int value;
	struct Element* next;
}element;
typedef struct  
{
	element* head;
}stack;

extern bool push(stack*, int);
extern int pull(stack*);
extern int peek(stack*);
extern void display(stack*);
extern int size(stack*);