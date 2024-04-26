// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "adjacency_list.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");
	
	QUEUE Q  = init_queue();

	enqueue(Q, 1, 0);
	enqueue(Q, 2, 0);
	enqueue(Q, 3, 0);
	enqueue(Q, 1, 0);
	enqueue(Q, 5, 0);

	dequeue(Q);

	display_queue(Q);

	separator("END");
	return 0;
}
