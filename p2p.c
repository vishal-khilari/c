#include<stdio.h>
int main(){
    int i = 5;
    int *ptr = &i;
    int **pptr = &ptr;

    printf("%d\n",i);  //value of i
    printf("%p\n",ptr); //address of i
    printf("%p\n",pptr); //address of ptr
    return 0;
}