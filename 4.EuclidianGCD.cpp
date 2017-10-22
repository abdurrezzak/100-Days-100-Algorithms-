/*
 * This program takes two numbers as input and
 * calculates their greates common divisor using
 * Euclidian Algorithm
 * For more information about the Algorithm: https://en.wikipedia.org/index.php?q=aHR0cHM6Ly9lbi53aWtpcGVkaWEub3JnL3dpa2kvRXVjbGlkZWFuX2FsZ29yaXRobQ
 *
 *      Coded by: Abdurrezak EFE
 *
 * */
#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    if(a%b == 0)
        return b;
    else
        return gcd(b,a%b);
}

int main()
{
    int a,b; //taking the inputs
    cin >> a >> b;

    cout << "GCD of " << a << " and " <<b <<" is: " << gcd(a,b) << endl;

}
