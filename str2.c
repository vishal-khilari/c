#include <stdio.h>
char str[20],pat[20],rep[20],res[20]; 
int a=0,b=0,c=0,d,e=0,flag=0;
void strrep(){
    while(str[a]!='\0'){
        if(str[b]==pat[c]){
            c++;
            b++;
            if(pat[c]=='\0'){
                flag = 1;
                for(d=0;rep[d]!='\0';d++,e++){
                    res[e]=rep[d];
                }
                c=0;
                a=b;
            }
        }
        else{
        res[e]=str[a];
        e++;
        a++;
        c=0;
        b=a;
        }
    
    }
    res[e]='\0';
}
void main(){
    printf("\nenter a string: ");
    gets(str);
    printf("\nenter the which has to be removed: ");
    gets(pat);
    printf("\nenter a replace string: ");
    gets(rep);
    printf("\nstring before edit: %s",str);
    strrep();
    if(flag=1){
    printf("\nresultant string: %s",res);
    }else{
    printf("Somthing wint wrong!");
    }
}