#include <stdio.h>
#include "linked_list.h"


////////////////////////MAIN////////////////////////

int main(int argc, char const *argv[])
{
    //basic inserts list
    list testList;
    initializeList(3, &testList);
    insertEnd(4, &testList);
    insertFront(2, &testList);
    print(&testList);
    
    //longer lists
    list listAscend;
    list listDescend;
    for(int i = 0; i < 10; i++){
        if(i == 0){
            initializeList(i, &listAscend);
            initializeList(i, &listDescend);
        }else{
            insertEnd(i, &listAscend);
            insertFront(i, &listDescend);
        }
    }
    // print(&listAscend);
    // print(&listDescend);

    //testing search method
    for(int i = 0; i < 20; i++){
        int p = search(i, &listAscend);
        if(p > 0){
            // printf("Value %i found in position %i\n", i, p);
        }else{
            // printf("Value not in list!\n");
        }
    }

    //list containing value several times.
    list cList;
    for(int i = 0; i < 10; i++){
        if(i == 0){
            initializeList(3, &cList);
        }else{
            insertEnd(3, &cList);
        }
    }

    int p = search(3, &cList);
    // printf("Value 3 found in position %i\n", p);

    //removing all values 1 by 1
    while(removeElement(0, &listAscend) > -1){
        print(&listAscend);
    }

    return 0;
}
