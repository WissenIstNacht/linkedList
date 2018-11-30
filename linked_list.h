#ifndef _LL_H_

#define _LL_H_


typedef struct elem elem, *pElem;
typedef struct elem{
    int key;
    pElem nextElem;
};

typedef struct{
    pElem firstElem;
    pElem lastElem;
    int size;
} list, *pList;

int initializeList(int key, pList xs);

int insertEnd(int key, pList xs);

int insertFront(int key, pList xs);

int search(int key, pList xs);

int removeElem(int key, pList xs);

int print(pList xs);

int sort(pList xs);

#endif