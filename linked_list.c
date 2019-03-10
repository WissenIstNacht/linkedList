#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

list createList(){
    list xs;

    xs.head = NULL;
    xs.tail = NULL;
    xs.size = 0;

    return xs;
}

/** Inserts FIRST element into EMPTY list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to EMPTY list into which key should be inserted. 
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. no more mem, etc,).
 * 
 * Putting the first element into a list requires special treatment of null
 * pointers in the empty list. This function does just that. Note that it is a
 * private function that is only called by prepend or append.  
 */
static int initializeList(int key, pList xs){
    //allocatae new node
    pElem firstItem = malloc(sizeof(elem));
    
    if(firstItem == NULL){
        printf("Not enough memory!");
        return -1;
    }
    
    //initialize new node
    firstItem->key = key;
    firstItem->nextElem = NULL;

    //update listpointers
    xs->head = firstItem;
    xs->tail = firstItem;
    xs->size++;

    return 0;
}

int append(int value, pList xs){
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
    pElem currLast = xs->tail;
    currLast->nextElem = newLast;
    xs->tail = newLast;
    xs->size++;
    
    return 0;
}

int prepend(int value, pList xs){
    //inserting into an empty list is done via initializeList.
    if(xs->size == 0){
        return initializeList(value, xs);
    }

    pElem newFirst = malloc(sizeof(elem));

    if(newFirst == NULL){
        printf("Not enough memory!");
        return -1;
    }
    
    //update lists first element
    newFirst->key = value;
    newFirst->nextElem = xs->head;
    xs->head = newFirst;
    xs->size++;

    return 0;
}

int search(int value, pList xs){
    pElem currElem = xs->head;
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
        pElem firstItem = xs->head;
        xs->head = NULL;
        xs->tail = NULL;
        free(firstItem);
    }
    //for two elements only simply redirect lists first/last pointer
    else if(n==2){
        if(pos == 0){
            pElem firstItem = xs->head;
            xs->head = xs->tail;
            free(firstItem);
        }else{
            pElem lastItem = xs->tail;
            xs->tail = xs->head;
            xs->head->nextElem = NULL;
            free(lastItem);
        }
    }
    //if list larger need to traverse to element...
    else{
        pElem lItem = xs->head;    //needed for traversing
        pElem mItem = lItem->nextElem;
        int k = 1;
        //...except for first elemnt
        if(pos == 0){
            xs->head = mItem;
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
                xs->tail = lItem;
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

void removeAll(pList xs){
    int n = xs->size;
    
    if(n == 0){
        return;
    }

    pElem currItem = xs->head;
    pElem nextItem = currItem->nextElem;

    while(nextItem != NULL){
        free(currItem);
        currItem = nextItem;
        nextItem = currItem->nextElem;
    }

    free(currItem);
    xs->size = 0;
    xs->head = NULL;
    xs->tail = NULL;
}

void print(pList xs){
    if(xs->size == 0){
        printf("[]\n");
    }else{
        pElem currElem = xs->head;

        printf("[%i", currElem->key);
        while(currElem->nextElem != NULL){
           currElem = currElem->nextElem;
           printf(", %i", currElem->key);
        }
        printf("]\n");
    }
}

int* toArray(pList xs){
    int n = xs->size;

    if(n ==0){
        printf("List is empty!");
        return NULL;
    }

    int* ptr;
    ptr = malloc(sizeof(int)*n);

    if(ptr == NULL){
        printf("Not enough memory!");
        return NULL;
    }
    
    
    pElem currItem = xs->head;
    *ptr = currItem->key;
    unsigned int k = 1;
    
    while(currItem->nextElem != NULL){
        currItem = currItem->nextElem;
        *(ptr + k) = currItem->key;
        k++;
    }
    
    return ptr;
}

void mergeLists(pList xs, pList ys){
    xs->tail = ys->head;
    xs->size += ys->size;
    free(ys);
}

void removeList(pList xs){
    removeAll(xs);
    free(xs);
}

