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
	queue A;
	init_queue(&A);
	display_queue_full(A);
	
	// =======================================================================

	separator("ENQUEUE");
	int i = 0;
	while(is_full(A) == FALSE){
		enqueue(&A, 'a' + i);
		i++;
	}
	display_queue(A);
	
	// =======================================================================

	separator("DEQUEUE");
	dequeue(&A);
	display_queue(A);
	
	// =======================================================================

	separator("TOP");
	printf("%c", top(A));

	// =======================================================================

	separator("ALL");
	remove_elem(&A, 'c');
	// remove_elem(&A, '$');
	// remove_elem(&A, 'a');
	display_queue(A);

	// =======================================================================

	separator("END");
	return 0;
}