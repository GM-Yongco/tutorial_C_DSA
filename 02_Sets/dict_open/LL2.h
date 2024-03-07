// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
typedef struct node{
	int elem;
	struct node* link;
}*LIST;
typedef LIST Dict[MAX];

typedef enum{FALSE, TRUE}BOOL;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void separator(char* message){
	int count = 53; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[count-2] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 1, message, strlen(message));
	new_string[strlen(message) + 1] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void initDict(Dict D){
	int i;
	for(i = 0; i<MAX; i++){
		D[i] = NULL;
	}
}

void displayDict(Dict D){
	LIST trav;
	
	int i;
	for(i = 0; i < MAX; i++){
		trav = D[i];
		printf("\n[%d]", i);
		
		
		if(trav == NULL){
			printf("EMPTY");
		}else{
			while(trav != NULL){
				printf("%d ", trav->elem);
				trav = trav->link;
			}
		}
	}
}

int hash(int elem){
	return elem%MAX;
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

LIST* ppn_trav_to_elem(LIST* START, int elem){
	//if elem is not found, will return the address of the last link
	LIST* trav;
	for(trav = START; 
		*trav != NULL && (*trav)->elem < elem; 
		trav = &((*trav)->link)){}
	return trav;
}

void insert(Dict D, int elem){
	LIST* trav;
	for(trav = &(D[hash(elem)]); 
		*trav != NULL && (*trav)->elem < elem; 
		trav = &((*trav)->link)){}
	
	LIST temp = NULL;
	temp = (LIST)malloc(sizeof(struct node));
	
	//condition 1 to check malloc
	//condition 2 to check if reached the end of the list
	//c 2 also checks to 
	if(temp != NULL && //check malloc
		(*trav == NULL ||
		(*trav)->elem != elem)){
		temp->elem = elem;
		temp->link = *trav;
		*trav = temp;
	}
}

BOOL isMember(Dict D, int elem){
	LIST trav;
	for(trav = D[hash(elem)]; 
		trav != NULL && trav->elem < elem; 
		trav = trav->link){}
		
	return (trav != NULL && trav->elem == elem)?(TRUE):(FALSE);
}

void deleteElem(Dict D, int elem){
	LIST* trav;
	for(trav = &(D[hash(elem)]); 
		*trav != NULL && (*trav)->elem < elem; 
		trav = &((*trav)->link)){}
		
	if(*trav != NULL && (*trav)->elem == elem){
		LIST temp;
		temp = *trav;
		*trav = (*trav)->link; 
		free(temp);
	}
}