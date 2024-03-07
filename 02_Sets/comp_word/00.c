// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "00.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");
	
	SET A = 7; 	//00000111
	SET B = 24; //00011000
	
	separator("DISPLAYING SETS");
	
	display(A);
	display(B);
	
	separator("DISPLAYING ADD");
	
	add(&A, 4);
	display(A);
	
	separator("DISPLAYING DIFFERENCE A-B and B-A RESPECTIVELY");
	
	display(difference(A, B));
	display(difference(B, A));
	
	separator("DISPLAY SET UNION");
	
	display(SET_union(A,B));
	display(SET_intersection(A,B));

	separator("END");
	
	return 0;
}
