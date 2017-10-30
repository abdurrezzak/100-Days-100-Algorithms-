/*
 * This program takes an array from the user
 * sorts it using bucket sort
 * Prints the sorted array
 * For more information about Bucket Sort Algorithm: https://en.wikipedia.org/wiki/Bucket_sort
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucket_sort(float arr[], int k)
{
    vector<float> v[k]; //creating buckets

    int num;
    for(int i=0;i<k;i++)
        num = k*arr[i], v[num].push_back(arr[i]); //filling buckets

    for(int i=0;i<k;i++)
        sort(v[i].begin(),v[i].end()); //sorting every bucket

    int index=0;
    for(int i=0;i<k;i++)
        for(int j=0;j<v[i].size();j++)
            arr[index] = v[i][j], index++;

}

int main()
{
    int k;
    cout << "Enter the number of the floating point numbers you want to construct the array from: ";
    cin >> k;

    float arr[k];
    for(int i=0;i<k;i++)
        cin >> arr[i];

    bucket_sort(arr, k); //sorting

    for(int i=0;i<k;i++) //printing the array
        cout << arr[i] << " ";
}
