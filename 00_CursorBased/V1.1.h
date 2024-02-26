// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <string.h>

#define MAX 5
#define null -1 

typedef enum{FALSE, TRUE}boolean;

typedef char elem;
typedef int link, LIST;

typedef struct{
	elem data;
	link next;
}node;
typedef struct{
	node elements[MAX];
	LIST avail;
}VH;

// =======================================================================
// MISC FUNCTIONS 1
// =======================================================================

void separator(char* message){
	int count = 55; 				//additional 3 for the (\n)s and the \0
	char new_string[count];

	memset(new_string, '-', count);

	new_string[0] = '\n';
	new_string[1] = '\n';
	new_string[count-2] = '\n';
	new_string[count-3] = '\n';
	new_string[count-1] = '\0';

	memcpy(new_string + 2, message, strlen(message));
	new_string[strlen(message) + 2] = ' ';

	printf("%s", new_string);
}

// =======================================================================
// CORE FUNCTIONS 1
// =======================================================================

void init_VH(VH* H){
	H->avail = 0;
	int i;
	for(i = 0; i < MAX-1; i++){
		H->elements[i].data = 'z';
		H->elements[i].next = i+1;
	}
	H->elements[i].data = 'z';
	H->elements[i].next = null;
}
link alloc(VH *H){
	link allocated = H->avail;
	H->avail = H->elements[H->avail].next;
	return allocated;
}
void dealloc(VH* H, link L){
	H->elements[L].next = H->avail;
	H->avail = L;
}

// =======================================================================
// CORE FUNCTIONS 1.1
// =======================================================================

boolean is_full_VH(VH H){
	return (H.avail == -1)?(TRUE):(FALSE);
}
boolean is_empty_VH(VH H){
	int i;
	link next;
	for(i = 0, next = H.avail;
	 next != null;
	 i++, next = H.elements[next].next){}

	return(i==MAX)?(TRUE):(FALSE);
}

// =======================================================================
// MISC LIST FUNCTIONS
// =======================================================================

boolean is_empty_LIST(LIST L){
	boolean ret_val = FALSE;
	if(L == null){
		ret_val = TRUE;
		printf("\nLIST is empty");
	}else{
		printf("\nLIST is not empty");
	}
	return ret_val;
}

// =======================================================================
// LIST FUNCTIONS 1.0
// =======================================================================

void insert_first(VH* H, LIST* L, elem new_data){
	LIST temp = null;
	temp = alloc(H);
	H->elements[temp].data = new_data;
	H->elements[temp].next = *L;
	*L = temp;
}
void insert_last(VH* H, LIST* L, elem new_data){
	LIST* trav = NULL;
	for(trav = L; *trav != null; trav = &(H->elements[*trav].next)){}
	
	LIST temp = null;
	temp = alloc(H);
	H->elements[temp].data = new_data;
	H->elements[temp].next = null;

	*trav = temp;
}
void insert_pos(VH* H, LIST* L, elem new_data, int pos){
	//should fail if pos is invalid
	//valid is 0 until count of elements in the list inclusive
	int i;
	LIST* trav = NULL;
	for(i = 0,trav = L;
		i < pos && *trav != null;
		i++, trav = &(H->elements[*trav].next)){}
	
	if(i == pos){
		LIST temp = null;
		temp = alloc(H);
		H->elements[temp].data = new_data;
		H->elements[temp].next = *trav;
		*trav = temp;
	}else{
		printf("\ninvalid pos: %d i: %d", pos, i);
	}
}

// =======================================================================
// LIST FUNCTIONS 1.1
// =======================================================================

void delete_first(VH* H, LIST* L){
	if(is_empty_LIST(*L) == FALSE){
		LIST temp = *L;
		*L = H->elements[*L].next;
		dealloc(H, temp);
	}
}
void delete_last(VH* H, LIST* L){

	if(is_empty_LIST(*L) == FALSE){
		LIST* trav;
		for(trav = L;
		 H->elements[*trav].next != null;
		 trav = &(H->elements[*trav].next)){}
		LIST temp = *trav;
		*trav = null;
		dealloc(H, temp);
	}
}
void delete_pos(VH* H, LIST* L, int pos){
	int i;
	LIST* trav;
	for(i=0, trav = L;
		i<pos && *trav != null;
		i++, trav = &(H->elements[*trav].next)){}
	LIST temp = *trav;
	*trav = H->elements[*trav].next;
	dealloc(H, temp);
}

// =======================================================================
// LIST FUNCTIONS 1.2
// =======================================================================

void display_VH(VH H){
	printf("\n\nPRINTING HEAP\n");
	printf("avail: %d\n", H.avail);

	int i;
	for(i = 0; i < MAX; i++){
		printf("%d\tdata[%c]\tnext[%d]\n", i, H.elements[i].data, H.elements[i].next);
	}
}

void display_list(VH H, LIST L){
	if(is_empty_LIST(L) == FALSE){
		printf("\n\nPRINTING LIST");
		printf("\nlist: %d", L);
		link trav = L;
		int i;
		for(i = 0; trav != null; i++){
			printf("\n%d data[%c]", i, H.elements[trav].data);
			trav = H.elements[trav].next;
		}	
	}
}

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void checker(VH H, LIST L){
	if(is_empty_LIST(L) == FALSE){
		
		display_list(H, L);
	}
	display_VH(H);

	if(is_full_VH(H)){
		printf("\nHEAP is full");
	}
	if(is_empty_VH(H)){
		printf("\nHEAP is empty");
	}
}