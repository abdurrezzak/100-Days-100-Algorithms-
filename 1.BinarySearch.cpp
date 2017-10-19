/*
 * This program takes an array from the user
 * sorts it
 * and searches the number user enters in the array using
 * Binary Search Algorithm
 *
 * The time complexity is O(nlogn) due to sorting. However, the sorting is just for demonstration of binary search.
 * Normally, time complexity of binary search is O(logn)
 *  
 *      Coded by: Abdurrezak EFE
 *
 * */

#include <iostream>
#include <algorithm>
using namespace std;

int bs(int arr[], int l, int r, int n)
{

    if(r>=l)
    {
        int mid = (l+r)/2;

        if(arr[mid] == n)
            return mid;

        if(arr[mid] > n)
            return bs(arr, l, mid-1, n);

        return bs(arr,mid+1,r,n);

    }

    return -1;

}


int main()
{
    int k;

    cout << "Enter the number of the integers you want to construct the array from: ";
    cin >> k;

    int arr[k];
    for(int i=0;i<k;i++)
        cin >> arr[i];

    sort(arr,arr+k);

    int n;
    cout << "Please enter the number to search: ";
    cin >> n;

    cout << "The number is in: " <<  bs(arr, 0, k-1, n) << endl;

}
