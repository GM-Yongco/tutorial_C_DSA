// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INFINITE 999999

typedef enum{FALSE, TRUE}BOOLEAN;

typedef struct NODE{
	int weight;
	int incident;
	struct NODE* next;
}NODE, *LIST;

typedef struct GRAPH{
	LIST* adj_list;
	int size;
}GRAPH;
//assumed the graph nodes are 0->(n-1)

typedef struct{
	LIST bot;
	LIST top;
}*QUEUE;
//top of the line, bot of the line
//enqueue at top
//dequeue at the bot
//LL starts at the bot 
//im sorry for the confusion

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
		L->incident = INFINITE;
		L->weight = INFINITE;
	}else{
		separator("FAILED ALLOCATION");
	}
	return L;
}

void LL_insert_sorted(LIST* Lp, int new_incident, int new_weight){
	//conditions: ascboting order, unique
	LIST* trav;
	for(trav = Lp; 
		(*trav) != NULL 
		&& (*trav)->incident < new_incident; 
		trav = &((*trav)->next)){}

	if((*trav) == NULL || (*trav)->incident >= new_incident){
		LIST new_list = LL_allocate();
		new_list->incident = new_incident;
		new_list->weight = new_weight;
		new_list->next = *trav;
		*trav = new_list;
	}else{
		separator("INCIDENT NOT UNIQUE ");
	}
}

// =======================================================================
// QUEUE FUNCTIONS
// =======================================================================

QUEUE init_queue(){
	QUEUE Q = (QUEUE)calloc(1, sizeof(LIST)*2);
	return Q;
}

BOOLEAN is_empty(QUEUE Q){
	return (Q->top == NULL)?(TRUE):(FALSE);
}

BOOLEAN is_present(QUEUE Q, int compare_incident){
	LIST trav;
	for(trav = Q->bot; 
		trav != NULL 
		&& trav->incident == compare_incident; 
		trav = trav->next){}
	(trav != NULL)?(TRUE):(FALSE);
}

void display_queue(QUEUE Q){
	LIST trav;
	printf("\n");
	for(trav = Q->top; trav != NULL; trav = trav->next){
		printf("%d-", trav->incident);
	}
}

// =======================================================================
// QUEUE FUNCTIONS 2
// =======================================================================

void enqueue(QUEUE Q, int new_incident, int new_weight){
	LIST new_list = LL_allocate();
	new_list->incident = new_incident;
	new_list->weight = new_weight;

	if(is_empty(Q) == TRUE){
		Q->top = new_list;
		Q->bot = new_list;
	}else{
		Q->bot->next = new_list;
		Q->bot = new_list;
	}
}

LIST dequeue(QUEUE Q){
	LIST ret = NULL;
	if(is_empty(Q) == FALSE){
		ret = Q->top;
		Q->top = Q->top->next;
	}
	if(Q->top == NULL){
		Q->bot = NULL;
	}
	return ret;
}

// =======================================================================
// GRAPH FUNCTIONS
// =======================================================================
GRAPH init_graph(int node_num){
	GRAPH x;
	LIST* adjacency_list = (LIST*)calloc(node_num, sizeof(LIST));
	if(adjacency_list == NULL){
		separator("FAILED ALLOCATION");
	}
	x.adj_list = adjacency_list;
	x.size = node_num;

	return x;
}

void add_edge(GRAPH G, int new_antecedent, int new_incident, int new_weight){
	//antecedent is the node that is pointing
	//incident is the node that is pointed at

	if(new_antecedent >= G.size){
		printf("\nINVALID ANTECEDENT %d >= graph_size (%d)", new_antecedent, G.size);
	}else if(new_antecedent < 0){
		printf("\nINVALID ANTECEDENT %d < 0", new_antecedent);
	}else if(new_incident >= G.size){
		printf("\nINVALID INCIDENT %d >= graph_size (%d)", new_antecedent, G.size);
	}else if(new_incident < 0){
		printf("\nINVALID INCIDENT %d < 0", new_incident);
	}else{
		LL_insert_sorted(&(G.adj_list[new_antecedent]), new_incident, new_weight);
	}
}

void display_edges(GRAPH G){
	int i;
	for(i = 0; i < G.size; i++){
		LIST trav;
		printf("\n%d ->", i);
		for(trav = G.adj_list[i]; trav != NULL; trav = trav->next){
			printf("node:%d weight:%d,", trav->incident, trav->weight);
		}
	}
}


// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

void dijkstra();
void floyd();
void warshall();

// =======================================================================
// TRAVERSALS
// =======================================================================

void DFS_loop(GRAPH G, BOOLEAN* traversed, int antecedent){
	traversed[antecedent] = TRUE;
	LIST trav;
	for(trav = G.adj_list[antecedent];
		trav != NULL; 
		trav = trav->next){
		if(traversed[trav->incident] == FALSE){
			printf("(%d, %d)", antecedent, trav->incident);
			DFS_loop(G, traversed, trav->incident);
		}
	}
}

void DFS(GRAPH G, int top_antecedent){
	BOOLEAN traversed[G.size];
	memset(traversed, FALSE, sizeof(BOOLEAN)*(G.size));

	int i = top_antecedent;
	do{
		if(traversed[i] == FALSE){
			DFS_loop(G, traversed, i);
		}
		i = (i+1) % G.size;
	}while(i != top_antecedent);
	//reference cyclical queue for better for loop later
}

void BFS(GRAPH G, int top_antecedent){
	QUEUE Q = init_queue();
	enqueue(Q, top_antecedent, 0);

	BOOLEAN traversed[G.size];
	memset(traversed, FALSE, sizeof(BOOLEAN)*(G.size));
	traversed[top_antecedent] = TRUE;

	LIST trav;
	while(is_empty(Q) == FALSE){
		LIST temp = dequeue(Q);
		int antecedent = temp->incident;
		free(temp);

		for(trav = G.adj_list[antecedent];
			trav != NULL; 
			trav = trav->next){
			if(traversed[trav->incident] == FALSE){
				printf("(%d, %d)", antecedent, trav->incident);
				enqueue(Q, trav->incident, 0);
				traversed[trav->incident] = TRUE;
			}
		}
	}	
}

// =======================================================================
// MINIMUM COST SPANNING TREE
// =======================================================================

