/*
This program illustrate various user defined operations that can be carried out on strings
1. Length of string
2. String concatenation
3. String Copy
4. String reversal
5. String reversal - recursion
6. Get substring of size n from right
7. Get substring of size n from left
8. String compare
9. Get substring of size n from a position
10. Count number of words in a line*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int StrLen(char *);
void StrCat(char *, char *);
void StrCpy(char *, char *);
void StrRev(char *);
char* StrSub(char *, int , int);
char *StrRightSub(char *,int);
char *StrLeftSub(char *, int);
char *StrRevRecursion(char *, int , int);
int StrCmp(char *,char *);
int numOfWordsInLine(char *);


int main()
{
    char *pName, *pConCat, *pCpy;

    char name[]="SNEHIT";
    printf("%s\n",name);

    pName=name;
    
    StrRev(pName);
    printf("rev:%s\n",pName);

    pName=StrRevRecursion(pName,0,StrLen(pName)-1);
    printf("Rev recursion:%s\n",pName);
    
    pCpy=(char *)malloc(StrLen(pName)*sizeof(char));
    StrCpy(pCpy,pName);
    printf("Copy:%s,size:%d,mem:%p\n",pCpy,strlen(pCpy),pCpy);

    pCpy=(char *)realloc(pCpy,2*StrLen(pName)*sizeof(char));
    StrCat(pCpy,pName);
    printf("Concats:%s,size:%d,mem:%p\n",pCpy,strlen(pCpy),pCpy);

    pCpy="Hi Hello Bye";
    char *strSubStr=StrRightSub(pCpy,3);
    printf("Right SubStr:%s\n",strSubStr);
    
    strSubStr=StrLeftSub(pCpy,2);
    printf("Left SubStr:%s\n",strSubStr);

    strSubStr=StrSub(pCpy,3,5);
    printf("SubStr:%s\n",strSubStr);
    
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
    char *temp=(char *)malloc(n+1), *temp1=pName+(StrLen(pName)-n);
    int i=0;
    while(i < n)
    {
        temp[i]=*temp1;
        temp1++;
        i++;
    }
    temp[i]='\0';
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
    int i=0, len=StrLen(pName);
    
    //pRevName points to end of pName
    char *pRevName=pName+(len-1), temp;

    printf("len=%d\n", len);

    //replace chars till mid of string
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

char *StrRevRecursion(char *str, int leftIndex, int rightIndex)
{
    if(str == NULL || leftIndex > rightIndex)
    return NULL;
    
    char temp=str[rightIndex];
    str[rightIndex]=str[leftIndex];
    str[leftIndex]=temp;
    StrRevRecursion(str,leftIndex+1,rightIndex-1);
    return str;
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

char *StrLeftSub(char *str, int n)
{
    char *temp=(char *)malloc(n+1);
    int i=0;
    while(i < n)
    {
        temp[i]=*str;
        str++;
        i++;
    }
    temp[i]='\0';
    return temp;
}

char *StrSub(char *str, int spos, int n)
{
    char *ret=(char *)malloc(n+1);
    char *temp=str+spos;
    int i=0;
    while(i < n)
    {
        ret[i]=*temp;
        temp++;
        i++;
    }
    ret[i]='\0';
    return ret;
}
