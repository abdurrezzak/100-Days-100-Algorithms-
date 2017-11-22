/*
 *  This program constructs an array from user inputs and
 *  calculates the minimun difference achievable by partitioning that array into two parts
 *  using Dynamic Programming
 *
 *
 *      Coded by: Abdurrezak Efe
 *
 * */
#include <iostream>
#include <cmath>
using namespace std;

int d[100][100000]; //global aray to memoize assuming sum is not over 100000

int min_part(int arr[], int n, int set_sum, int sum)
{

    if(d[n][set_sum])
        return d[n][set_sum];

    if(n == 0)
        return abs(sum-2*set_sum);

    d[n][set_sum] = min(min_part(arr, n-1, set_sum + arr[n-1], sum), min_part(arr, n-1, set_sum, sum)); //memoizing and calculating
    return d[n][set_sum];

}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    int sum=0;

    for(int i=0;i<n;i++)
        cin >> arr[i], sum+=arr[i];

    cout << min_part(arr, n, 0, sum) << endl;
}