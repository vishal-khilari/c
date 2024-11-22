#include <stdio.h>
#include <stdlib.h>
struct Day{
    char *dayname;
    int date;
    char *activity;
};
void create(struct Day *day){
    day->dayname=(char*)malloc(sizeof(char)*20);
    day->activity=(char*)malloc(sizeof(char)*100);
    printf("Enter your day name: ");
    scanf("%s",day->dayname);
    printf("Enter your date: ");
    scanf("%d",&day->date);
    printf("Enter your activity: ");
    scanf("%[^\n]s",day->activity);
}

void read(struct Day *calendar,int size){
    for(int i = 0;i<size;i++){
        printf("Enter details of your day %d \n",i+1);
        create(&calendar[i]);
    }
}

void display(struct Day *calendar,int size){
    printf("Enter your week's activity\n");
    for(int i = 0;i<size;i++){
        printf("Day: %d",i+1);
        printf("Date: %d",calendar[i].date);
        printf("Day Name: %s",calendar[i].dayname);
        printf("Day activity: %s",calendar[i].activity);
        printf("\n");
    }
}

void freealloc(struct Day *calendar,int size){
    for(int i =0;i<size;i++){
        free(calendar[i].dayname);
        free(calendar[i].activity);
    }
}

int main(){
    int size;
    printf("Enter the number of days in week: ");
    scanf("%d",&size);
    struct Day *calendar = (struct Day*)malloc(sizeof(struct Day)*size);
    if(calendar==NULL){
        printf("not able to alloct");
        return 1;
    }
    read(calendar,size);
    display(calendar, size);
    freealloc(calendar,size);
    free(calendar);
    return 0;
}