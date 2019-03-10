/******************************************************************************
    Author: WissenIstNacht
    Date: November 2018 

    This module implements a linked list data structure. It provides basic
    functionality such as creation, insertion, deletion as well as other
    function that can be handy when working with lists. So far, only integer
    keys are supported.

    How does one work with lists? The module is meant to be used as follows:
    
    1)  Always start by creating a list using the method createList. This
        method returns a list (struct) with size 0 and ptrs set to NULL:

        list someList = createList();

    2)  Then add or remove elements using the respective function:
        methods.

        prepend(42, &someList)
        prepend(42*42, &someList)
        remove()

    3)  Since list elements are dynamically allocated delete list after using
        it.
    
        deleteList(&someList)

******************************************************************************/

#ifndef _LL_H_
#define _LL_H_

typedef struct elem elem, *pElem;
struct elem{
    int key;
    pElem nextElem;
};

typedef struct{
    pElem head;
    pElem tail;
    int size;
} list, *pList;


/** Create empty list with both ptr fields of the NULL and size 0.
 * 
 * @param  pList: pointer to list that is created. 
 *          
 * @return  list: Struct representing empty list.
 */
list createList();

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
int append(int key, pList xs);

/** Insert item at the begining of a list.
 * 
 * @param   key: key to be inserted.
 *          pList: pointer to list into which key should be inserted. 
 *          
 *          
 * @return  1 if the insertion was successful,
 *          -1 if not (e.g. no more mem, etc,)
 */
int prepend(int key, pList xs);

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

/** Removes all items form the list.
 * 
 * @param   pList: pointer to list in which the key should be deleted. 
 *          
 * @return   0, if elements deleted successfully. 
 *          -1, else.
 * 
 * This method goes through all elements one by one deleting them. It frees the memory of the
 * allocated nodes and sets the head and tail pointer NULL.
 */
void removeAll(pList xs);

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
void print(pList xs);

/** Outputs the list as an array
 * 
 * @param   pList: pointer to list in which the key should be deleted. 
 *          
 * @return  *ptr:   Address to first array entry
 * 
 * This method puts every key in the list into an array. It does so by starting
 * at head and ending at tail.
 *
 *  [e_1, e_2, ..., e_n]
 */
int* toArray(pList xs);

/** Merges two lists into one\n
 * 
 * @param   pList: pointer to list in which the key should be deleted. 
 *          
 * @return  nothing to return
 * 
 * Merging the lists means that the first element of ys gets appended to the
 * (last element of) list xs. In particular this means that ys no longer exists
 * and xs gets modified.
 */
void mergeLists(pList xs, pList ys);

/** Removes the list and all its items.
 * 
 * @param   pList: pointer to list to be deleted
 *          
 * @return   0, if list deleted successfully. 
 *          -1, else.
 * 
 * This method first deletes all elements, then
 */
void removeList(pList xs);

#endif