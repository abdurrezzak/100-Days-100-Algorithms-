/*
 * This program takes an array from the user
 * sorts it using selection sort
 * Prints the sorted array
 * For more information about Insertion Sort Algorithm: https://en.wikipedia.org/wiki/Selection_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void selection_sort(int arr[],int k) //insertion sort function
{

    for(int i=0;i<k;i++)
    {
        int smallest=999999999;
        int smallestIndex=-1;
        for(int j=i;j<k;j++)
        {
            if(arr[j]<=smallest)
                smallest = arr[j],smallestIndex=j;

            arr[smallestIndex] = arr[i];
            arr[i] = smallest;
        }
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

    selection_sort(arr,k); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
