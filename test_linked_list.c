/*
    Author: WissenIstNacht
    Date: Novemeber 2018 

    This program tests the different functions provided by the module
    linked_list. 


*/

#include <stdio.h>
#include "linked_list.h"

////////////////////////MAIN////////////////////////

int main(int argc, char const *argv[])
{
   /* TEST INSERTIONS */
    list testList  = createList();
    insertFront(3, &testList);
    insertEnd(4, &testList);
    insertFront(2, &testList);
    // print(&testList);
    
    /* longer lists */
    list listAscend = createList();
    list listDescend = createList();
    
    for(int i = 0; i < 10; i++){
        insertEnd(i, &listAscend);
        insertFront(i, &listDescend);
    }
    // print(&listAscend);
    // print(&listDescend);

    /* list containing value several times. */
    list cList = createList();
    for(int i = 0; i < 10; i++){
        
        if(i < 5){
            insertEnd(4, &cList);
        }else{
            insertEnd(2, &cList);
        }
    }


    /* TEST SEARCH */
    /* For presence and absence */
    for(int i = 0; i < 20; i++){
        int p = search(i, &listAscend);
        if(p > 0){
            // printf("Value %i found in position %i\n", i, p);
        }else{
            // printf("Value not in list!\n");
        }
    }

    /* for list with same elements */
    int p = search(4, &cList);
    // printf("Value 3 found in position %i\n", p);
    p = search(2, &cList);
    // printf("Value 3 found in position %i\n", p);


    /* TEST REMOVING */

    /* First position */
    while(removeElement(0, &listAscend) > -1){
        // print(&listAscend);
    }

    /* Last position */
    while(removeElement(listDescend.size-1, &listDescend) > -1){
        // print(&listDescend);
    }

    /* TEST TOARRAY */
    int* testArray = toArray(&testList);
    printf("The value is %i\n", testArray[1]);
    printf("[");
    for(int i = 0; i < 3; i++){;
        printf("%i ", testArray[i]);
    }
    printf("]\n");

    return 0;
}
