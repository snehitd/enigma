/*
This program illustrates 
1. Dangling pointer
2. Void pointer
3. Null pointer
4. Wild pointer
5. realloc(NULL,size) equivalent to malloc
6. realloc(ptr,0) equivalent to free(ptr)
*/
#include <stdio.h> //for printf,scanf etc
#include <stdlib.h> //for malloc,free etc
int *fun()
{
    int a=20;
    return &a; //variable a is local scope
}
int main()
{
    int *ptr; /* ptr is a Wild pointer */
    
    /* ntr is NULL pointer, as it points to NULL */
    int *ntr = NULL; 
    
    int x=5;
    ptr=&x;//ptr is not wild pointer now
    
    ptr=(int *)malloc(sizeof(int));
    //ptr=(int *)realloc(NULL,sizeof(int)); //this is equivalent to malloc
    
    *ptr=x;
    printf("Before free %p\t %d\n",ptr,*ptr);
    
    free(ptr);//ptr becomes  dangling pointer now
    //realloc(ptr,0); //this is equivalent to free
    
    printf("Aftre free %p\t %d\n",ptr,*ptr);
    
    ptr=NULL;//ptr now is not dangling pointer, its NULL pointer now
    
    //ntr is not a null pointer now 
    ntr=fun(); //ntr becomes dangling pointer now, ntr points to something which is not valid now
    
    //void pointer - can be type cast to any data type
    void *p;
    int i = 10;
    float j = 12.6;
    p=&i;
    printf("%d\n",*(int *)p);
    p=&j;
    printf("%f\n",*(float *)p);
}
