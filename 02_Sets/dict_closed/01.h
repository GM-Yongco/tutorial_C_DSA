// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 10
#define EMPTY -1
#define DELETED -2

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
	memset(D, EMPTY, MAX*sizeof(char));
}

void displayDict(Dict D){
	int i;
	for(i = 0; i<MAX; i++){
		if(D[i] == -1){
			printf("EMPTY");
		}else if(D[i] == -2){
			printf("DELETED");
		}else{
			printf("%c", D[i]);
		}
		printf("\n");
	}
}

int hashDict(char elem){
	char insert_elem[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int insert_hash[] = {3, 9, 4, 3, 9, 0, 1, 3, 0, 3};
	
	int i;
	for(i = 0; 
	i < MAX &&
	insert_elem[i] != elem;
	i++){}
	
	return (insert_elem[i] == elem)?(insert_hash[i]):(-1);
}


// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void insert(Dict D, char elem){
	int hash = hashDict(elem);
	
	if(hash != -1){			
		int i;
		int count;
		for(i = hash, count = 0; 
			D[i] != EMPTY && count<MAX && D[i] != elem;
			i = (i+1) % MAX, count++){}
		
		//means the thingy doesnt exist yet
		//insert if not full
		if(D[i] != elem){		
			for(i = hash, count = 0; 
				D[i] != DELETED && D[i] != EMPTY && count<MAX;
				i = (i+1) % MAX, count++){}
			if(count != MAX){
				D[i] = elem;
			}
		}
	}
}


BOOL is_member(Dict D, char elem){
	
	int hash = hashDict(elem);
	BOOL returneee = FALSE;
	if(hash != -1){			
		int i;
		int count;
		for(i = hash, count = 0; 
			D[i] != EMPTY && count<MAX && D[i] != elem;
			i = (i+1) % MAX, count++){}
		if(D[i] == elem){
			returneee = TRUE;
		}
	}
	
	return returneee;
}


void deleteDict(Dict D, char elem){
	int hash = hashDict(elem);
	
	if(hash != -1){
		int i;
		int count;
		for(i = hash, count = 0; 
			D[i] != EMPTY && count<MAX && D[i] != elem;
			i = (i+1) % MAX, count++){}
		if(D[i] == elem){
			D[i] = DELETED;
		}
	}
	
}