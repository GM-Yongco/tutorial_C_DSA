// =======================================================================
// Description     : Code that will impress u ;)
// Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
// Date            : ur my date uwu
// =======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "adjacency_list.h"

// =======================================================================
// MAIN
// =======================================================================

int main(){
	separator("START");
	separator("INITIALIZE GRAPH");
	GRAPH x = init_graph(8);

	separator("ADDING EDGES");
	add_edge(x, 0, 1, 1);
	add_edge(x, 0, 2, 1);
	add_edge(x, 0, 6, 1);
	add_edge(x, 0, 7, 1);
	add_edge(x, 1, 3, 1);
	add_edge(x, 1, 4, 1);
	add_edge(x, 2, 6, 1);
	add_edge(x, 2, 7, 1);
	add_edge(x, 3, 4, 1);
	add_edge(x, 4, 5, 1);

	separator("DISPLAYING EDGES");
	display_edges(x);
	
	separator("TRAVERSAL DFS");
	DFS(x, 0);
	separator("TRAVERSAL BFS");
	BFS(x, 0);

	separator("END");
	return 0;
}