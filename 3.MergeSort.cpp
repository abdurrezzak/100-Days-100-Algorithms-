/*
 * This program takes an array from the user
 * sorts it using merge sort
 * Prints the sorted array
 * Time Complexity of the algorithm is: O(nlogn)
 *
 * For more information about Merge Sort Algorithm: https://en.wikipedia.org/wiki/Merge_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void merge(int arr[], int l, int m, int r) //merge function O(n)
{
    int lsize = m-l+1;
    int rsize = r-m;

    int left[lsize];
    int right[rsize];

    for(int i=0;i<lsize;i++)
        left[i] = arr[i+l];

    for(int i=0;i<rsize;i++)
        right[i] = arr[i+m+1];

    int li=0,ri=0;
    int index = l;

    while(li<lsize && ri<rsize)
    {
        if(left[li] <= right[ri])
            arr[index]=left[li],li++;
        else
            arr[index] = right[ri],ri++;

        index++;
    }

    while(li<lsize)
        arr[index] = left[li],li++,index++;

    while(ri<rsize)
        arr[index] = right[ri],ri++,index++;

}

void merge_sort(int arr[],int l, int r) //merge sort function O(nlogn)
{
    if(l<r)
    {
        int m = (l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main()
{
    int k;
    cout << "Enter the number of the integers you want to construct the array from: ";
    cin >> k;

    int arr[k];
    for(int i=0;i<k;i++)
        cin >> arr[i];

    merge_sort(arr,0,k-1); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}