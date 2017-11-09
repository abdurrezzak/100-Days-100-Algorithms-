/*
 * This program searches for a pattern in a text using
 * Rabin - Karp Algorithm
 *
 *      Coded by: Abdurrezak Efe
 *
 * */



#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int prime = 7;
int pattern_hash;
vector<int> indexes;

int hasher(string s)
{
    int result = 0;
    for(int i=0;i<s.size();i++)
        result += (s[i] - 'a' + 1)*pow(prime, s.size()-i-1);

    return result;
}

void rabin_karp(string text, string pattern)
{
    int m = pattern.size();

    int cur_hash = hasher(text.substr(0,m));

    //cout << cur_hash << endl;

    for(int i=0; i < text.size()-m+1; i++) //searching
    {
        if(cur_hash == pattern_hash)
            if(text.substr(i,m) == pattern)
                indexes.push_back(i);

        cur_hash = prime*(cur_hash - (text[i]-'a'+1)*pow(prime, m-1))+(text[i+m]-'a'+1); //updating hash in O(1)
    }
}


int main()
{
    string text, pattern;
    cin >> text >> pattern;

    pattern_hash = hasher(pattern);
    rabin_karp(text, pattern);

    for(int i=0;i<indexes.size();i++)
        cout << indexes[i] << endl;

}