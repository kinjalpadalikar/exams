
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node* next;
} Node;

typedef struct List
{
    struct Node* next;
} List;

List* mallocList()
{
    List* newList = malloc(sizeof(List));

    newList->next = NULL;

    return newList;
}

void printList(List* myList)
{
    printf("[");

    Node* currentNode = myList->next;

    while(currentNode != NULL)
    {
        int number = currentNode->number;

        printf("%d ", number);

        currentNode = currentNode->next;
    }

    printf("]\n");
}

void freeList(List* myList)
{
    Node* currentNode = myList->next;

    while(currentNode != NULL)
    {
        Node* previousNode = currentNode;

        currentNode = currentNode->next;

        free(previousNode);
    }

}

void insertFront(List* myList, int newNumber)
{
    Node* node = malloc(sizeof(Node));

    node->number = newNumber;
    node->next   = myList->next;

    myList->next = node;
}

void removeFront(List* myList)
{
    Node* currentNode = myList->next;
    
    Node* previousNode = currentNode;

    currentNode = currentNode->next;

    free(previousNode);

    myList->next = currentNode;
 
   
}

// DON'T MODIFY ANYTHING IN MAIN

int main()
{
    List* myList = mallocList();

    printList(myList); // []

    insertFront(myList, 21);
    insertFront(myList, 671);
    insertFront(myList, 331);
    insertFront(myList, 61);
    insertFront(myList, 51);
    insertFront(myList, 81);
    insertFront(myList, 16);
    insertFront(myList, 15);
    insertFront(myList, 4);
    insertFront(myList, 1);

    printList(myList); // [1 4 15 16 81 51 61 331 671 21]

    removeFront(myList);

    printList(myList); // [ 4 15 16 81 51 61 331 671 21]

/*
    eraseBack(myList);

    printList(myList); // [16 81 51 61 331 671]

    Node* node = findList(myList, 81);

    printf("Found node with number %d\n", node->next->number);

    insert(node, 82);

    printList(myList); // [16 81 82 51 61 331 671]
*/
    freeList(myList);

    return 0;
}





