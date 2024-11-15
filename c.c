#include <stdio.h>
#include <stdlib.h>
struct Node {
    int row;         
    int col;        
    int value;        
    struct Node* next; 
};
struct Node* createNode(int row, int col, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->row = row;
    newNode->col = col;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void printSparseMatrix(struct Node* head) {
    struct Node* temp = head;
    printf("Row  Col  Value\n");
    while (temp != NULL) {
        printf("%d    %d    %d\n", temp->row, temp->col, temp->value);
        temp = temp->next;
    }
}

int main() {
    struct Node* head = createNode(0, 2, 5);
    head->next = createNode(1, 1, 3);
    head->next->next = createNode(2, 0, 7);
    printSparseMatrix(head);
    return 0;
}