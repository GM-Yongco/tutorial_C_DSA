// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>


//#include "00.h"	//template thingy
// #include "comp_word.h"
// #include "LL_unsorted.h"
#include "array_unsorted.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");
	SET A;
	SET B;
	SET C;

	initialize(&A);
	initialize(&B);
	initialize(&C);
	
	separator("DISPLAYING EMPTY SETS");
	display_raw(A);
	display_raw(B);
	
	separator("DISPLAYING ADD");
	SET_add(&A, 0);
	SET_add(&A, 1);
	SET_add(&A, 2);

	SET_add(&B, 3);
	SET_add(&B, 4);

	SET_add(&C, 0);
	SET_add(&C, 1);
	SET_add(&C, 2);
	SET_add(&C, 3);
	SET_add(&C, 4);

	// SET A = 7; 	00000111
	// SET B = 24;	00011000
	// SET C = 24;	00011111

	display_raw(A);
	display_formatted(A);

	display_raw(B);
	display_formatted(B);

	display_raw(C);
	display_formatted(C);
	
	separator("DISPLAYING DIFFERENCE C-A and C-B RESPECTIVELY");
	SET DA = SET_difference(C, A);
	SET DB = SET_difference(C, B);
	display_formatted(DA);
	display_formatted(DB);
	
	separator("DISPLAY SET UNION, INTERSECTION, UNIVERSAL");
	SET UA = SET_union(A,C);
	SET IA = SET_intersection(B,C);
	SET U = SET_union(C,SET_complement(C));

	printf("\nDisplay A,C union");
	display_formatted(UA);
	
	printf("\nDisplay B,C intersection");
	display_formatted(IA);
	
	printf("\nDisplay Univseral Set");
	display_formatted(U);

	separator("IS SUBSET");
	if(is_subset(A, C) == TRUE){
		printf("\nC is subset of A");
	}else{
		printf("\nC is NOT subset of A");
	}

	if(is_subset(C, B) == TRUE){
		printf("\nB is subset of C");
	}else{
		printf("\nB is NOT subset of C");
	}

	separator("IS ELEMENT");
	if(is_elem(B, 0) == TRUE){
		printf("\n0 is an element of B");
	}else{
		printf("\n0 is NOT an element of B");
	}

	if(is_elem(C, 3) == TRUE){
		printf("\n3 is an element of C");
	}else{
		printf("\n3 is NOT an element of C");
	}

	separator("REMOVE ELEMENT");
	SET_remove(&C, 3);
	SET_remove(&C, 4);
	SET_remove(&C, 5);
	SET_add(&C, 7);

	display_formatted(C);

	separator("END");
	
	return 0;
}