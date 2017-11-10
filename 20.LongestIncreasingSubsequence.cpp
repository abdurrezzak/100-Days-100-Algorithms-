/*
 * This program takes an array from the user and returns
 * the longest increasing subsequence's length
 *
 *      Coded by: Abdurrezak Efe
 *
 * */
#include <iostream>
#include <algorithm>

using namespace std;
int d[10000][10000] = {0}; //constructing dynamic array

int lis(int arr[], int n)
{
    int b[n];
    for(int i=0;i<n;i++)
        b[i] = arr[i];

    sort(b,b+n);

    //basically calculating the lcs of the array's original and sorted versions
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(arr[i-1] == b[j-1])
                d[i][j] = d[i-1][j-1]+1;
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
        }
    }

    return d[n][n];
}

int main()
{
    //taking the array
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];

    //printing final result
    cout << lis(arr, n) << endl;


}
