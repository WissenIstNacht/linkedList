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

/** Insert first item into empty list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. element already in tree, no more mem, etc,)
 * 
 * In an empty list the other insertion functions would lead to a segmentation fault.
 * This is why this function is called whenever an insertion is made into a list with size 0.
 * It0s implementation is simple: Attach a new dynAllc node to the both of the list pointers
 * (first and lastElement).
 */
int initializeList(int key, pList xs);

/** Insert item at the end of a list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. element already in tree, no more mem, etc,)
 * 
 * Thanks to the pointer to the last element provided by the list itself, this method
 * can access the end of the list directly and add the item in time O(1).
 */
int insertEnd(int key, pList xs);

/** Insert item at the begining of a list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. element already in tree, no more mem, etc,)
 */
int insertFront(int q, pList xs);

/** Searches for an item in a list.
 * 
 * @param   key: key th.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. element already in tree, no more mem, etc,)
 */
int search(int key, pList xs);

int removeElem(int key, pList xs);

int print(pList xs);

int sort(pList xs);

#endif