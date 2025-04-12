#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node {
    char ssn[25], name[25], dept[10], designation[25];
    int sal;
    long int phone;
    struct node *llink;
    struct node *rlink;
};
typedef struct node *NODE;
NODE first = NULL;
int count = 0;
NODE create() {
    NODE enode = (NODE)malloc(sizeof(struct node));
    if (enode == NULL) {
        printf("\nError: Memory allocation failed.\n");
        exit(1);
    }
    printf("\nEnter the SSN, Name, Department, Designation, Salary, and Phone Number of the employee: ");
    if (scanf("%s %s %s %s %d %ld", enode->ssn, enode->name, enode->dept,
              enode->designation, &enode->sal, &enode->phone) != 6) {
        printf("\nError: Invalid input.\n");
        free(enode);
        return NULL;
    }
    enode->llink = NULL;
    enode->rlink = NULL;
    count++;
    return enode;
}
NODE insertfront() {
    NODE temp = create();
    if (temp == NULL) return first;
    if (first == NULL) {
        return temp;
    }
    temp->rlink = first;
    first->llink = temp;
    return temp;
}
void display() {
    NODE cur = first;
    int nodeno = 1;
    if (cur == NULL) {
        printf("\nThe doubly linked list is empty.\n");
        return;
    }
    printf("\nContents of the Doubly Linked List:");
    while (cur != NULL) {
        printf("\nNode %d | SSN: %s | Name: %s | Department: %s | Designation: %s | Salary: %d | Phone: %ld",
               nodeno, cur->ssn, cur->name, cur->dept, cur->designation, cur->sal, cur->phone);
        cur = cur->rlink;
        nodeno++;
    }
    printf("\nTotal number of employee nodes: %d\n", count);
}
NODE deletefront() {
    if (first == NULL) {
        printf("\nError: The list is empty.\n");
        return NULL;
    }
    NODE temp = first;
    if (first->rlink == NULL) { 
        printf("\nThe employee node with SSN: %s is deleted.\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }
    first = first->rlink;
    first->llink = NULL;
    printf("\nThe employee node with SSN: %s is deleted.\n", temp->ssn);
    free(temp);
    count--;
    return first;
}
NODE insertend() {
    NODE temp = create();
    if (temp == NULL) return first;
    if (first == NULL) {
        return temp;
    }
    NODE cur = first;
    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->rlink = temp;
    temp->llink = cur;
    return first;
}
NODE deleteend() {
    if (first == NULL) {
        printf("\nError: The list is empty.\n");
        return NULL;
    }
    NODE cur = first;
    if (first->rlink == NULL) { 
        printf("\nThe employee node with SSN: %s is deleted.\n", first->ssn);
        free(first);
        count--;
        return NULL;
    }

    while (cur->rlink != NULL) {
        cur = cur->rlink;
    }
    cur->llink->rlink = NULL;
    printf("\nThe employee node with SSN: %s is deleted.\n", cur->ssn);
    free(cur);
    count--;
    return first;
}
void deqdemo() {
    int ch;
    while (1) {
        printf("\n--- Double Ended Queue Operations ---");
        printf("\n1: Insert Front");
        printf("\n2: Delete Front");
        printf("\n3: Insert Rear");
        printf("\n4: Delete Rear");
        printf("\n5: Display");
        printf("\n6: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                first = insertfront();
                break;
            case 2:
                first = deletefront();
                break;
            case 3:
                first = insertend();
                break;
            case 4:
                first = deleteend();
                break;
            case 5:
                display();
                break;
            case 6:
                return;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}
int main() {
    int ch, n, i;
    while (1) {
        printf("\n--- Main Menu ---");
        printf("\n1: Create Employee List");
        printf("\n2: Display List");
        printf("\n3: Insert at End");
        printf("\n4: Delete from End");
        printf("\n5: Insert at Front");
        printf("\n6: Delete from Front");
        printf("\n7: Double Ended Queue Demo");
        printf("\n8: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter the number of employees: ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    first = insertend();
                }
                break;
            case 2:
                display();
                break;
            case 3:
                first = insertend();
                break;
            case 4:
                first = deleteend();
                break;
            case 5:
                first = insertfront();
                break;
            case 6:
                first = deletefront();
                break;
            case 7:
                deqdemo();
                break;
            case 8:
                printf("\nExiting the program. Cleaning up memory.\n");
                while (first != NULL) {
                    first = deletefront();
                }
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }
}