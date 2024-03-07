// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define DELETED '@'
#define EMPTY '!'

typedef char Dict[MAX];
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
// CORE FUNCTIONS
// =======================================================================

void initDict(Dict D){
	int i;
	for(i = 0; i<MAX; i++){
		D[i] = EMPTY;
	}
}

void displayDict(Dict D){
	int i;
	for(i = 0; i<MAX; i++){
		printf("\n[%d] %c", i, D[i]);
	}
}

int hashDict(char elem){
	char insert_elem[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int insert_hash[] = {3, 9, 4, 3, 9, 0, 1, 3, 0, 3};
	
	int i;
	for(i = 0; 
		i<sizeof(insert_elem)/sizeof(insert_elem[0]) && 
		elem != insert_elem[i]; 
		i++){}
		
	return (insert_elem[i] == elem)?(insert_hash[i]):(-1);
}


// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================


BOOL is_member(Dict D, char elem){
	int hash = hashDict(elem);
	
	if(hash != -1){
		int search_count = 0;
		while(search_count<MAX && D[hash] != EMPTY && D[hash] != elem){
			hash = (hash + 1) % MAX;
			search_count++;
		}
	}
	return(hash != -1 && D[hash] == elem)?(TRUE):(FALSE);
}

void insert(Dict D, char elem){
	int hash = hashDict(elem);
	
	if(hash != -1 && is_member(D, elem) == FALSE){
		
		
		int search_count = 0;
		while(D[hash] != EMPTY && D[hash] != DELETED && search_count<MAX){
			hash = (hash + 1) % MAX;
			search_count++;
		}
		if(search_count!= MAX){
			D[hash] = elem;
		}
	}
}


void deleteDict(Dict D, char elem){
	int hash = hashDict(elem);
	if(hash != -1){
		int search_count = 0;
		while(search_count<MAX && D[hash] != EMPTY && D[hash] != elem){
			hash = (hash + 1) % MAX;
			search_count++;
		}
	}
	
	if(hash != -1 && D[hash] == elem){
		 D[hash] = DELETED;
	}
}