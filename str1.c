#include<stdio.h>
char str[50],pat[50],rep[50],res[50];
int i=0,c=0,m=0,j=0,k,flag=0;
void strreplace(){
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag = 1;
                for(k=0;rep[k]!='\0';k++,j++){
                res[j]=rep[k];
                }
                i=0;
                c=m;
            }
        }
        else{
            res[j]=str[c];
            j++;
            c++;
            m=c;
            i=0;
        }
    }
    res[j]='\0';
}
void main(){
    printf("enter the main string");
    gets(str);
    printf("enter the main string");
    gets(pat);
    printf("enter the main string");
    gets(rep);
    printf("the string before match: %s",str);
    strreplace();
    if(flag==1)
    printf("the string is %s",res);
    else
    printf("string un matxched\n");
}