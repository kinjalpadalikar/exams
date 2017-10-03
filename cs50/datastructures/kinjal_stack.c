
#include <stdio.h>
#include <stdlib.h>


// DON'T MODIFY ANYTHING IN MAIN

int main()
{
    Stack* myStack = mallocStack();

    printStack(myStack); // []

    pushStack(myStack, 21);
    pushStack(myStack, 671);
    pushStack(myStack, 331);

    printStack(myStack); // [331, 671, 21]

    popStack(myStack);

    printStack(myStack); // [671, 21]

    freeStack(myStack);

    return 0;
}





