#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Day
{
char *name;
char *date;
char *Activity;
};
void create(struct Day calendar[7])
{
for (int i = 0; i < 7; i++)
{
calendar[i].name = (char *)malloc(20 * sizeof(char));
calendar[i].date = (char *)malloc(20 * sizeof(char));
calendar[i].Activity = (char *)malloc(20 * sizeof(char));
}
}
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
create(calendar); 
read(calendar);
display(calendar);
for (int i = 0; i < 7; i++)
{
free(calendar[i].name);
free(calendar[i].date);
free(calendar[i].Activity);
}
return 0;
}