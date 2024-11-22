#include <stdio.h>
#include <stdlib.h>

struct Day{
    char *dayname;
    int date;
    char *activity;
};

void create(struct Day *day){
    day->dayname=(char*)malloc(sizeof(char)*20);
    day->activity=(char*)malloc(sizeof(char)*50);
    printf("Enter date: ");
    scanf("%d",&day->date);
    printf("Enter day: ");
    scanf("%s",day->dayname);
    printf("Enter activity: ");
    scanf(" %[^\n]s",day->activity);
}

void read(struct Day *calendar,int size){
    for(int i=0;i<size;i++){
        printf("Enter detail for day %d",i+1);
        create(&calendar[i]);
    }
}

void display(struct Day *calendar,int size){
    printf("---DETAILS OF THE WEEK---");
    for(int i=0;i<size;i++){
        printf("Date: %d",calendar[i].date);
        printf("Day: %s",calendar[i].dayname);
        printf("Activity: %s",calendar[i].activity);
        printf("\n");
    }
}

void freememory(struct Day *calendar,int size){
    for(int i = 0;i<size;i++){
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
}

int main(){
    int size;
    printf("Enter the number of days in week: ");
    scanf("%d",&size);
    struct Day *calendar = (struct Day*)malloc(sizeof(struct Day)*size);
    if(calendar == NULL){
        printf("not able to allockate");
        return 1;
    }
    read(calendar,size);
    display(calendar,size);
    freememory(calendar,size);
    free(calendar);
    return 0;
}