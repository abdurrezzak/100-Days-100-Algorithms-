/*
 * This program solves 1/0 Knapsack program using Dynamic Programming
 *
 *      Coded by: Abdurrezak EFE
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int d[10000][10000]={0}; //global dynamic programming table
int v[10000]={0};
int w[10000]={0};

int knapsack(int i, int j)
{
    if(j<0)
        return -10000000;

    if(i <= 0 || j <= 0)
        return 0;

    if(d[i][j]) //if it was calculated return it
        return d[i][j];

    d[i][j] = max(knapsack(i-1, j), knapsack(i-1, j - w[i]) + v[i]); //memoizing the value

    return d[i][j];
}

int main()
{
    int n, m; //respectively size of the knapsack and number of items
    cin >> n >> m;

    for(int i=1;i<=n;i++)
        cin >> v[i] >> w[i];

    cout << knapsack(n,m);

}
