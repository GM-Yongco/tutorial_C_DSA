// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

typedef unsigned char SET;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void separator(char* message){
	int count = 53; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, message, strlen(message));
	new_string[strlen(message) + 1] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS
// =======================================================================

void add(SET* X, int elem){
	*X = *X | (1<<elem);
}

void display(SET X){
	SET mask;
	printf("\n");
	for(mask = 1 << ((sizeof(SET)*8) - 1); mask > 0; mask = mask >> 1){
		printf("%d", ((X&mask) > 0)?(1):(0));
	}
}

SET SET_union(SET A, SET B){
	return A|B;
}
SET SET_intersection(SET A, SET B){
	return A&B;
}

SET difference(SET A, SET B){
	return A&(~B);
}	