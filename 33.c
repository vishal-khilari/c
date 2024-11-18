#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int top = -1;
int data[MAX_SIZE];
int isEmpty() {
return top == -1;
}
int isFull() {
return top == MAX_SIZE - 1;
}
void push(int element) {
if (isFull()) {
printf("Stack overflow!\n");
return;
}
top++;
data[top] = element;
}
int pop() {
if (isEmpty()) {
printf("Stack underflow!\n");
return -1;
}
int poppedElement = data[top];
top--;
return poppedElement;
}
void display() {
if (isEmpty()) {
printf("Stack is empty.\n");
return;
}
printf("Elements in the stack:\n");
for (int i = top; i >= 0; i--) {
printf("%d ", data[i]);
}
printf("\n");
}
void palindrome() {
int i;
for(i=0;i<=top;i++)
if(data[i]!=pop()) {
printf("\nIt is not a palindrome\n");
return;
}
printf("\nIt is a Palindrome\n");
}


int main() {
int choice, element;
while (1) {
printf("\n1. Push\n2. Pop\n3. Display\n4.Check Palindrome\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter element to push: ");
scanf("%d", &element);
push(element);
break;
case 2:
element = pop();
if (element != -1) {
printf("Popped element: %d\n", element);
}
break;
case 3:
display();
break;
case 5:
exit(0);
case 4:
palindrome();
break;
default:
printf("Invalid choice!\n");
}
}
return 0;
}