// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================
#include <stdio.h>
#include <stdlib.h>

// #include "01.h"
#include "02.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	int given[MAX] = {6, 2, 9, 4, 2, 0, 5, 10, 8, 1, 12, 4, 3, 19};
	int given_count = 13;
	// ---------------------------------------------
	LIST x;
	list_innit(&x);
	list_display(&x);
	// ---------------------------------------------
	int i;
	for(i = 0; i<=given_count; i++){
		list_insert(&x, given[i]);
	}
	list_display(&x);    
	// ---------------------------------------------
	heapify(&x);
	list_display(&x);
	// ---------------------------------------------
	delete_max_loop(&x);
	list_display(&x);
	// ---------------------------------------------
	return 0;
}
