#include<stdio.h>
#include<stdlib.h>
void swapQ(int *a, int index, int index1)
{
    int temp=a[index];
    a[index]=a[index1];
    a[index1]=temp;
}

int partition(int *arr,int low,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swapQ(arr,i,j);
        }
    }
    swapQ(arr,i+1,high);
    return (i+1);
}
void quickSort(int *arr,int low,int high)
{
    if(low < high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
int cmpFunc(const void *a, const void *b)
{
    return(*(int*)a - *(int*)b);  // > 0 -- b a
                                  // < 0 -- a b
}
int main()
{
    printf("enter length of array\n");
    int len;
    scanf("%d",&len);
    int *arr=(int *)malloc(sizeof(int)*len);
    printf("enter array\n");
    for(int i=0;i<len;i++)
        scanf("%d",&arr[i]);
    //quickSort(arr,0,len-1);
    qsort(arr,len,sizeof(int),cmpFunc);
    printf("Sorted array is:\t");
    for(int i=0;i<len;i++)
        printf("%d\t",arr[i]);
    return 0;
}
