/*
 * This program takes an array from the user
 * sorts it using quicksort
 * Prints the sorted array
 * For more information about Quicksort Algorithm: https://en.wikipedia.org/wiki/Quicksort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int r) // The used partition method is Lomuto's Partition
{
    int pivot = arr[r]; //choosing the last element as the pivot

    int i = (l - 1); //starting from the left
    int temp;

    for (int j = l; j <= r- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j],arr[j]=temp; //swapping elements
        }
    }
    temp = arr[i+1], arr[i+1] = arr[r], arr[r] = temp; //swapping elements again
    return (i + 1);
}

void quick_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
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

    quick_sort(arr,0, k-1); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
