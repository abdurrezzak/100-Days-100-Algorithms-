/*
 * This program takes a text and a pattern and searches the pattern inside the text
 * using Knuth- Morris- Pratt Algorithm
 *
 *      Coded by: Abdurrezak Efe
 *
 * */
#include <iostream>

using namespace std;

int fail[10000]; //assuming pattern has a length less than or equal to 10000

void failure(string s)
{
    int i=1;
    int j=0;
    while(i<s.size())
    {
        if(s[i] == s[j])
            fail[i] = j+1, i++, j++;
        else if(j>0)
            j =  fail[j-1];
        else
            fail[i] = 0, i++;
    }
}

int kmp(string text, string pattern)
{
    int i=0;
    int j=0;
    while(i<text.size())
    {
        if(text[i] == pattern[j])
            if(j == pattern.size()-1)
                return i-j; // we have a match
            else
                i++,j++;
        else
            if(j>0)
                j = fail[j-1];
            else
                i++;
    }
    return -1;

}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    cout << kmp(text, pattern) << endl;
}
