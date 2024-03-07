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

// CHANGE DEPENDING ON THE STRUCTURE VERSION
typedef struct{
	int top;
	elem data[MAX];
}stack;

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
// MISC STACK FUNCTIONS
// =======================================================================

void display_stack_full(stack S){
	printf("\ntop: %d", S.top);
	int i;
	for(i = 0; i<MAX; i++){
		printf("\n%d\tdata[%c]", i, S.data[i]);
	}
}

void display_stack(stack S){
	int i;
	for(i = 0; i<= S.top; i++){
		printf("\n%d\tdata[%c]", i, S.data[i]);
	}
}

// =======================================================================
// STACK FUNCTIONS 1
// =======================================================================

void init_stack(stack* S){
	S->top = null;
}
boolean is_empty(stack S){
	return (S.top == null)?(TRUE):(FALSE);
}
boolean is_full(stack S){
	return (S.top == MAX-1)?(TRUE):(FALSE);
}

// =======================================================================
// STACK FUNCTIONS 2
// =======================================================================

void push(stack* S, elem new_data){
	if(is_full(*S) == FALSE){
		S->data[++S->top] = new_data;
	}
}
void pop(stack* S){
	if(is_empty(*S) == FALSE){
		S->top = S->top - 1;
	}
}
elem top(stack S){
	return (S.top != null)?(S.data[S.top]):('\0');
}

// =======================================================================
// STACK FUNCTIONS 3
// =======================================================================

void remove_elem(stack* S, elem x){
	if(is_empty(*S) == FALSE){
		stack temp;
		init_stack(&temp);

		while(top(*S) != x && is_empty(*S) == FALSE){
			push(&temp, top(*S));
			pop(S);
		}
		if(is_empty(*S) == FALSE){
			pop(S);
		}
		while(is_empty(temp) == FALSE){
			push(S, top(temp));
			pop(&temp);
		}
	}
}