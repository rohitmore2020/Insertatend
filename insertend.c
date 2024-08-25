#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* nextNode;
};

struct Node* insertAtEnd(struct Node* headNode) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the new node to insert at the end: ");
    scanf("%d", &newNode->value);
    newNode->nextNode = NULL; 
    struct Node* tempNode = headNode; 
    while(tempNode->nextNode != NULL) {
        tempNode = tempNode->nextNode; 
    }
    tempNode->nextNode = newNode; 
    return headNode; 
}

int main() {
    int nodeCount;
    printf("Enter the number of nodes  to insert in the linked list: ");
    scanf("%d", &nodeCount);

    struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value of the first node of the linked list: ");
    scanf("%d", &headNode->value);
    headNode->nextNode = NULL;
    struct Node* currentNode = headNode;

    int counter = 1;
    while (counter < nodeCount) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter the value of the new node: ");
        scanf("%d", &newNode->value);
        newNode->nextNode = NULL;
        currentNode->nextNode = newNode;
        currentNode = currentNode->nextNode;
        counter++;
    }

    printf("Here is our linked list:\n");

    currentNode = headNode;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");

    headNode = insertAtEnd(headNode);

    printf("linked list after the insertion:\n");

    currentNode = headNode;
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->value);
        currentNode = currentNode->nextNode;
    }
    printf("NULL\n");

    return 0;
}
