// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITE 999999

typedef struct NODE{
	int weight;
	struct NODE* next;
}NODE, *LIST;

typedef LIST *GRAPH; 

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
// LL FUNCTIONS
// =======================================================================
LIST LL_allocate(){
	LIST L = (LIST)malloc(sizeof(NODE));
	if(L != NULL){
		L->next = NULL;
		L->weight = INFINITE;
	}else{
		separator("FAILED ALLOCATION");
	}
	return L;
}

void LL_insert_first(LIST* Lp, int new_weight){
	//conditions: ascending order, unique
	LIST* trav;
	for(trav = Lp; 
		(*trav) != NULL 
		&& (*trav)->weight < new_weight; 
		trav = &((*trav)->next)){}

	if((*trav) == NULL || (*trav)->weight >= new_weight){
		LIST new_list = LL_allocate();
		new_list->weight = new_weight;
		new_list->next = *trav;
		*trav = new_list;
	}else{
		printf("\n\nweight is in the list\n\n");
	}
}

// =======================================================================
// GRAPH FUNCTIONS
// =======================================================================
GRAPH init_graph(int node_num){
	GRAPH adj_list = (GRAPH)calloc(node_num, sizeof(LIST));
	return adj_list;
}

void add_edge(int antecedent, int incident, GRAPH G){
	//antecedent is the node that points points
	//incident is the node that is pointed at
	G[antecedent];
}



void display_edges(){

}


// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

void dijkstra();
void floyd();
void warshall();

// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

// =======================================================================
// MINIMUM COST SPANNING TREE
// =======================================================================

