/*
Description     : Code that will impress u ;)
Author          : G.M. Yongco #BeSomeoneWhoCanStandByShinomiya
Date            : ur my date uwu
*/
#include <stdio.h>
#include <stdlib.h>

#include "01.h"

int main(){
	separator("START");
	
	// =======================================================================
	// INIT & INSERT
	// =======================================================================
    int given[] = {6, 2, 9, 4, 2, 0, 5, 10, 8, 1, 12, 4, 3, 19, -1, -2};
    int given_count = 15;
    
    LIST x = NULL;
    
    int i;
    for(i = 0; i<=given_count; i++){
    	list_insert(&x, given[i]);	
	}
    list_display(x);
    printf("\n");
    
	// =======================================================================
	// DELETE 1
	// =======================================================================
	list_delete_elem(&x, -1);
    list_display(x);   
    printf("\n"); 
	
	// =======================================================================
	// DELETE 2
	// =======================================================================
	list_delete_elem(&x, 12);
	list_display(x);    
	
	// =======================================================================
	// DELETE 3
	// =======================================================================
	list_delete(&x, 6);
	ist_display(x);    

	// =======================================================================	
	separator("END");
    return 0;
}
