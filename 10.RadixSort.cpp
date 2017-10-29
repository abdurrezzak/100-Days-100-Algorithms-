/*
 * This program takes an array from the user
 * sorts it using radix sort
 * Prints the sorted array
 * For more information about Radix Sort Algorithm: https://en.wikipedia.org/wiki/Counting_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

void counting_sort(int arr[], int k, int power)
{
    int counts[11] = {0}; //initializing count array

    for(int i=0; i<k; i++) //we find out how many times a character occurs
        counts[(arr[i]/power)%10]++;

    for(int i=1;i<10; i++) //we find out the actual positions of the elements
        counts[i] += counts[i-1];

    //we copy our array
    int arr2[k];
    for(int i=0;i<k;i++)
        arr2[i] = arr[i];

    for(int i=k-1; i>=0; i--) //change the order of the original array
        arr[counts[(arr2[i]/power)%10]-1] = arr2[i], counts[(arr[i]/power)%10]--;
}

void radix_sort(int arr[], int k, int maxx)
{
    for (int power = 1; maxx/power > 0; power *= 10) //sorting on each digit
        counting_sort(arr, k, power);
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

    radix_sort(arr, k, maxx); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
