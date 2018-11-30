#include <stdio.h>
#include "linked_list.h"


////////////////////////MAIN////////////////////////

int main(int argc, char const *argv[])
{
    list testList;
    initializeList(3, &testList);
    insertEnd(4, &testList);
    insertFront(2, &testList);
    print(&testList);
    

    return 0;
}
