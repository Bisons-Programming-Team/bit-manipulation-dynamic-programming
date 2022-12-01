#include <bits/stdc++.h>

using namespace std;


int climbStairs(int n)
{

    if (n == 1)
    {
        return 1;
    }

    int prevOne = 1;
    int prevTwo = 2;

    for (int i = 3; i <= n; i++)
    {
        // Add the previous 2 numbers
        int nextFib = prevOne + prevTwo;

        // Update the two variables to last two fibonacci numbers
        prevOne = prevTwo;
        prevTwo = nextFib;
    }

    return prevTwo;
}


int main(void)
{
    int n = 4;

    cout << climbStairs(n) << endl;
}