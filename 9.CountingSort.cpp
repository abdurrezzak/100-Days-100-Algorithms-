/*
 * This program takes an array from the user
 * sorts it using counting sort
 * Prints the sorted array
 * For more information about Counting Sort Algorithm: https://en.wikipedia.org/wiki/Counting_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(int arr[], int k, int maxx)
{
    int counts[maxx+1];
    for(int i=0;i<maxx+1;i++) //initializing count array
        counts[i] = 0;

    for(int i=0; i<k; i++) //we find out how many times a character occurs
        counts[arr[i]]++;

    for(int i=1;i<=maxx; i++) //we find out the actual positions of the elements
        counts[i] += counts[i-1];

    //we copy our array
    int arr2[k];
    for(int i=0;i<k;i++)
        arr2[i] = arr[i];

    for(int i=0; i<k; i++) //change the order of the original array
        arr[counts[arr2[i]]-1] = arr2[i], counts[arr2[i]]--;
}

int main()
{
    int k;
    cout << "Enter the number of the integers you want to construct the array from: ";
    cin >> k;

    int arr[k];
    int maxx = -1;
    for(int i=0;i<k;i++)
        cin >> arr[i], maxx = max(maxx,arr[i]);

    counting_sort(arr, k, maxx); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
