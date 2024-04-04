// =======================================================================
// Description     : NON-RECURRSIVE VERSION OF HEAPIFY
// Author          : G.M. Yongco #BeSomeoIhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================
#include <stdio.h>
#include <stdlib.h>

// =======================================================================
// MISC DEFINITIONS
// =======================================================================
#define MAX 15
typedef struct {
	int elem[MAX];
	int lastNdx;
}LIST;
typedef enum{FALSE, TRUE}BOOLEAN;
// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void list_innit(LIST* L){
	L->lastNdx = -1;
}

void list_insert(LIST* L, int I){
	if(L->lastNdx < MAX){
		L->elem[++(L->lastNdx)] = I;
	}else{
		printf("full list");
	}
}

void list_display(LIST* L){
	printf("LAST INDEX %d:\t[", L->lastNdx);
	int i;
	for(i = 0; i < L->lastNdx; i++){
		printf("%d, ", L->elem[i]);
	}
	if(L->lastNdx != -1){
		printf("%d ", L->elem[i]);
	}
	printf("]\n");
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void heapify_subtree(LIST* L, int parent_index){
	BOOLEAN is_POT = FALSE;
	while(((parent_index*2)+1 <= L->lastNdx) &&		// while parent index is greater than or equal the lowest parent index. ie. while it is not leaf
		is_POT == FALSE){							// if it didnt swap					
		is_POT = TRUE;
		// get big child =====================================================
		int big_child_index = (parent_index*2) + 1;						//innitially left child
		if(big_child_index + 1 <= L->lastNdx &&							//if right_child_index exists
			L->elem[big_child_index + 1] >= L->elem[big_child_index]){	//if right_child_index has a bigger value
			big_child_index++;
		}
		//swap if ============================================================
		if(L->elem[parent_index] <  L->elem[big_child_index]){
			int temp = L->elem[parent_index];
			L->elem[parent_index] = L->elem[big_child_index];
			L->elem[big_child_index] = temp;

			// update
			parent_index = big_child_index;
			is_POT = FALSE;
		}
	}
}

void heapify(LIST* L){ // note: creates max heap through heapify
	//find parent of lowest
	int lowest_parent;
	for(lowest_parent = ((L->lastNdx)-1) /2;
		lowest_parent > -1;
		lowest_parent--){
		heapify_subtree(L, lowest_parent);
	}
}

// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

int delte_max(LIST* L){
	//swap
	int temp = L->elem[0];
	L->elem[0] = L->elem[L->lastNdx];
	L->elem[L->lastNdx] = temp;

	L->lastNdx--;
	return L->elem[L->lastNdx + 1];
}
void delete_max_loop(LIST* L){
	int old_lastNdx = L->lastNdx;
	while(L->lastNdx > -1){
		delte_max(L);
		heapify_subtree(L, 0);
	}
	L->lastNdx = old_lastNdx;
}






























