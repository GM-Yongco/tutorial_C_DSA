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
	int** weight;
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
	G->weight = (int**)malloc(sizeof(int*)* node_num);
	
	for(i = 0; i<node_num; i++){
		G->weight[i] = (int*)malloc(sizeof(int)* node_num);
	}
	for(i = 0; i<node_num; i++){
		for(j = 0; j<node_num; j++){
			G->weight[i][j] = INFINITE;
		}
	}
	
	return G;
}

void add_edge(GRAPH G, int new_antecedent, int new_incident, int new_weight){
	G->weight[new_antecedent][new_incident] = new_weight;
}

void display_edges(GRAPH G){
	int i, j;
	for(i = 0; i<G->size; i++){
		printf("\n%d -> ", i);
		for(j = 0; j<G->size; j++){
			if(G->weight[i][j] != INFINITE){	
				printf("(%d: %d), ", j, G->weight[i][j]);
			}
		}
	}
}


// =======================================================================
// SHORTEST PATH ALGOS
// =======================================================================

void dijkstra(GRAPH G, int antecedent){
	int weights[G->size];
	BOOLEAN found_min_cost[G->size];
	memset(weights, INFINITE, sizeof(int)*(G->size));
	memset(found_min_cost, FALSE, sizeof(BOOLEAN)*(G->size));
	weights[antecedent] = 0;
	
	int x, y, z;
	int min, min_incident;

	//get the shortest path for each of the verticies
	//cuz every itteration gets us a shotest path for one vertex
	for(x = 0; x < G->size; x++){
		min = INFINITE;

		//itterate through all the verticies we know the weights of
		for(y = 0; y < G->size; y++){
			if(found_min_cost[y] == FALSE && weights[y]<min){
				min = weights[y];
				min_incident = y;
			}
		}

		found_min_cost[min_incident] = TRUE;

		//itterate through all the incidents of newly found shortest path
		for(z = 0; z < G->size; z++){
		if(G->weight[min_incident][z] != INFINITE){
			//replace if the newly found shortest path to z is shorter than the distance we know of rn
			if(found_min_cost[z] == FALSE && 
				weights[z] > weights[min_incident] + G->weight[min_incident][z]){
				weights[z] = weights[min_incident] + G->weight[min_incident][z];
			}
		}
		}
	}
	//at this point, all the weights should be min cost

	//printing
	printf("%d -> ", antecedent);
	for(x = 0; x< G->size; x++){
		printf("(%d, %d), ", x, weights[x]);
	}
}

void floyd_warshal(GRAPH G){
	GRAPH smol = init_graph(G->size);
	int i, j, k;

	for(i = 0; i<G->size; i++){
		G->weight[i][i] = 0;
	}
	for(i = 0; i<G->size; i++){
	for(j = 0; j<G->size; j++){
		smol->weight[i][j] = G->weight[i][j];
	}
	}
	for(k = 0; k<G->size; k++){
	for(i = 0; i<G->size; i++){
	for(j = 0; j<G->size; j++){
		if(smol->weight[i][j]  > smol->weight[i][k] + smol->weight[k][j]){
			smol->weight[i][j] = smol->weight[i][k] + smol->weight[k][j];
		}
	}
	}
	}

	display_edges(smol);
}

// =======================================================================
// TRAVERSALS
// =======================================================================

void DFS_loop(GRAPH G, int antecedent, BOOLEAN* traversed){
	traversed[antecedent] = TRUE;
	int i;
	for(i = 0; i<G->size; i++){
		if(G->weight[antecedent][i] != INFINITE && traversed[i] == FALSE){
			printf("(%d, %d)", antecedent, i);
			DFS_loop(G, i, traversed);
		}
	}
}

void DFS(GRAPH G, int antecedent){
	BOOLEAN* traversed = (BOOLEAN*)malloc(sizeof(BOOLEAN) * G->size);
	memset(traversed, FALSE, sizeof(BOOLEAN)*G->size);
	DFS_loop(G, antecedent, traversed);
}

typedef struct QUEUE{
	int* arr;
	int top;//dequeue here
	int bot;//enqueue here
}QUEUE;

void BFS(GRAPH G, int antecedent){
	
}

// =======================================================================
// MINIMUM COST SPANNING TREE
// =======================================================================

void prims(GRAPH G){

}
void kruskal(){

}