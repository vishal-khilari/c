#include<stdio.h>
int main(){
    int i = 5;
    int *ptr = &i;
    int **pptr = &ptr;

    printf("%d\n",i);
    printf("%p\n",ptr);
    printf("%p\n",pptr);
    return 0;
}