

struct Node
{
    int number;
    Node* next;
};

struct List
{
    Node* next;
};

List* mallocList()
{
    List* newList = malloc(sizeof(List));

    newList->next = NULL;

    return newList;
}

void printList(List* myList)
{

}

int main()
{
    List* myList = mallocList();

    printList(myList);

    insertFront(myList, 1);
    insertFront(myList, 4);
    insertFront(myList, 15);
    insertFront(myList, 16);
    insertFront(myList, 81);
    insertFront(myList, 51);
    insertFront(myList, 61);
    insertFront(myList, 331);
    insertFront(myList, 671);
    insertFront(myList, 21);

    printList(myList);

    eraseFront(myList);
    eraseBack(myList);

    printList(myList);

    Node* node = findList(myList, 81);

    printf("Found node with number %d\n", node->number);

    insert(node, 82);

    printList(myList);

    freeList(myList);

    return 0;
}




