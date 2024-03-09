/******************************************************************
 * Project Name:  List, Set and Dictionary                        *
 * Programmer  :  Put your Name here                              *
 * Date Completed: March 25, 2023                                 *
 ******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VH_SIZE     0XC    //size of Virtual Heap
#define OPEN_DSIZE  0XA    //size of Open Hash Table
#define CLOSE_DSIZE 0XC    //size of Close Hash Table
#define LIST_SIZE   0XF    //size of the array implementation of List
/******************************************************************************
 * Data Structure Definition:                                                 *
 ******************************************************************************/
typedef struct {  
	char name[24];          // Chocolate name  
 	int  weight;            // Chocolate weight in grams  
}chocoDesc;
 
typedef struct {
   char prodID[8];          //  product ID uniquely identifies the products; EMPTY or DELETED   
  	chocoDesc prodDesc;     //  product description 
 	float prodPrice;        //  product price 
  	int prodQty;            //  product count or quantity   
}product;                   //  product record  

typedef struct {
	product elem;            
	int next;                
}prodNode;                 // Product node, used in cursor-based implementation of Set  


/************************
 * Virtual Heap         *
 ************************/
typedef struct {
   prodNode VH_node[VH_SIZE];
   int avail;
}VHeap;

/******************************************
 * Cursor-Based Implementation of SET     *
 ******************************************/
typedef struct {
   int elemIndex;        // index of the 1st element in the set  
   int count;            // holds the actual number of elements in the set  
   VHeap *VHptr;         // holds the pointer to the virtual heap  
}cursorSet;            

/********************************************
 * Open Hashing Implementation of Dictionary*
 ********************************************/
typedef struct {
	int header[OPEN_DSIZE];  // array of sets   
	int count;               // total number of elements in the dictionary  
	VHeap *dicVHptr;         // holds the pointer to the virtual heap  
}openDic;


/**********************************************
 * Closed Hashing with 2 pass loading          *
 **********************************************/
#define EMPTY   "empty"     // stored in product ID field  
#define DELETED  "del"      // stored in product ID field * 
 
typedef product closeDic[CLOSE_DSIZE];   //Definition of the closed hash dictionary
  
typedef struct {
	product prod[LIST_SIZE];
	int last;   //index of the last element; -1 if list is empty	
}List;



/**********************************************************
 * Function Prototypes                                    *
 *********************************************************/
//---Problem #1 ---
void initVHeap(VHeap *VH);
cursorSet initCursorSet(VHeap *VH);
void displayVHeap(VHeap V);
void displaySet(cursorSet A);

//---Problem #2 ---
int mallocInVHeap(VHeap *VH);
void insertSorted(cursorSet *A, product P);
void populateSet(cursorSet *A);

//---Problem #3 ---
int openHash(char *IDen);                
openDic initOpenDict(VHeap *VH);
openDic convertToOpenDict(cursorSet *A);
void displayOpenDict(openDic D);

//---Problem #4 ---
void freeInVHeap(VHeap *VH, int ndx);
void deleteDict(openDic *D, char *IDen);

