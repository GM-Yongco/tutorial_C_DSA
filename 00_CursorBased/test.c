// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "V1.1.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	
	separator("00 INITIALIZE");
	VH A;
	LIST L1 = null;


	init_VH(&A);
	checker(A, L1);
	
	// =======================================================================

	separator("01 INSERT FRIST");
	int i;
	for(i = 0; is_full_VH(A) == FALSE; i++){
		insert_first(&A, &L1, 'a'+i);
	}
	checker(A, L1);

	// =======================================================================

	separator("02 DELETE FIRST");
	delete_first(&A, &L1);
	delete_first(&A, &L1);
	checker(A, L1);

	// =======================================================================

	separator("03 INSERT LAST");
	for(i = 0; is_full_VH(A) == FALSE; i++){
		insert_last(&A, &L1, 'a'+i);
	}
	checker(A, L1);
	
	// =======================================================================

	separator("04 DELETE LAST");
	while(is_empty_VH(A) == FALSE){
		delete_last(&A, &L1);
		display_list(A, L1);
		display_VH(A);
	}
	
	// =======================================================================

	separator("05 INSERT POS");
	for(i = 0; i<3; i++){
		insert_pos(&A, &L1, 'a'+i, 0);
	}
	insert_pos(&A, &L1, '$', 2);
	insert_pos(&A, &L1, '?', 1);
	checker(A, L1);
	
	// =======================================================================

	separator("06 DELETE POS");
	delete_pos(&A, &L1, 2);
	delete_pos(&A, &L1, 1);
	delete_pos(&A, &L1, 1);
	checker(A, L1);

	separator("END");
	return 0;
}