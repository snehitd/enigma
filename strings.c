/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
int StrLen(char *);
void StrCat(char *, char *);
void StrCpy(char *, char *);
void StrRev(char *);

int main()
{
    char *pName,*pConCat, *pCpy;
    char name[]="SNEHIT";
    printf("%s\n",name);
    pName=name;
    StrRev(pName);
    printf("rev:%s\n",pName);
    pCpy=(char *)malloc(StrLen(pName)*sizeof(char));
    StrCpy(pCpy,pName);
    printf("Copy:%s\n",pCpy);
    pCpy=(char *)realloc(pCpy,2*StrLen(pName)*sizeof(char));
    StrCat(pCpy,pName);
    printf("Concats:%s",pCpy);
    return 0;
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
