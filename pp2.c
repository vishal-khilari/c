#include <stdio.h>
#include <stdlib.h>
char str[50],pat[20],rep[20],res[50];
int a=0,b=0,c=0,d,e=0,flag=0;
void stringmatch(){
while(str[a]!='\0'){
if(str[b]==pat[c]){
b++;
c++;
if(pat[c]=='\0'){
flag=1;
for(d=0;rep[d]!='\0';d++,e++){
res[e]=rep[d];
}
a=b;
c=0;
}
}
else{
res[e]=str[a];
e++;
a++;
b=a;
c=0;
}
}
res[e] = '\0';
}
void main(){
printf("Enter a main string: ");
gets(str);
printf("Enter a pat string: ");
gets(pat);
printf("Enter a rep string: ");
gets(rep);
printf("\nThe string before pattern match is:\n%s\n", str);
stringmatch();
if(flag==1)
printf("String after replace: %s",res);
else
printf("Invalid string");
}