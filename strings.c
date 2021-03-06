/******************************************************************************
                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int StrLen(char *);
void StrCat(char *, char *);
void StrCpy(char *, char *);
void StrRev(char *);
char *StrRightSub(char *,int);
int StrCmp(char *,char *);

int main()
{
    char *pName, *pConCat, *pCpy;
    char name[]="SNEHIT";
    printf("%s\n",name);
    pName=name;
    StrRev(pName);
    printf("rev:%s\n",pName);
    pCpy=(char *)malloc(StrLen(pName)*sizeof(char));
    StrCpy(pCpy,pName);
    printf("Copy:%s,size:%d,mem:%p\n",pCpy,strlen(pCpy),pCpy);
    pCpy=(char *)realloc(pCpy,2*StrLen(pName)*sizeof(char));
    StrCat(pCpy,pName);
    printf("Concats:%s,size:%d,mem:%p\n",pCpy,strlen(pCpy),pCpy);
    char *strSubStr=StrRightSub(pName,10);
    printf("SubStr:%s",strSubStr);
    int ret=StrCmp(pName,pName);
    printf("%s",(ret==0?"Same":"Not Same"));
    return 0;
}
int StrCmp(char *str1, char* str2)
{
    while(*str1==*str2)
    {
        if(*str1=='\0')
            return 0;
            str1++;
            str2++;
    }
    return (*str1-*str2);
}
char *StrRightSub(char *pName,int n)
{
    char *temp=(char *)malloc(n+1);
    char *temp1=pName+StrLen(pName)-n;
    int i=0;
    while(i < n)
    {
        temp[i]=*temp1;
        temp1++;
        i++;
    }
    return temp;
}
void StrCpy(char *pCpy, char *name)
{
    while(*name)
    {
        *pCpy++=*name++;
    }
}
void StrCat(char *pConCat, char *pName)
{
    while(*pConCat)
    {
        pConCat++;
    }
    while(*pName)
    {
        *pConCat++=*pName++;
    }
}
void StrRev(char *pName)
{
    int len=StrLen(pName);
    char *pRevName=pName+len-1;
    int i=0;
    char temp;
    printf("len=%d\n", len);
    while(i < len/2)
    {
        temp=*pName;
        *pName=*pRevName;
        *pRevName=temp;
        pName++;
        pRevName--;
        i++;
    }
}
int StrLen(char *pName)
{
    int len =0;
    while(*pName++)
    {
        len++;
    }
    return len;
}