//---Problem #5 ---
int closeHash(char *ID);
void initCloseDict(closeDic CD);
closeDic * convertToCloseDict(openDic *D);	
void displayCloseDict(closeDic CD);


 
/************************************************************************************
 * READ ME FIRST before ANSWERING                                                   *
 *   1)  To facilitate the checking of the machine problem, follow the instructions *
 *       in each PROBLEM #.                                                         *
 *   2)  To accomplish the task for each PROBLEM, a series of function calls may be *
 *       necessary.                                                                 *  
 *   3)  Write you answer BELOW THE COMMENTS. DO NOT DELETE COMMENTS                *
 *                                                                                  *
 ***********************************************************************************/
 int main( ) 
 {	
 /*---------------------------------------------------------------------------------
 * 	Problem #1 ::  1) Initializes the virtual heap and the cursor Set             *
 *                 2) Displays the contents  virtual heap and cursor Set          *
 *--------------------------------------------------------------------------------*/
 	printf("\n\n\nProblem #1:: "); 
 	printf("\n------------");
 	//Declare variables needed for Problem #1
	VHeap VH1;
	initVHeap(&VH1);
 	cursorSet CS1 = initCursorSet(&VH1);
	
 	//Function Calls for Problem #1
	displayVHeap(VH1);
	displaySet(CS1);

/*---------------------------------------------------------------------------------
 * 	Problem #2 ::  1) Populates the Cursor set which is sorted in ascending order *
 *                    according to ID                                             *
 *                 2) Displays the Cursor set                                     * 
 *--------------------------------------------------------------------------------*/	 
 	printf("\n\n\nProblem #2:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #2
	
 	//Function Calls for Problem #2
	populateSet(&CS1);
	displaySet(CS1);
/*---------------------------------------------------------------------------------
 * 	Problem #3 ::  1) Converts the Cursor set into an Open Hash Dictionary        *      
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the empty Cursor set.                              * 
 *--------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #3:: "); 
 	printf("\n------------");
	//Declare variables needed for Problem #3
 	openDic OD;
	
 	//Function Calls for Problem #3
	
	OD = convertToOpenDict(&CS1);
	displayOpenDict(OD);
	displaySet(CS1);
 

/*---------------------------------------------------------------------------------
 * 	Problem #4 ::  1) Perform 3 delete operations on the Open Hash Dictionary     *
 *                 2) Displays the Open Hash Dictionary                           *
 *                 3) Displays the Virtual Heap                                   * 
 *--------------------------------------------------------------------------------*/	
 	printf("\n\n\nProblem #4:: "); 
 	printf("\n------------");	
 //Declare variables needed for Problem #4
    char delete01[] = "1703";
    char delete02[] = "1358";    
	char delete03[] = "1601";
	
 
//Function Calls for Problem #4	
	deleteDict(&OD, delete01);
	deleteDict(&OD, delete02);
	deleteDict(&OD, delete03);
    displayOpenDict(OD);
	displayVHeap(VH1);
    

/*------------------------------------------------------------------------------------
 * 	Problem #5 :: 1) Converts the Open Hash Dictionary into a Closed Hash Dictionary *
 *                2) Displays the Closed Hash Dictionary                             * 
 *                3) Displays the virtual heap                                       *
 *---------------------------------------------------------------------------------*/	
	printf("\n\n\nProblem #5:: ");
    printf("\n------------");
    //Declare variables needed for Problem #5
    closeDic* CD = convertToCloseDict(&OD);
    
    //Function Calls for Problem #5
	// displayCloseDict(*CD);
	// displayVHeap(VH1);
	// commented out cuz i wanna see the before and after second pass

	return 0;
}

/************************************************************
 *  Problem 1:: Function Definitions                          *
 ************************************************************/
 void initVHeap(VHeap *V)
 {
 	V->avail = VH_SIZE - 1;
	int i;
	for(i = VH_SIZE - 1; i>=0; i--){
		V->VH_node[i].next = i-1;
		strcpy(V->VH_node[i].elem.prodID, "default");
		strcpy(V->VH_node[i].elem.prodDesc.name, "default");
		V->VH_node[i].elem.prodDesc.weight = -1;

		V->VH_node[i].elem.prodPrice = -1;
		V->VH_node[i].elem.prodQty = -1;
	}
 }

cursorSet initCursorSet(VHeap *VH)
{
	cursorSet temp;
	temp.count = 0;
	temp.elemIndex = -1;
	temp.VHptr = VH;

	return temp;
}

void displayVHeap(VHeap V)
{
	//Variable Declaration here
	int i,j;

    printf("\n\nDetails of the Virtual Heap :: ");
    printf("\n------------------------------");
    printf("\nAvailable Index  ::  %d", V.avail  );       //Complete this statement
	printf("\nVHeap Address    ::  %d" , &V.VH_node );       //Complete this statemet
	
    printf("\n\n%10s", "Index");
    printf("%10s", "Prod ID");
    printf("%15s", "Next Field");
	printf("\n%10s%10s%15s", "-----", "-------","----------");	
     
    //Write your code here 
	 for(i=0; i<VH_SIZE; i++){
	 	printf("\n\t%d \t%s\t %d",i, V.VH_node[i].elem.prodID , V.VH_node[i].next);
	 }
	 

	printf("\n\n"); system("Pause");
}

void displaySet(cursorSet A)
{
	int x;
	product p;
	
	printf("\n\nDetails of the Set :: ");
	printf("\n---------------------");
	printf("\nNo. of elements ::  %d", A.count );      //Complete this code
	printf("\nFirst index\t::  %d", A.elemIndex );      //ADDED FOR CONVENIENCE
	printf("\n\n%-7s", "ID");
	printf("%-12s","Choco Name");
	printf("%-15s","Choco Weight");
	printf("%-10s","VHeap Index");
	printf("\n%-7s%-12s%-15s%-10s", "--", "----------", "------------", "-----------");

	//Write your code here
	int i;
	for(i = A.elemIndex; i >= 0; i = A.VHptr->VH_node[i].next){
		printf("\n%-7s%-12s%-15d%-10d", A.VHptr->VH_node[i].elem.prodID, A.VHptr->VH_node[i].elem.prodDesc.name, A.VHptr->VH_node[i].elem.prodDesc.weight, i);
	}

	printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 2:: Function Definitions                         *
 ************************************************************/
int mallocInVHeap(VHeap *VH)
{
	int old_avail = VH->avail;
	if(old_avail >= 0){
		VH->avail = VH->VH_node[VH->avail].next;
	}
	return old_avail;
}


void insertSorted(cursorSet *A, product P)
{
	int* trav;
	for(trav = &(A->elemIndex);
		*trav != -1
		&& strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) < 0 ;
		trav = &(A->VHptr->VH_node[*trav].next)){}

	if(strcmp(A->VHptr->VH_node[*trav].elem.prodID, P.prodID) != 0){
		int temp = mallocInVHeap(A->VHptr);
		if(temp != -1){
			A->VHptr->VH_node[temp].elem = P;
			A->VHptr->VH_node[temp].next = *trav;
			*trav = temp;
			
			A->count++;
		}
	}
}

void populateSet(cursorSet *A)
{
	const int COUNT = 15;
	product data[] = { 	{"1701", {"Toblerone", 135}, 150.75, 20},
						{"1356", {"Ferrero", 200}, 250.75, 85},
						{"1109", {"Patchi", 50}, 99.75, 35},
						{"1550", {"Cadbury", 120}, 200.00, 30},
						{"1807", {"Mars", 100}, 150.75, 20},
						{"1201", {"Kitkat", 50}, 97.75, 40},
						{"1450", {"Ferrero", 100},150.50, 50},
						{"1701", {"Toblerone", 50}, 90.75, 80},
						{"1601", {"Meiji", 75}, 75.50, 60},
						{"1310", {"Nestle", 100}, 124.50, 70},
						{"1807", {"Valor", 120}, 149.50, 90},
						{"1455", {"Tango", 75}, 49.50, 100},
						{"1703", {"Toblerone", 100}, 125.75, 60},
						{"1284", {"Lindt", 100}, 250.75, 15},
						{"1688", {"Guylian", 50}, 99.75, 35},
					
		              };
    //Inserts each element of the array to the cursor set
    //Write your code here!!
	int i;
	for(i = 0; i<15; i++){
		insertSorted(A, data[i]);
	}
}



/************************************************************
 *  Problem 3:: Function Definitions                        *
 ************************************************************/
int openHash(char * prodID)               
{ 
    return (prodID[3]%OPEN_DSIZE);
}


openDic initOpenDict(VHeap *VH)
{
	openDic ret;

	ret.count = 0;
	ret.dicVHptr = VH;
	int i;
	for(i = 0; i<OPEN_DSIZE; i++){
		ret.header[i] = -1;
	}

	return ret;
}

openDic convertToOpenDict(cursorSet *A)
{
	openDic ret = initOpenDict(A->VHptr);
	
	int trav = A->elemIndex;
	int old_trav;
	int hash;
	while(trav > -1){
		old_trav = trav;
		trav = A->VHptr->VH_node[trav].next;

		hash = openHash(A->VHptr->VH_node[old_trav].elem.prodID);
		A->VHptr->VH_node[old_trav].next = ret.header[hash];
		ret.header[hash] = old_trav;

		ret.count++;
	}
	A->count = 0;
	A->elemIndex = -1;

	return ret;
}



void displayOpenDict(openDic D)
{
	//Variable declaration here 
	
	printf("\n\nDetails of the Open Hash Dictionary:: ");
	printf("\n-------------------------------------");
	
	printf("\nNo. of elements :: %d", D.count);
	printf("\n\n%-7s", "GROUPS");
	printf("%15s","ID Numbers");
	printf("\n%-7s%15s", "------","----------");
	
	//Write your code here
	int i;
	int j;
	for(i = 0;i<OPEN_DSIZE; i++){
		for(j = D.header[i]; j > -1; j = D.dicVHptr->VH_node[j].next ){
			printf("\n%-7d%15s", i, D.dicVHptr->VH_node[j].elem.prodID);
		}
	}

    printf("\n\n"); system("Pause");	
}


/************************************************************
 *  Problem 4:: Function Definitions                        *
 ************************************************************/
void freeInVHeap(VHeap *VH, int ndx)
{
	VH->VH_node[ndx].next = VH->avail;
	strcpy(VH->VH_node[ndx].elem.prodID, "free");
	VH->avail = ndx;
}

void deleteDict(openDic *D, char *IDen)
{
	int* trav;
	for(trav = &(D->header[openHash(IDen)]); 
		*trav != -1
		&& strcmp(D->dicVHptr->VH_node[*trav].elem.prodID , IDen) != 0; 
		trav = &(D->dicVHptr->VH_node[*trav].next)){}
	if(*trav != -1){
		int temp = *trav;
		*trav = D->dicVHptr->VH_node[*trav].next;
		freeInVHeap(D->dicVHptr, temp);
		(D->count)--;
	}
}


 /************************************************************
 *  Problem 5:: Function Definitions                        *
 ************************************************************/
int closeHash(char *ID)
{
    //for fun, im gonna use the name of the chocolte for the hash
	return (ID[0])%LIST_SIZE;
}



void initCloseDict(closeDic CD)
{
	int i;
	product A = {EMPTY, {EMPTY, -1}, -1, -1};
	for(i = 0; i<CLOSE_DSIZE; i++){
		CD[i] = A;
	}
}
 
closeDic * convertToCloseDict(openDic *D)
{
	//2 pass loading this shit for fun and cuz its mentioned sa line 63
    closeDic* ret = (closeDic*)malloc(sizeof(closeDic));
	initCloseDict(*ret);

	int i;//for the head of dict
	int* j;//for the trav of head
	int hash;
	int temp;

	//inital pass
	for(i = 0; i<OPEN_DSIZE; i++){
		j = &(D->header[i]);
		while(*j > -1){
			// hash = closeHash(D->dicVHptr->VH_node[*j].elem.prodDesc.name);
			// for fun lang sad to see the effects of using different hash
			hash = openHash(D->dicVHptr->VH_node[*j].elem.prodID);

			if(strcmp(((*ret)[hash]).prodID, EMPTY) == 0 ){//
				(*ret)[hash] = D->dicVHptr->VH_node[*j].elem;
				temp = *j;
				*j = D->dicVHptr->VH_node[*j].next;
				freeInVHeap(D->dicVHptr, temp);
			}else{
				j = &(D->dicVHptr->VH_node[*j].next);//update/skip
			}
		}
	}
	displayCloseDict(*ret);
	displayVHeap(*(D->dicVHptr));
	//second pass
	int count;
	for(i = 0; i<OPEN_DSIZE; i++){
		j = &(D->header[i]);
		while(*j > -1){
			// hash = closeHash(D->dicVHptr->VH_node[*j].elem.prodDesc.name);
			// for fun lang sad to see the effects of using different hash
			hash = openHash(D->dicVHptr->VH_node[*j].elem.prodID);
			
			for(count = 0; 
				count<CLOSE_DSIZE
				&& strcmp(((*ret)[hash]).prodID, EMPTY) != 0 
				&& strcmp(((*ret)[hash]).prodID, DELETED) != 0; 
				count++, hash = (hash+1)%CLOSE_DSIZE){}

			if(count != CLOSE_DSIZE){
				(*ret)[hash] = D->dicVHptr->VH_node[*j].elem;
				temp = *j;
				*j = D->dicVHptr->VH_node[*j].next;
				freeInVHeap(D->dicVHptr, temp);
			}
		}
	}
	displayCloseDict(*ret);
	displayVHeap(*(D->dicVHptr));

	return ret;
}	

void displayCloseDict(closeDic CD)
{
 	//Variable declaration here
 	
 	
	printf("\n\nDetails of Closed Hash Dictionary :: ");
	printf("\n-------------------------------------");
	printf("\n\n%-6s", "Index");
	printf("%-10s", "ChocoID");
	printf("%-15s", "Choco Name");
	printf("\n%-6s%-10s%-15s", "-----", "-------", "----------"); 
	
	//Write your code here
	int i;
	for(i = 0; i<CLOSE_DSIZE; i++){
		printf("\n%-6d%-10s%-15s", i, CD[i].prodID, CD[i].prodDesc.name); 
	}
	 
	
	printf("\n\n"); system("Pause");
 
}
 
