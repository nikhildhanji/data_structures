#ifndef true
	#define true 1
#endif
#ifndef false
	#define false 0
#endif


#ifndef Q_H
	#define Q_H
		typedef struct  
		{
			int* ptr_i;
			int end_index;
			int start_index;
			int capacity;
		}queue;
#endif
typedef int bool;
extern bool enqueue(queue*, int);
extern int dequeue(queue*);
extern bool is_empty(queue*);
extern void display(queue*);
