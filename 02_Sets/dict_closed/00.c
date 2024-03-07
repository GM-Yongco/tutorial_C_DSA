// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

//#include "00.h"
//#include "01.h"
///#include "02.h"
#include "03.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");

	Dict A;
	
	initDict(A);
	displayDict(A);

	printf("\nhash of e is %d\n", hashDict('e'));

//	printf("%d", hashDict('a'));

	separator("2");

	char insertee = 'a';
	while(insertee < 'g'){
		insert(A, insertee);
		insertee++;
	}

	insertee = 'a';
	while(insertee < 'g'){
		insert(A, insertee);
		insertee++;
	}

	displayDict(A);
	
	insertee = 'a';
	while(insertee < 'z' + 1){
		printf("\n%c is ", insertee);
		if(is_member(A, insertee) == TRUE){
			printf("found");
		}else{
			printf("not found");
		}
		insertee++;
	}
	
	separator("3");

	deleteDict(A, 'a');
	deleteDict(A, 'd');
	deleteDict(A, 'z');
	deleteDict(A, 'y');

	displayDict(A);
	
	separator("END");
	return 0;
}
