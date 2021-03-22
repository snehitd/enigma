// Bubble sort : Swapping all the out of order elements
//Efficiency - Less
//Tme Complexity : O(n2) - Traditional, can be optimized to O(n) refer optBubSort()function below
//Space Complexity: O(1) 
#include <stdio.h>
#include <stdlib.h>

void swap(int index,int* arr)
{
    int temp=arr[index];
    arr[index]=arr[index+1];
    arr[index+1] = temp;
}

// Complete the countSwaps function below.
void countSwaps(int a_count, int* a) {
    int len=a_count,swaps=0;
    int i=0,j=0;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len-1;j++)
        {
            if(a[j] > a[j+1])
            {
                swap(j,a);
                swaps++;
            }
        }
    }
}

void optBubSort(int a_count, int* a)
{
    bool isSorted=false;
    int swaps=0;
    int unSortedLen=a_count-1;
    while(!isSorted)
    {
        isSorted=true;
        for(int i=0;i<unSortedLen;i++)
        {
            if(a[i] > a[i+1])
            {
                swap(i,a);
                isSorted=false;
                swaps++;
            }
        }
        unSortedLen--;
    }
    printf("Array is sorted in %d swaps.\n",swaps);
    printf("First Element: %d\n",a[0]);
    printf("Last Element: %d\n",a[a_count-1]);
}

int main()
{
    int* a = NULL;
    int len=0;
    printf("Enter length of array:");
    scanf("%d",&len);
    a=(int *)malloc(sizeof(int)*len);
    for(int i=0; i < len;i++)
    scanf("%d",&a[i]);
    if(len != 0 && a!=NULL)
    //countSwaps(len,a);
    optBubSort(len,a);
}
