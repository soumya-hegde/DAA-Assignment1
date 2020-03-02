#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//using namespace std;
char s[50];
char a[50],d[50],t[50];
int h,t1,t2=-1,t3=-1,t4=-1,move=0;
int tower(int n,char src,char aux,char des,char temp)
{
    if(n==0)
        return 0;
    tower(n-1,src,des,aux,temp);

    if(src=='a'&&des=='c')
        d[++t3]=s[t1--];
    if(src=='a'&&des=='b')
        a[++t2]=s[t1--];
    if(src=='a'&&des=='e')
        t[++t4]=s[t1--];
    if(src=='b'&&des=='a')
        s[++t1]=a[t2--];
    if(src=='b'&&des=='c')
        d[++t3]=a[t2--];
    if(src=='b'&&des=='e')
        t[++t4]=a[t2--];
    if(src=='c'&&des=='a')
        s[++t1]=d[t3--];
    if(src=='c'&&des=='b')
        a[++t2]=d[t3--];
    if(src=='c'&&des=='e')
        t[++t4]=d[t3--];
    if(src=='e'&&des=='a')
        s[++t1]=t[t4--];
    if(src=='e'&&des=='b')
        a[++t2]=t[t4--];
    if(src=='e'&&des=='c')
        d[++t3]=t[t4--];
    printf("Move %d\n",++move);
    printf("Source:");
    for(int i=t1;i>=0;i--)
        printf("%c\t",s[i]);
    printf("\n");
    printf("Aux:");
    for(int i=t2;i>=0;i--)
        printf("%c\t",a[i]);
    printf("\n");
    printf("Destination:");
    for(int i=t3;i>=0;i--)
        printf("%c\t",d[i]);
    printf("\n");
    printf("Temp:");
    for(int i=t4;i>=0;i--)
        printf("%c\t",t[i]);
    printf("\n\n");

    tower(n-1,aux,temp,des,src);
    return 0;
}
int main(int argc, char* argv[])
{
int j=49;
int x;
   //printf("enter number of disks\n");
    //scanf("%d",&h);
    //t1=h-1;
     x=atoi(argv[1]);
     t1=x-1;
      printf("initially\n");
for(int i=t1;i>=0;i--)
{
        s[i]=j++;
        printf("%c\t",s[i]);
        printf("\n");
}
        printf("aux:\n");
        printf("destination:\n");
        printf("temp:\n");
    tower(x,'a','b','c','e');
    //tower(h,'a','b','c','e');


    return 0;
}


