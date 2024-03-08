// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	int elem;
	struct node* link;
}NODE, *LINK, *SET;

typedef enum{TRUE, FALSE}BOOL;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void separator(char* message){
	int count = 55; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[1] = '\n';
	new_string[count-3] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 2, message, strlen(message));
	new_string[strlen(message) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void initialize(SET* S){
	*S = NULL;
}

void display_formatted(SET S){
	SET trav;
	printf("\n{");
	for(trav = S; trav != NULL; trav = trav->link){
		printf("%d", trav->elem);
		if(trav->link != NULL){
			printf(", ");
		}
	}
	printf("}\n");
}
void display_raw(SET S){
	display_formatted(S);
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

LINK new_node(int new_elem, LINK next_link){
	LINK temp = (LINK)malloc(sizeof(NODE));
	if(temp != NULL){
		temp->elem = new_elem;
		temp->link = next_link;
	}else{
		printf("failed to allocate");
	}
	return temp;
}
void SET_add(SET* S, int new_elem){
	LINK* trav;
	for(trav = S; 
		*trav != NULL && (*trav)->elem != new_elem;
		trav = &((*trav)->link)){
	}
	if(*trav == NULL){
		*trav = new_node(new_elem, *trav);
	}
}
void SET_remove(SET* S, char check_elem){
	LINK* trav;
	for(trav = S; 
		*trav != NULL && (*trav)->elem != check_elem; 
		trav = &((*trav)->link)){}
	if((*trav) != NULL){
		LINK temp = *trav;
		*trav = (*trav)->link;
		free(temp);
	}else{
		printf("element was not found");
	}
}
SET SET_difference(SET A, SET B){
	LINK TA, TB;
	SET new_set = NULL;
	for(TA = A; TA != NULL; TA = TA->link){
		for(TB = B; 
			TB != NULL && 
			TB->elem != TA->elem; 
			TB = TB->link){}
		if(TB == NULL){
			new_set = new_node(TA->elem, new_set);
		}
	}
	return new_set;
}
SET SET_union(SET A, SET B){
	LINK TA, TB;
	SET new_set = NULL;
	for(TA = A; TA!=NULL; TA = TA->link){
		new_set = new_node(TA->elem, new_set);
	}
	for(TB = B; TB != NULL; TB = TB->link){
		for(TA = A; 
			TA!=NULL && 
			TA->elem != TB->elem; 
			TA = TA->link){}
		if(TA == NULL){
			new_set = new_node(TB->elem, new_set);
		}
	}
	return new_set;
}
SET SET_intersection(SET A, SET B){
	LINK TA, TB;
	SET new_set = NULL;
	for(TB = B; TB != NULL; TB = TB->link){
		for(TA = A; 
			TA!=NULL && 
			TA->elem != TB->elem; 
			TA = TA->link){}
		if(TA != NULL){
			new_set = new_node(TB->elem, new_set);
		}
	}
	return new_set;
}
SET SET_complement(SET A){ // theres no universal set in LL
	return A;
}

// =======================================================================
// CORE FUNCTIONS 3
// =======================================================================

BOOL is_subset(SET A, SET B){
	//if B is a subset of A
	BOOL ret = TRUE;

	LINK TA = A;
	LINK TB;
	for(TB = B; 
		TB != NULL && TA != NULL; 
		TB = TB->link){
		for(TA = A;
			TA!=NULL && TA->elem != TB->elem; 
			TA = TA->link){}
		if(TA == NULL){
			ret = FALSE;
		}
	}
	return ret;
}
BOOL is_elem(SET S, int search_elem){
	LINK TS = S;
	for(TS = S;
		TS != NULL && TS->elem != search_elem; 
		TS = TS->link){}
	return (TS != NULL)?TRUE:FALSE;
}