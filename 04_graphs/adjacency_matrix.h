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

typedef struct{
	int** node;
	int size;
}*GRAPH, MATRIX;

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
// GRAPH FUNCTIONS
// =======================================================================
GRAPH init_graph(int node_num){
	int i, j;
	GRAPH G = (GRAPH)malloc(sizeof(MATRIX));
	G->size = node_num;
	G->node = (int**)malloc(sizeof(int*)* node_num);
	
	for(i = 0; i<node_num; i++){
		G->node[i] = (int*)malloc(sizeof(int)* node_num);
	}
	for(i = 0; i<node_num; i++){
		for(j = 0; j<node_num; j++){
			G->node[i][j] = INFINITE;
		}
	}
	
	return G;
}

void add_edge(GRAPH G, int new_antecedent, int new_incident, int new_weight){
	G->node[new_antecedent][new_incident] = new_weight;
}

void display_edges(GRAPH G){
	int i, j;
	for(i = 0; i<G->size; i++){
		printf("\n%d -> ", i);
		for(j = 0; j<G->size; j++){
			if(G->node[i][j] != INFINITE){	
				printf("(%d: %d), ", j, G->node[i][j]);
			}
		}
	}
}


// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

void dijkstra(GRAPH G, int antecedent){
	int distances[G->size];
	memset(distances, INFINITE, sizeof(int)*(G->size));
	distances[antecedent] = 0;
	
	
}

void floyd_warshal(GRAPH G){}

// =======================================================================
// TRAVERSALS
// =======================================================================

void DFS(GRAPH G, int top_antecedent){
	struct list{
		int arr[G->size];
		int top;
	}list;
	list.top = -1;
	BOOLEAN traversed[G->size];
	memset(
	
	
	list.arr[++list.top] = top_antecedent;
	
	
}

void BFS(GRAPH G, int top_antecedent){}

// =======================================================================
// MINIMUM COST SPANNING TREE
// =======================================================================

void kruskal(){}
void prims(){}