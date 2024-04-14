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

// =======================================================================

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}NODE, *LIST;

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
	// not null means the element exists already
	if(*trav == NULL){
		LIST new_node = (LIST)malloc(sizeof(NODE));
		new_node->data = new;
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
	
	
	if(*trav == NULL){
		printf("\nelement not found\n");
	}else{//assume element is found here
		LIST temp = *trav;
	
		if((*trav)->left != NULL && (*trav)->right != NULL){
			//getting biggest of left(BOL)
			LIST* BOL = &((*trav)->left);
			while((*BOL)->right != NULL){
				BOL = &((*trav)->right);
			}
			
			//swap BOL with trav
			(*BOL)->left = (*trav)->left;
			(*BOL)->right = (*trav)->right;
			
		}else if((*trav)->left != NULL){
			*trav = (*trav)->left;
		}else if((*trav)->right != NULL){
			*trav = (*trav)->right;
		}
		free(temp);
	}
}
