/*
 * This program takes an array from the user
 * sorts it using bubble sort
 * Prints the sorted array
 * For more information about Bubble Sort Algorithm: https://en.wikipedia.org/wiki/Bubble_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int arr[],int k) //bubble sort function
{
    int i, j,temp;
    for (i = 0; i < k-1; i++)
        for (j = 0; j < k-i-1; j++)
            if (arr[j] > arr[j+1])
                temp=arr[j],arr[j]=arr[j+1],arr[j+1]=temp; //swapping
}

int main()
{
    int k;
    cout << "Enter the number of the integers you want to construct the array from: ";
    cin >> k;

    int arr[k];
    for(int i=0;i<k;i++)
        cin >> arr[i];

    bubble_sort(arr,k); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
