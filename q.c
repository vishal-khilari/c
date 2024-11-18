#include<stdio.h>
#define MAX 4
int ch, front = 0, rear = -1, count=0; char q[MAX], item;
void insert()
{
if(count == MAX)
printf("\nQueue is Full");
else
{
rear = (rear + 1) % MAX; q[rear]=item;
count++;
}
}
void del()
{
if(count == 0)
printf("\nQueue is Empty");
else
{
item=q[front];
printf("\nDeleted item is: %c",item);
if(front == rear)
{
front=0;
rear=-1;
count=0;
}
else
{
front = (front + 1) % MAX;
count--;
}
}
}
void display()
{
int i, f=front, r=rear; if(count == 0)
printf("\nQueue is Empty");
else
{
printf("\n Contents of Queue\n");
for(i=f; i<=r; i++)
{
printf("%c\t", q[i]);
f = (f + 1) % MAX;
}
}
}
void main() {
do
{
printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit"); printf("\nEnter the choice: ");
scanf("%d", &ch); switch(ch)
{
case 1: printf("\nEnter the character / item to be inserted: ");
scanf("%c", &item);
insert();
break;
case 2: del();
break;
case 3: display(); break;
case 4: exit(0);
}
}while(ch!=4);
getch();
}