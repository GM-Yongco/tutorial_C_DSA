// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

#define MAX 5
#define null -1 

typedef enum{FALSE, TRUE}boolean;
typedef char elem;
typedef int index;

// CHANGE DEPENDING ON THE STRUCTURE VERSION
typedef struct{
	index top;
	index bot;
	elem data[MAX];
}queue;

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){
	int count = 55; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[1] = '\n';
	new_string[count-2] = '\n';
	new_string[count-3] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 2, message, strlen(message));
	new_string[strlen(message) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// QUEUE FUNCTIONS 1
// =======================================================================

void init_queue(queue* Q){
	Q->top = 0;
	Q->bot = null;
}
boolean is_empty(queue Q){
	return (Q.top - 1 == Q.bot)?(TRUE):(FALSE);
}
boolean is_full(queue Q){
	return (Q.bot == MAX-1)?(TRUE):(FALSE);
}

// =======================================================================
// MISC QUEUE FUNCTIONS
// =======================================================================

void display_queue_full(queue Q){
	printf("\nindex top\t[%d]", Q.top);
	printf("\nindex bot \t[%d]", Q.bot);
	int i;
	for(i = 0; i<MAX; i++){
		printf("\n%d\t data[%c]", i, Q.data[i]);
	}
}
void display_queue(queue Q){
	int i;
	for(i = Q.top; i <= Q.bot; i++){
		printf("\n%d\t data[%c]", i, Q.data[i]);
	}
}

// =======================================================================
// QUEUE FUNCTIONS 2
// =======================================================================

void enqueue(queue* Q, elem new_data){
	if(is_full(*Q) == FALSE){
		Q->data[++Q->bot] = new_data;
	}
}
void dequeue(queue* Q){
	if(is_empty(*Q) == FALSE){
		Q->top++;
	}
}
elem top(queue Q){
	return (is_empty(Q) == FALSE)?(Q.data[Q.top]):('\0');
}


// =======================================================================
// CHALLENGE FUNCTIONS
// =======================================================================

void remove_elem(queue* Q, elem x){
	queue temp;
	init_queue(&temp);
	while(is_empty(*Q) == FALSE){
		enqueue(&temp, top(*Q));
		dequeue(Q);
	}
	init_queue(Q);
	while(is_empty(temp) == FALSE){
		if(top(temp) != x){
			enqueue(Q, top(temp));
		}
		dequeue(&temp);
	}
}