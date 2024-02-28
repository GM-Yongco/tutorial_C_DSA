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

	Dict A;
	initDict(A);
	
	separator("1");
	
	int inputs[] = {20, 30, 0, 28, 33, 13, 48, 108, 45, 43};

	int i;
	for(i = 0; i< sizeof(inputs)/sizeof(*inputs);i++ ){
		insert(A, inputs[i]);
	}

	// to test for duplicates
	for(i = 0; i< sizeof(inputs)/sizeof(*inputs);i++ ){
		insert(A, inputs[i]);
	}
	
	displayDict(A);
	
	separator("2");
	
	(isMember(A, 28) == TRUE)?(printf("found\n")):(printf("not found\n"));
	(isMember(A, 18) == TRUE)?(printf("found\n")):(printf("not found\n"));
	(isMember(A, 20) == TRUE)?(printf("found\n")):(printf("not found\n"));
	(isMember(A, 43) == TRUE)?(printf("found\n")):(printf("not found\n"));
	
	separator("3");
	
	deleteElem(A, 43);
	deleteElem(A, 20);
	deleteElem(A, 21);
	deleteElem(A, 40);
	
	displayDict(A);
	
	separator("END");
	return 0;
}
