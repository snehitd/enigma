// Example program
#include<stdio.h>
#include<stdlib.h>
int StrCmp(char *str1, char* str2)
{
    while(*str1==*str2)
    {
        if(*str1=='\0' /*|| *str2=='\0'*/)
            return 0;
            str1++;
            str2++;
    }
    return (*str1-*str2);
}
// Driver code
int main()
{
    char* strA = NULL;
    char* strB = NULL;
    int lenA = 0, lenB = 0;
    printf("Enter length of String A\n");
    scanf("%d",&lenA);
    strA=(char *)malloc(sizeof(char)*lenA);
    printf("Enter string A\n");
    scanf("%s",strA);
    printf("Enter length of String B\n");
    scanf("%d",&lenB);
    strB=(char *)malloc(sizeof(char)*lenB);
    printf("Enter string B\n");
    scanf("%s",strB);
    int ret = StrCmp(strA,strB);
    if(ret==0)
        printf("Strings are equal");
    else if (ret > 0)
        printf("%s greater than %s",strA,strB);
    else
        printf("%s greater than %s",strB,strA);
    return 0;
}
