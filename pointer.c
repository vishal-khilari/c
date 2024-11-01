#include<stdio.h>
int main(){
    int a = 22;
    int *ptr = &a;
    int a1 = (int)ptr;
    int a2 = *ptr;

    printf("%d\n",a); //value
    printf("%d\n",*ptr); //value
    printf("%p\n",ptr);  //address
    printf("%p\n",a1);  //address
    printf("%d\n",a2);  //value
    return 0;
}