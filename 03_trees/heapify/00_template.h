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
}

void heapify(LIST* L){
}

// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

int delte_min(LIST* L){
	
}

void delete_min_loop(LIST* L){
}






























