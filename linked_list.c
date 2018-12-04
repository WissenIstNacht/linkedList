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
    int k = 0;
    //go through list
    while(currElem->nextElem != NULL){
        //if elem found, stop.
        if(currElem->key == value){
            return k;
        }
        //update pointer
        currElem = currElem->nextElem;
        k++;
    }
    
    return 0;
}

int removeElement(int pos, pList xs){
    int n = xs->size;

    //check validity of position (incl. that list be non empty)
    if(pos < 0 || pos >= n){
        printf("Position out of bounds or list empty!\n");
        return -1;
    }

    // Different procedure depending on list size.
    if(n==1){
        //for one item first=last. List empty afterwards.
        pElem firstItem = xs->firstElem;
        xs->firstElem = NULL;
        xs->lastElem = NULL;
        free(firstItem);
    }
    //for two elements only simply redirect lists first/last pointer
    else if(n==2){
        if(pos == 0){
            pElem firstItem = xs->firstElem;
            xs->firstElem = xs->lastElem;
            free(firstItem);
        }else{
            pElem lastItem = xs->lastElem;
            xs->lastElem = xs->firstElem;
            xs->firstElem->nextElem = NULL;
            free(lastItem);
        }
    }
    //if list larger need to traverse to element...
    else{
        pElem lItem = xs->firstElem;    //needed for traversing
        pElem mItem = lItem->nextElem;
        int k = 1;
        //...except for first elemnt
        if(pos == 0){
            xs->firstElem = mItem;
            free(lItem);
        }else{
            //travese        
            while(k < pos){
                lItem = mItem;
                mItem = mItem->nextElem;
                k++;
            }
            //elements in middle of the list deleted differently than at end.
            if(pos == n-1){
                xs->lastElem = lItem;
                lItem->nextElem = NULL;
                free(mItem);
            }else{
                lItem->nextElem = mItem->nextElem;
                free(mItem);
            }
        }
    }
    xs->size--;
    return 0;
}

int sort(pList xs){
    return 0;
}

int print(pList xs){
    if(xs->size == 0){
        printf("[]\n");
    }

    if(xs->firstElem != NULL){
        pElem currElem = xs->firstElem;

        printf("[%i", currElem->key);
        while(currElem->nextElem != NULL){
           currElem = currElem->nextElem;
           printf(", %i", currElem->key);
        }
        printf("]\n");
    }
}
