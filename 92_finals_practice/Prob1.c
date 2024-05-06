#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/********************************************************************
 * Data Structure Definition                                        *
 ********************************************************************/
#define MAX_VERTEX    6                  // Maximum number of vertices  
#define SENTINEL      0XFFFF             // A value bigger than any weight  

typedef char  vertexType;               // 'A', 'B', 'C', 'D', 'E', 'F'               
typedef int labelType;

typedef enum{FALSE,TRUE} Boolean;

typedef struct {
	vertexType tail;         // vertex at the tail of the arc or edge  
	vertexType head;         // vertex at the head of the arc or edge  
	int weight;
}edgeType;                  // data type of the list of edges in the file and edge list  

typedef struct {
	vertexType adjVertex;
	int weight;
}adjType;

typedef struct adjNode {
	adjType  info;
	struct adjNode *link;
}*AdjList;

/* Labeled Adjacency list */
typedef struct {
   AdjList head[MAX_VERTEX];       /* Vertices adjacent to Vertex A are stored at index 0, Vertex B at index 1, etc.. */          
   int edgeCount;                  /* Total number of edges in the graph */             
}directedAdjList;

/*Labeled Adjacency Matrix*/
typedef struct{
    labelType matrix[MAX_VERTEX][MAX_VERTEX];
    int edgeCount;
}labeledAdjMatrix;


/**************************************************
 * Function Prototypes                            *
 **************************************************/
/* PROBLEM 1 */
void initDirectedAdjList(directedAdjList *DL);
directedAdjList populateDirectedAdjList();
void displayAdjList(directedAdjList L);

/* PROBLEM 2 */
void initMatrix(labeledAdjMatrix *M);
labeledAdjMatrix convertToMatrix(directedAdjList L);
void displayMatrix(labeledAdjMatrix M);

/* DIJKSTRA'S WITH ADJ LIST*/
int *dijkstras(directedAdjList list, int source);

 int main( ) 
 {	
 
 /*------------------------------------------------------------------------------------
 * 	Problem #1 ::  a) Creates a Labeled Adjacency List via populateDirectedAdjList()  *
 *                 b) Calls displayAdjList().                                         *
 *------------------------------------------------------------------------------------*/
   printf("\n\n\nProblem #1:: "); 
   printf("\n------------"); 
   
   //Write the code for main here
    directedAdjList myList = populateDirectedAdjList();
    displayAdjList(myList);

    printf("\n\n\nProblem #2:: "); 
   printf("\n------------"); 

   labeledAdjMatrix myMatrix = convertToMatrix(myList);
   displayMatrix(myMatrix);


    int sourceVertex = 0, totalCost; // Assuming 'A' is the source vertex
    int *distances = dijkstras(myList, sourceVertex);

    printf("\n\nShortest distances from vertex %c:\n", 'A' + sourceVertex);
    for (int i = 0; i < MAX_VERTEX; i++) {
        if (distances[i] != SENTINEL) {
            printf("Distance to vertex %c: %d\n", 'A' + i, distances[i]);
            totalCost += distances[i];
        } else {
            printf("Distance to vertex %c: INF\n", 'A' + i);
        }
    }

    printf("\nShortest Path: %d\n", totalCost);
    free(distances); // Free the dynamically allocated memory

 
 return 0;
}


 
/************************************************************
 *  Problem 1 Function Definitions                          *
 ************************************************************/ 
void initDirectedAdjList(directedAdjList *DL)
{
	 //Write the code 
    int x;
    for(x=0;x<MAX_VERTEX;x++){
        DL->head[x] = NULL;
    }

	DL->edgeCount=0;
}

