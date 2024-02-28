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
	
	insert(A, 20);
	
	insert(A, 30);
	insert(A, 0);
	insert(A, 28);
	insert(A, 33);
	insert(A, 13);
	insert(A, 48);
	insert(A, 108);
	insert(A, 45);
	insert(A, 43);
	
	
	insert(A, 20);
	
	insert(A, 30);
	insert(A, 0);
	insert(A, 28);
	insert(A, 33);
	insert(A, 13);
	insert(A, 48);
	insert(A, 108);
	insert(A, 45);
	insert(A, 43);
	
	
	displayDict(A);
	
	separator("2");
	
	if(isMember(A, 28) == TRUE){
		printf("found\n");
	}
	
	if(isMember(A, 18) == TRUE){
		printf("found\n");
	}
	
	if(isMember(A, 30) == TRUE){
		printf("found\n");
	}
	
	if(isMember(A, 33) == TRUE){
		printf("found\n");
	}
	
	separator("3");
	
	deleteElem(A, 43);
	
	deleteElem(A, 20);
	
	deleteElem(A, 21);
	
	deleteElem(A, 40);
	
	displayDict(A);
	
	separator("END");
	return 0;
}
