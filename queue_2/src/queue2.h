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
}queue;

extern bool enqueue(queue*, int);
extern int dequeue(queue*);
extern bool is_empty(queue*);
extern void display(queue*);
extern int size(queue*);