directedAdjList populateDirectedAdjList()
{
    directedAdjList newList;
    initDirectedAdjList(&newList);

	const int COUNT = 14;
    edgeType data[] =     {  {'A', 'E', 6}, {'C', 'A', 4}, { 'E', 'C' , 6 },
                             {'A', 'F', 3}, {'C', 'D', 6}, { 'E', 'F' , 6 },
                             {'B', 'A', 4}, {'D', 'A', 8}, { 'F', 'B' , 3 },
                             {'B', 'C', 3}, {'D', 'B', 6}, {'D', 'E', 3}, 
							 {'B', 'E', 6}, {'F', 'D' ,3 }, { 'B', 'F' , 10 }, 
						};
	
    int x;
    AdjList *trav, temp;
    for(x=0;x<=COUNT;x++){
        for(trav = &(newList.head[data[x].tail-'A']); *trav!= NULL && (*trav)->info.adjVertex <= data[x].head; trav=&(*trav)->link){}
        if(*trav==NULL){
            temp=malloc(sizeof(struct adjNode));
            if(temp!=NULL){
                temp->info.adjVertex = data[x].head;
                temp->info.weight= data[x].weight;
                temp->link = *trav;
                *trav= temp;
                newList.edgeCount++;
            }
            
        }
    }

	 return newList;
}

void displayAdjList(directedAdjList L)
{
 	int x;
	AdjList temp;
		
	printf("\n\nThe Adjacency List ::");
	printf("\n%-8s", "VERTEX");
	printf("%-20s", "Adjacent vertices");
	printf("\n%-8s", "------");
	printf("%-20s", "-----------------");
 
	//Write your code here 
    for ( x = 0; x < MAX_VERTEX; ++x) { 
        printf("\n %c :: ", 'A' + x); 
        if (L.head [x] == NULL) {
            printf(" NULL");
        } else {
            for (temp = L.head[x]; temp != NULL; temp= temp->link) {
                printf("%c (%d)\t", temp->info.adjVertex, temp->info.weight);
            }
        }
    }
    printf("\n\nNumber of arcs: %d\n\n", L.edgeCount);
	 
	printf("\n\nPress any key to continue ... ");

 }
 
 /************************************************************
 *  Problem 2 Function Definitions                          *
 ************************************************************/ 

void initMatrix(labeledAdjMatrix *M){
    int x,y;
    for(x=0;x<MAX_VERTEX;x++){
        for(y=0;y<MAX_VERTEX;y++){
            M->matrix[x][y]= SENTINEL;
        }
    }
    M->edgeCount=0;
}

labeledAdjMatrix convertToMatrix(directedAdjList L){

    labeledAdjMatrix myMatrix;
    initMatrix(&myMatrix);

    int x;
    AdjList trav;
    for(x=0;x<MAX_VERTEX;x++){
        for(trav=L.head[x]; trav!=NULL ; trav= trav->link){
            myMatrix.matrix[x][trav->info.adjVertex - 'A'] = trav->info.weight;
            myMatrix.edgeCount++;
        }

    }

    return myMatrix;
}

void displayMatrix(labeledAdjMatrix M){

    int x,y;
    for(x=0;x<MAX_VERTEX;x++){
        printf("\n%c :: ", 'A'+x);
        for(y=0;y<MAX_VERTEX;y++){
            if(M.matrix[x][y] ==  SENTINEL){
                printf("  SENTINEL  ");
            }else{
                printf("   %2d   ", M.matrix[x][y]);
            }
        }
    }

}
 /************************************************************
 *  DIJKSTRAS FOR ADJ LIST                         *
 ************************************************************/ 


int *dijkstras(directedAdjList list, int source) {

    int x, y, min, minIndex;
    int *DISTANCE = (int *)malloc(sizeof(int)*MAX_VERTEX);
    Boolean VISITED[MAX_VERTEX];

    if (DISTANCE != NULL) {
        for (x = 0; x < MAX_VERTEX; x++) {
            DISTANCE[x] = SENTINEL;
            VISITED[x] = FALSE;
        }

        DISTANCE[source] = 0;

        for (x = 0; x < MAX_VERTEX; x++) {
            min = SENTINEL;
            minIndex = -1;
            for (y = 0; y < MAX_VERTEX; y++) {
                if (VISITED[y] == FALSE && DISTANCE[y] < min) {
                    min = DISTANCE[y];
                    minIndex = y;
                }
            }
            VISITED[minIndex] = TRUE;

            for (AdjList trav = list.head[minIndex]; trav != NULL; trav = trav->link) {
                int neighbor = trav->info.adjVertex - 'A';
                if (VISITED[neighbor] == FALSE && DISTANCE[minIndex] + trav->info.weight < DISTANCE[neighbor]) {
                    DISTANCE[neighbor] = DISTANCE[minIndex] + trav->info.weight;
                }
            }
        }
    }

    return DISTANCE;
}
