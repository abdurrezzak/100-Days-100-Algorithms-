/*
 * This program takes an array from the user
 * sorts it using insertion sort
 * Prints the sorted array
 * For more information about Insertion Sort Algorithm: https://en.wikipedia.org/wiki/Insertion_sort
 *  
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(int arr[],int k) //insertion sort function
{
    for(int i=1;i<k;i++)
    {
        int j = i-1;
        int num = arr[i];

        while(j>=0 && arr[j]>=num)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = num;
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

    insertion_sort(arr,k); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
