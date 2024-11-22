#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int top=-1;
int data[MAX];

int isempty(){
return top==-1;
}

int isfull(){
return top==MAX-1;
}

void push(int element){
if(isfull()){
printf("stack overflow");
return;
}
top++;
data[top] = element;
}

int pop(){
if(isempty()){
printf("Underflow!");
return -1;
}
int popedelement = data[top];
top--;
return popedelement;
}

void display(){
if (isempty()) {
printf("Stack is empty.\n");
return;
}
printf("Elements in the stack:\n");
for(int i=top; i>=0; i--){
printf("%d",data[i]);
}
printf("\n");
}

void palindrome(){
if(isempty()){
printf("Stack is overflow\n");
return;
}
for(int i=0;i<=top/2;i++){
if(data[i]!=data[top-i]){
printf("its not a palindrome!");
return;
}
}
printf("its a palindrome");
}

int main(){
int choice,element;
while(1){
printf("\n1. Push\n2. Pop\n3. Display\n4.Check Palindrome\n5.Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice){
case 1:
printf("Enter the element to push");
scanf("%d", &element);
push(element);
break;
case 2:
element = pop();
if (element != -1) {
printf("The poped element is %d\n",element);
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
printf("Invalid");
}
}
return 0;
}