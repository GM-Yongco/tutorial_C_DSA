// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "V1.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){

	separator("00 INITIALIZE");
	stack A;
	init_stack(&A);
	display_stack(A);
	
	// =======================================================================

	separator("PUSH");
	int i = 0;
	while(is_full(A) == FALSE){
		push(&A, 'a' + i);
		i++;
	}
	display_stack(A);
	
	// =======================================================================

	separator("POP");
	pop(&A);
	display_stack(A);
	
	// =======================================================================

	separator("TOP");
	printf("%c", top(A));

	// =======================================================================

	separator("ALL");
	remove_elem(&A, 'c');
	remove_elem(&A, '$');
	remove_elem(&A, 'a');
	display_stack(A);

	// =======================================================================

	separator("END");
	return 0;
}