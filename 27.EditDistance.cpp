/*
 * This program takes two strings from the user and
 * calculates Edit distance between them using
 * Dynamic Prograrmming
 *
 *      Coded by: Abdurrezak Efe
 *
 * */
#include <iostream>
#include <cmath>
using namespace std;

int edit_distance(string s1, string s2, int m, int n)
{

    int d[m+1][n+1]; //our bottom up table

    for (int i=0; i <= m; i++)
    {
        for (int j=0; j <= n; j++)
        {
            if (i==0)
                d[i][j] = j;

            else if (j==0)
                d[i][j] = i;

            else if (s1[i-1] == s2[j-1]) //no op needed
                d[i][j] = d[i-1][j-1];

            else
                d[i][j] = 1 + min(min(d[i][j-1], d[i-1][j]), d[i-1][j-1]); //insert delete
        }
    }

    return d[m][n];
}

int main()
{
    string s1,s2;

    cin >> s1 >> s2;

    cout << edit_distance(s1,s2,s1.size(),s2.size()) << endl;

}