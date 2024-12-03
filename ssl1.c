#include <stdio.h>
#include <stdlib.h>
struct node 
{
    char usn[25], name[25], branch[25];
    int sem;
    long int phone;
    struct node *link;
};
typedef struct node *NODE;
NODE start = NULL;
int count = 0;
NODE create()
 {
    NODE snode = (NODE)malloc(sizeof(struct node));
    if (!snode) {
        printf("\nMemory not available");
        exit(1);
    }
    printf("\nEnter USN, Name, Branch, Sem, Phone: ");
    scanf("%s %s %s %d %ld", snode->usn, snode->name, snode->branch, &snode->sem, &snode->phone);
    snode->link = NULL;
    count++;
    return snode;
}

NODE insertfront() {
    NODE temp = create();
    temp->link = start;
    return temp;
}

NODE deletefront() {
    if (!start) {
        printf("\nLinked list is empty");
        return NULL;
    }
    NODE temp = start;
    start = start->link;
    printf("\nDeleted node USN: %s", temp->usn);
    free(temp);
    count--;
    return start;
}

void display() {
    if (!start) {
        printf("\nSLL is empty");
        return;
    }
    printf("\nContents of SLL:\n");
    NODE cur = start;
    int num = 1;
    while (cur) {
        printf("\n%d. USN: %s | Name: %s | Branch: %s | Sem: %d | Phone: %ld", 
               num++, cur->usn, cur->name, cur->branch, cur->sem, cur->phone);
        cur = cur->link;
    }
    printf("\nTotal nodes: %d", count);
}

void stackdemo() {
    int ch;
    while (1) {
        printf("\n\n--- Stack Demo ---\n1: Push\n2: Pop\n3: Display\n4: Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: start = insertfront(); break;
            case 2: start = deletefront(); break;
            case 3: display(); break;
            case 4: return;
            default: printf("\nInvalid choice");
        }
    }
}

int main() {
    int ch, n;
    while (1) {
        printf("\n\n--- Menu ---\n1: Create SLL\n2: Display\n3: Stack Demo\n4: Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nNumber of nodes: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) start = insertfront();
                break;
            case 2: display(); break;
            case 3: stackdemo(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice");
        }
    }
}
