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
}

void display_raw(SET S){
}

void display_formatted(SET S){
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void SET_add(SET* S, int elem){
}
void SET_remove(SET* S, int elem){
}
SET SET_difference(SET A, SET B){
	return A;
}
SET SET_union(SET A, SET B){
	return A;
}
SET SET_intersection(SET A, SET B){
	return A;
}
SET SET_complement(SET A){
	return A;
}


// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

BOOL is_subset(SET A, SET B){
	//if B is a subset of A
	return FALSE;
}
BOOL is_elem(SET S, int elem){
	return FALSE;
}