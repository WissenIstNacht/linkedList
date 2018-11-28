#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int insertLast(int value, pList xs){
    //create new element
    elem new;
    new.key = value;
    new.nextElem = NULL; 

    //allocate space for it
    pElem newLast = malloc(sizeof(elem));

    if(newLast != NULL){
        //update previous last element to point to new last element
       pElem currLast = xs->lastElem;
       currLast->nextElem = newLast;
        //update list's 'last' pointer to hold new element
       xs->lastElem = newLast;
       xs->size++;
       return 0;
    }else{
        printf("Not enough memory!");
        return -1;
    }
}

int insertFirst(int value, pList xs){
    //Create new elemnt
    elem new;
    new.key = value;
    new.nextElem = xs->firstElem;

    pElem newFirst = malloc(sizeof(elem));

    if(newFirst != NULL){
        //update lists first element
        xs->firstElem = newFirst;
        xs->size++;
    }else{
        printf("Not enough memory!");
        return -1;
    }
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