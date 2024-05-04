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

typedef int GRAPH;

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
GRAPH init_graph(int node_num);

void add_edge(GRAPH G, int new_antecedent, int new_incident, int new_weight);

void display_edges(GRAPH G);


// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

void dijkstra(GRAPH G, int antecedent);

void floyd_warshal();

// =======================================================================
// TRAVERSALS
// =======================================================================

void DFS(GRAPH G, int top_antecedent);

void BFS(GRAPH G, int top_antecedent);

// =======================================================================
// MINIMUM COST SPANNING TREE
// =======================================================================

void kruskal();
void prims();