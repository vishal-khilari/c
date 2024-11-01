#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Structure to represent a day 
struct Day 
{ 
char *name; 
char *date; 
char *Activity; 
}; 
// Function to create a calendar 
void create(struct Day calendar[7]) 
{ 
for (int i = 0; i < 7; i++) 
{ 
// Dynamically allocate memory for the day name 
calendar[i].name = (char *)malloc(20 * sizeof(char)); 
// Dynamically allocate memory for the date 
calendar[i].date = (char *)malloc(20 * sizeof(char)); 
// Dynamically allocate memory for the Activity 
calendar[i].Activity = (char *)malloc(20 * sizeof(char)); 
} 
} 
// Function to read data from the keyboard 
void read (struct Day calendar [7]) 
{ 
for (int i = 0; i < 7; i++)
{ 
printf("Enter the name of day %d: ", i + 1); 
scanf("%s", calendar[i].name); 
printf("Enter the date for %s: ", calendar[i].name); 
scanf("%s", calendar[i].date); 
printf("Enter activity description for %s: ", calendar[i].name); 
scanf(" %[^\n]s", calendar[i].Activity); 
} 
} 
// Function to display the week's activity details report 
void display(struct Day calendar[7])  
{ 
printf("\nWeek's Activity Details:\n"); 
printf("-------------------------------------------\n"); 
printf("DAY\t\tDATE\tACTIVITY\n"); 
printf("-------------------------------------------\n"); 
for (int i = 0; i < 7; i++) 
{ 
printf("%s\t", calendar[i].name); 
printf("%s\t\t", calendar[i].date); 
printf("%s", calendar[i].Activity); 
printf("\n"); 
} 
} 
int main() { 
struct Day calendar[7]; 
create(calendar); // call function to Create the calendar 
read(calendar); // call function to Create the calendar 
display(calendar); // Display the week's activity details 
// Free dynamically allocated memory 
for (int i = 0; i < 7; i++) 
{ 
free(calendar[i].name); 
free(calendar[i].date); 
free(calendar[i].Activity); 
} 
return 0; 
}