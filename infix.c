#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
struct Stack {
char data[MAX_SIZE];
int top;
};
void initializeStack(struct Stack *stack) {
stack->top = -1;
}
int isEmpty(struct Stack *stack) {
return stack->top == -1;
}
int isFull(struct Stack *stack) {
return stack->top == MAX_SIZE - 1;
}
void push(struct Stack *stack, char ch) {
if (isFull(stack)) {
printf("Stack Overflow\n");
return;
}
stack->top++;
stack->data[stack->top] = ch;
}
char pop(struct Stack *stack) {
if (isEmpty(stack)) {
printf("Stack Underflow\n");
return '\0';
}
char ch = stack->data[stack->top];
stack->top--;
return ch;
}
int precedence(char ch) {
if (ch == '^')
return 3;
else if (ch == '*' || ch == '/' || ch == '%')
return 2;
else if (ch == '+' || ch == '-')
return 1;
else
return 0;
}
void infixToPostfix(char *infix, char *postfix) {
struct Stack stack;
initializeStack(&stack);
int i, j = 0;
for (i = 0; infix[i] != '\0'; i++) {
if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i]
>=
'A' && infix[i] <= 'Z') || (infix[i] >= '0' &&
infix[i] <=
'9')) {
postfix[j++] = infix[i];
} else if (infix[i] == '(') {
push(&stack, '(');
} else if (infix[i] == ')') {
while (!isEmpty(&stack) && stack.data[stack.top] != '(') {
postfix[j++] = pop(&stack);
}
if (!isEmpty(&stack) && stack.data[stack.top] ==
'(') {
pop(&stack);
} else {
printf("Invalid expression\n");
return;
}
} else {
while (!isEmpty(&stack) && precedence(infix[i]) <=
precedence(stack.data[stack.top])) {
postfix[j++] = pop(&stack);
}
push(&stack, infix[i]);
}
}
while (!isEmpty(&stack)) {
postfix[j++] = pop(&stack);
}
postfix[j] = '\0';
}
int main() {
char infix[MAX_SIZE], postfix[MAX_SIZE];
printf("Enter an infix expression: ");
scanf("%s", infix);
infixToPostfix(infix, postfix);
printf("Postfix expression: %s\n", postfix);
return 0;
}