/*
 * This program finds the best local alignment for two strings
 * using Dynamic Programming (Smith- Waterman Algorithm)
 *
 *      Coded by: Abdurrezak EFE
 * */

#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

int d[10000][10000]; // dynamic programming table
char t[10000][10000]; //traceback table
int mismatch_pen = 3;
int match_rew = 5;
int indel_pen = 1;

string str1;
string str2;

string reverser(string str)
{
    string s="";
    for(int i = str.size()-1;i>-1;i--)
        s += str[i];
    return s;
}

void LA(string s1, string s2)
{
    for(int i=0;i<=s1.size();i++) // initiating first row as zeros
        d[0][i] = (-1)*i*indel_pen, t[0][i] = 'l';

    for(int i=0;i<=s2.size();i++) // initiating first column as zero
        d[i][0] = (-1)*i*indel_pen, t[i][0] = 'u';

    int max_value = -100000; //biggest value in dynamic table yet
    int maxi = 0;
    int maxj = 0;

    for(int i=1; i<=s1.size(); i++)
    {
        for(int j=1; j<=s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
                d[i][j] = max(max(max(d[i-1][j-1] + match_rew, d[i-1][j]-indel_pen), d[i][j-1]-indel_pen), 0);
            else
                d[i][j] = max(max(max(d[i-1][j]-indel_pen, d[i][j-1]-indel_pen), d[i-1][j-1]-mismatch_pen), 0);

            if(d[i][j] > max_value) //keeping the biggest value
                max_value = d[i][j], maxi = i, maxj = j;

            if(d[i][j] == 0)
                t[i][j] = 's';
            else if(d[i][j] == d[i-1][j-1]-mismatch_pen ) //mismatch(negative)
                t[i][j] = 'n';
            else if(d[i][j] == d[i-1][j-1] + match_rew && s1[i-1] == s2[j-1]) //match(positive)
                t[i][j] = 'p';
            else if(d[i][j] == d[i-1][j] - indel_pen) //indel up
                t[i][j] = 'u';
            else //indel left
                t[i][j] = 'l';

        }
    }

    str1=""; //getting local part of s1
    str2=""; //getting local part of s2

    int i= maxi;
    int j= maxj;


    while(d[i][j] > 0)
    {
        if(t[i][j] == 'u')
        {
            str1 += s1[i-1];
            str2 += '-';
            i--;
        }
        else if(t[i][j] == 'l')
        {
            str1 += '-';
            str2 += s2[j-1];
            j--;
        }else
        {
            str1 += s1[i-1];
            str2 += s2[j-1];
            i--,j--;
        }


    }
    str1 = reverser(str1);
    str2 = reverser(str2);
}

int main()
{
    string s1,s2;

    cin >> s1 >> s2;

    LA(s1,s2);

    cout << str1 << endl << str2 << endl;
}
