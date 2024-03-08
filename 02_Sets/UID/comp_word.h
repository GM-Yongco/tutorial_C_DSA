// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

typedef unsigned char SET;

typedef enum{TRUE, FALSE}BOOL;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void separator(char* message){
	int count = 55; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[1] = '\n';
	new_string[count-3] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 2, message, strlen(message));
	new_string[strlen(message) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void initialize(SET* S){
	*S = 0;
}

void display_raw(SET S){
	SET mask;
	printf("\n");
	for(mask = 1 << ((sizeof(SET)*8) - 1); mask > 0; mask = mask >> 1){
		printf("%d", ((S&mask) > 0)?(1):(0));
	}
}

void display_formatted(SET S){
	SET mask = 1;
	int elem;
	printf("\n{");
	for(elem = 0;
		elem < sizeof(SET)*8;
		elem++, mask = mask<<1){
		if((S&mask) == mask){
			printf("%d, ", elem);
		}
	}
	printf("}\n");
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void SET_add(SET* S, int elem){
	*S = *S | (1<<elem);
}
void SET_remove(SET* S, int elem){
	*S = *S & (~(1<<elem));
}
SET SET_union(SET A, SET B){
	return A|B;
}
SET SET_intersection(SET A, SET B){
	return A&B;
}
SET SET_difference(SET A, SET B){
	return A&(~B);
}
SET SET_complement(SET A){
	return ~A;
}


// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

BOOL is_subset(SET A, SET B){
	//if B is a subset of A
	return ((A|B) == A )?TRUE:FALSE;
	//you can also use (A&B) == B
}
BOOL is_elem(SET S, int elem){
	BOOL ret = FALSE;
	if(elem < (sizeof(SET)*8) && S&(1<<elem) == (1<<elem)){
		ret = TRUE;
	}
	return ret;
}