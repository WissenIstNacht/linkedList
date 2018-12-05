/*
    Author: WissenIstNacht
    Date: November 2018 

    This module implements a linked list data structure. It provides basic
    functionality such as creation, insertion, deletion as well as other
    function that can be handy when working with lists. So far, only integer key
    are supported.

    A note on working with lists: The module is meant to be use as follows:
    1)  Always start by create a list using the method createList. This method
        returns a list (struct) with size 0 and ptrs set to NULL.
        'list someList = createList();
    2)  Then add/remove elements using insertFront/End and remove Element
        methods.
        'insertX(42, &someList)'
    3)  Since list elements are dynamically allocated delete list after using it.
        'deleteList(&someList)'
*/

#ifndef _LL_H_
#define _LL_H_

typedef struct elem elem, *pElem;
struct elem{
    int key;
    pElem nextElem;
};

typedef struct{
    pElem firstElem;
    pElem lastElem;
    int size;
} list, *pList;


/** Creates empty list.
 * 
 * @param  pList: pointer to list that is created. 
 *          
 * @return 
 * 
 * Sets both ptr fields of the list to NULL and the size to 0.
 */
list createList();

/** Insert first item into empty list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. no more mem, etc,)
 * 
 * Using InsertFront/InsertEnd on a newly declared list leads to a segmentation
 * fault *as one would need dereference a NULL ptr(). This is why this function
 * is called whenever an insertion is made into a list with size 0. It's
 * implementation is simple: Attach a new dynAlloc node to the both of the list
 * pointers (first and lastElement).
 */
static int initializeList(int key, pList xs);

/** Insert item at the end of a list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. no more mem, etc,)
 * 
 * Thanks to the pointer to the last element provided by the list itself, this
 * method can access the end of the list directly and add the item in time O(1).
 */
int insertEnd(int key, pList xs);

/** Insert item at the begining of a list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. no more mem, etc,)
 */
int insertFront(int key, pList xs);

/** Searches for an item in a list.
 * 
 * @param   key: value that's searched.
 *          pList: pointer to list in which the key should be searched. 
 *          
 * @return  i >= 0, position where key was found 
 *          -1 if key was not found.
 * 
 * This method searches the list item by item. Hence it takes linear time.
 * In case a key is in the list multiple times it output the position  where
 * it encounters the key first.
 */
int search(int key, pList xs);

/** Removes an item form the list.
 * 
 * @param   pos: Position in [0,size-1] of element to be deleted.
 *          pList: pointer to list in which the key should be deleted. 
 *          
 * @return   0, if element deleted successfully. 
 *          -1, else (out of bound, etc.).
 * 
 * This method goes to the element in i-th position starting at firstElem whihc
 * has position 0. Redirects necessary pointers and frees memory of item that's
 * removed.
 */
int removeElement(int pos, pList xs);

/** Prints the list
 * 
 * @param   pList: pointer to list in which the key should be deleted. 
 *          
 * @return   0
 * 
 * This method goes to the list and prints each element to the console one by
 * one. The output for a list fo n elements looks as follows:
 *
 *  [e_1, e_2, ..., e_n]
 */
int print(pList xs);

int* toArray(pList xs);
#endif