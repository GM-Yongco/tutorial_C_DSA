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
	GRAPH y = init_graph(4);

	separator("ADDING EDGES");
	add_edge(x, 0, 1, 6);
	add_edge(x, 1, 0, 6);
	add_edge(x, 0, 3, 1);
	add_edge(x, 3, 0, 1);

	add_edge(x, 1, 2, 5);
	add_edge(x, 2, 1, 5);
	add_edge(x, 1, 3, 2);
	add_edge(x, 3, 1, 2);
	add_edge(x, 1, 4, 4);
	add_edge(x, 4, 1, 4);

	add_edge(x, 2, 4, 5);
	add_edge(x, 4, 2, 5);
	add_edge(x, 3, 4, 1);
	add_edge(x, 4, 3, 1);
	
	add_edge(x, 4, 7, 2);
	add_edge(x, 7, 4, 2);
	add_edge(x, 4, 5, 5);
	add_edge(x, 5, 4, 5);
	
	add_edge(x, 5, 7, 7);
	add_edge(x, 7, 5, 7);
	add_edge(x, 5, 6, 3);
	add_edge(x, 6, 5, 3);

	add_edge(x, 6, 7, 4);
	add_edge(x, 7, 6, 4);
	
	separator("GRAPH 2");

	add_edge(y, 1, 3, -2);
	add_edge(y, 1, 3, -2);

	separator("PRINTINNG EDGE WEIGHTS");

	int i, j;
	for(j = 0; j<x.size; j++){
		for(i = 0; i<x.size; i++){
			printf("%d, ", get_edge_weight(x, i, j));
		}
		printf("\n");
	}
	

	separator("END");
	return 0;
}
