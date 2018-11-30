#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int initializeList(int key, pList xs){
    xs->size = 1;
    
    pElem firstElems = malloc(sizeof(elem));

    
    if(firstElems == NULL){
        printf("Not enough memory!");
        return -1;
    }
    
    printf("hi\n");
    firstElems->key = key;
    firstElems->nextElem = NULL;
    xs->firstElem = firstElems;
    xs->lastElem = firstElems;
    return 0;
}

int insertEnd(int value, pList xs){
    //inserting into an empty list is done via initializeList.
    if(xs->size == 0){
        return initializeList(value, xs);
    }

    //allocate space for new element
    pElem newLast = malloc(sizeof(elem));

    if(newLast == NULL){
        printf("Not enough memory!");
        return -1;
    }

    //instantiate new element
    newLast->key = value;
    newLast->nextElem = NULL;

    //update pointers
    pElem currLast = xs->lastElem;
    currLast->nextElem = newLast;
    xs->lastElem = newLast;
    xs->size++;
    return 0;
}

int insertFront(int value, pList xs){
    //Create new elemnt
    elem new;
    new.key = value;
    new.nextElem = xs->firstElem;

    pElem newFirst = malloc(sizeof(elem));

    if(newFirst == NULL){
        printf("Not enough memory!");
        return -1;
    }
    
    //update lists first element
    newFirst->key = value;
    newFirst->nextElem = xs->firstElem;
    xs->firstElem = newFirst;
    xs->size++;
}

int search(int value, pList xs){

    pElem currElem = xs->firstElem;
    
    //go through list
    while(currElem->nextElem != NULL){
        //if elem found, stop.
        if(currElem->key == value){
            return 1;
        }
        //update pointer
        currElem = currElem->nextElem;
    }
    //this code is only reached if whole list was searched.
    return 0;
}

int removeElem(int key, pList xs){
    return 0;
}

int sort(pList xs){
    return 0;
}

int print(pList xs){

    if(xs->firstElem != NULL){

        pElem currElem = xs->firstElem;

        printf("[%i", currElem->key);
        while(currElem->nextElem != NULL){
           currElem = currElem->nextElem;
           printf(", %i", currElem->key);
        }
        printf("]");
    }
}