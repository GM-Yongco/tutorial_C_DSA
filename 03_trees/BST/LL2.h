// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// rules			:
//		use snake case
//		all user defined typedefs should be all caps
// =======================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================================================================
typedef enum{FALSE, TRUE}BOOLEAN;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE, *LIST;

// =======================================================================
// MISC FUNCTIONS
// =======================================================================

void separator(char* message){
	int count = 55; 				//additional 5 for the (\n)s and the \0
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

//BST insertion
void list_insert(LIST* L, int I){
	LIST* trav = L;
	
	// finding place to put it
	while(*trav != NULL && (*trav)->data != I){
		if( (*trav)->data < I){
			trav = &((*trav)->right);
		}else{
			trav = &((*trav)->left);
		}
	}
	
	// putting it in
	// not null means the element exists already ie. dont put in duplicates
	if(*trav == NULL){
		LIST new_node = (LIST)malloc(sizeof(NODE));
		new_node->data = I;
		new_node->left = NULL;
		new_node->right = NULL;
		*trav = new_node;
	}
}

void list_display(LIST L){		//in order
	if(L != NULL){
		list_display(L->left);
		printf("%d ", L->data);
		list_display(L->right);
	}
}

// =======================================================================
// CORE FUNCTIONS 2
// =======================================================================

void list_delete_elem(LIST* L, int I){
	LIST* trav = L;
	
	// finding the element
	while(*trav != NULL && (*trav)->data != I){
		if( (*trav)->data < I){
			trav = &((*trav)->right);
		}else{
			trav = &((*trav)->left);
		}
	}
	
	//	deleting the element iff
	if(*trav == NULL){
		printf("\nelement not found\n");
	}else{//assume element is found here
		LIST temp = *trav;
	
		//if one child/no child
		if((*trav)->left == NULL){
			*trav = (*trav)->right;
		}else if((*trav)->right == NULL){
			*trav = (*trav)->left;
		}else{
			//if both children exist
			//getting biggest of left(BOL)
			LIST* BOL = &((*trav)->left);
			while((*BOL)->right != NULL){
				BOL = &((*BOL)->right);
			}

			LIST tempL = (*BOL)->left;		//get attributes of BOL
			*trav = *BOL; 					//make BOL new head
			//give BOL attributes of old head
			(*BOL)->left = temp->left;		
			(*BOL)->right = temp->right;
			*BOL = tempL;					//correct old BOL connection
		}
		free(temp);
	}
}
