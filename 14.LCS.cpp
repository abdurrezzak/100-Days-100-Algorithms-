/*
 * This program applies LC algorithm on two string user enters
 *
 *      Coded by: Abdurrezak EFE
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int d[10000][10000]; // dynamic programming table

string reverser(string str)
{
    string s="";
    for(int i = str.size()-1;i>-1;i--)
        s+=str[i];
    return s;
}

string LCS(string s1, string s2)
{
    for(int i=0;i<s1.size();i++) // initiating first row as zeros
        d[0][i] = 0;

    for(int i=0;i<s2.size();i++) // initiating first column as zero
        d[i][0] = 0;

    for(int i=1; i<=s1.size(); i++)
        for(int j=1; j<=s2.size(); j++)
            if(s1[i-1] == s2[j-1])
                d[i][j] = max(max(d[i-1][j-1]+1, d[i-1][j]),d[i][j-1]);
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);


    string str=""; //getting lcs of s1 and s2
    int i,j;
    i = s1.size();
    j = s2.size();

    while(i>0 && j>0) //traceback for the string
        if(d[i][j] == 1+d[i-1][j-1] && s1[i-1] == s2[j-1]) //if it was a match
            str += s1[i-1], i--, j--;
        else if(d[i][j-1] == d[i][j]) //if it was an insert
            j--;
        else if(d[i-1][j] == d[i][j]) //if it was a delete
            i--;

    return reverser(str);
}

int main()
{
    string s1,s2;

    cin >> s1 >> s2;

    cout << "The Longest Common Subsequence of " << s1 << " and " << s2 << " is: " << endl
         <<LCS(s1,s2) << endl;
}
