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

// CHANGE DEPENDING ON THE STRUCTURE
typedef struct{
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
// VH FUNCTIONS 1
// =======================================================================

void init_VH(VH* H){
}
link alloc(VH *H){
}
void dealloc(VH* H, link L){
}

// =======================================================================
// VH FUNCTIONS 1.1
// =======================================================================

boolean is_full_VH(VH H){
}
boolean is_empty_VH(VH H){
}

// =======================================================================
// MISC LIST FUNCTIONS
// =======================================================================

boolean is_empty_LIST(LIST L){
}

// =======================================================================
// LIST FUNCTIONS 1.0
// =======================================================================

void insert_first(VH* H, LIST* L, elem new_data){
}
void insert_last(VH* H, LIST* L, elem new_data){
}
void insert_pos(VH* H, LIST* L, elem new_data, int pos){
}
void delete_last(VH* H, LIST* L){
}
void delete_pos(VH* H, LIST* L, int pos){
}

// =======================================================================
// LIST FUNCTIONS 1.2
// =======================================================================

void display_VH(VH H){
}
void display_list(VH H, LIST L){
}

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void checker(VH H, LIST L){
}