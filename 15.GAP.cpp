/*
 * This program finds the best global alingment for two strings
 * using Dynamic Programming
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
        s+=str[i];
    return s;
}

void GA(string s1, string s2)
{

    for(int i=0;i<=s1.size();i++) // initiating first row as zeros
        d[0][i] = (-1)*i*indel_pen, t[0][i] = 'l';

    for(int i=0;i<=s2.size();i++) // initiating first column as zero
        d[i][0] = (-1)*i*indel_pen, t[i][0] = 'u';


    d[0][0] = 0;

    for(int i=1; i<=s1.size(); i++)
    {
        for(int j=1; j<=s2.size(); j++)
        {
            if(s1[i-1] == s2[j-1])
                d[i][j] = max(max(d[i-1][j-1] + match_rew, d[i-1][j]-indel_pen), d[i][j-1]-indel_pen);
            else
                d[i][j] = max(max(d[i-1][j]-indel_pen, d[i][j-1]-indel_pen), d[i-1][j-1]-mismatch_pen);

            if(d[i][j] == d[i-1][j-1]-mismatch_pen ) //mismatch
                t[i][j] = 'n';
            else if(d[i][j] == d[i-1][j-1] + match_rew && s1[i-1] == s2[j-1]) //match
                t[i][j] = 'p';
            else if(d[i][j] == d[i-1][j] - indel_pen) //indel
                t[i][j] = 'u';
            else
                t[i][j] = 'l';

            //cout << d[i][j] << " ";
        }
        //cout << endl;
    }

    str1=""; //getting alignment of s1
    str2=""; //getting alignment of s2

    int i= s1.size();
    int j= s2.size();

    while(i>0 || j>0)
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

    GA(s1,s2);

    cout << str1 << endl << str2 << endl;
}
