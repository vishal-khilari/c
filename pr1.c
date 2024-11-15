#include<stdio.h>
#include<string.h>
struct Day{
    char name[20];
    int date;
    char activity[100];
};
int main(){
    struct Day calendar[7];
    strcpy(calendar[0].name,"monday");
    calendar[0].date=1;
    strcpy(calendar[0].activity,"work from 9 to 5");
    strcpy(calendar[1].name,"tuesday");
    calendar[1].date=2;
    strcpy(calendar[1].activity,"dance");
    strcpy(calendar[2].name,"wednsday");
    calendar[2].date=3;
    strcpy(calendar[2].activity,"football");
    strcpy(calendar[3].name,"thursday");
    calendar[3].date=4;
    strcpy(calendar[3].activity,"tution");
    strcpy(calendar[4].name,"friday");
    calendar[4].date=5;
    strcpy(calendar[4].activity,"workout");
    strcpy(calendar[5].name,"saturday");
    calendar[5].date=6;
    strcpy(calendar[5].activity,"rest");
    strcpy(calendar[6].name,"sunday");
    calendar[6].date=7;
    strcpy(calendar[6].activity,"collage");
    printf("Callender for the week:\n");
    for(int i=0;i<7;i++){
        printf("day: %s\tDate: %d\tactivity: %s\n",calendar[i].name, calendar[i].date,calendar[i].activity);
    }
    return 0;
}