// =======================================================================
// Description     : Code that will impress u ;)
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
	
	if((parent_index*2) + 1 <= L->lastNdx){								//if parent_index is not leaf
		//get bigger child (innitially left child)
		int big_child_index = (parent_index*2) + 1;
			
		if(big_child_index + 1 <= L->lastNdx &&							//if right_child_index exists
			L->elem[big_child_index + 1] >= L->elem[big_child_index]){	//if big child index(left) is bigger or equal to right child index
			big_child_index++;
		}
		if(L->elem[big_child_index] > L->elem[parent_index]){			//compare with parent then swap
			int temp = L->elem[big_child_index];
			L->elem[big_child_index] = L->elem[parent_index];
			L->elem[parent_index] = temp;
			
			//reccursive with the swapped child index
			heapify_subtree(L, big_child_index);
		}
	}
}

void heapify(LIST* L){
	
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

int delte_min(LIST* L){
	
}

void delete_min_loop(LIST* L){
	int old_lastNdx = L->lastNdx;
	
	while(L->lastNdx > -1){
		//swap with bottom of the list
		int temp = L->elem[0];
		L->elem[0] = L->elem[L->lastNdx];
		L->elem[L->lastNdx] = temp;
		
		//ignore the last element
		L->lastNdx--;
		
		heapify_subtree(L, 0);
	}
	L->lastNdx = old_lastNdx;
}






























