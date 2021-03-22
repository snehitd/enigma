// Bubble sort : Swapping all the out of order elements
//Efficiency - Less
//Tme Complexity : O(n2) 
//Space Complexity: O(1)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void swap(int index,vector<int>& arr)
{
    int temp=arr[index];
    arr[index]=arr[index+1];
    arr[index+1] = temp;
}
// Complete the countSwaps function below.
void countSwaps(vector<int> a) {
    int swaps=0,i=0,j=0;
    int len = a.size();
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                swap(j,a);
                swaps++;
            }
            //counter++;
        }
    }
    printf("Array is sorted in %d swaps.\n",swaps);
    //printf("Array is sorted in %d swaps. :%d\n",swaps,counter);
    printf("First Element: %d\n",a[0]);
    printf("Last Element: %d\n",a[len-1]);
}

int main()
{
    int len=0;
    cout << "Enter length of array:" << endl;
    cin >> len;
    vector<int> a(len);

    for(int i=0; i < len;i++)
        cin >> a[i];
    if(len != 0)
    countSwaps(a);
}
