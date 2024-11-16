#include<stdio.h>
void main(){
char STR[100],PAT[100],REP[100],ans[100];
int i,j,c,m,k,flag=0;
printf("\n Enter the MAIN string:\n");
gets(STR);
printf("\n Enter the PATTERN string:\n:");
gets(PAT);
printf("\n Enter the REPLACE string:\n");
gets(REP);
i=m=c=j=0;
while(STR[c]!='\0'){
if(STR[m]==PAT[i]){
i++;
m++;
flag=1;
if(PAT[i]=='\0'){
for(k=0;REP[k]!='\0';k++,j++)
ans[j]=REP[k];
i=0;
c=m;
}
}
else{
ans[j]=STR[c];
j++;
c++;
m=c;
i=0;
}
}
if(flag==0)
printf("Pattern doesnot found");
else{
    ans[j]='\0';
printf("\n The Resultant String is:%s\n",ans);
}
}