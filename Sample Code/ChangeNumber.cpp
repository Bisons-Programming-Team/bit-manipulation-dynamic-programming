#include <bits/stdc++.h>

using namespace std;

// Naive solution to check
// Time complexity - theta(Total Bit count)
int count(int n)
{
    int ans = 0;

    while (n > 0)
    {
        // If the current bit at position 1 is 1 then ans will be incremented by 1, otherwise it will not
        ans = ans + (n & 1);
        n = (n >> 1);
    }

    return ans;
}

// Function that count set bits
// Time complexity - theta(Total Set Bit count)
int countSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        count++;
        // n&(n-1) changes the last set bit in number to zero
        n &= (n - 1);
    }
    return count;
}

// Driver code
int main()
{
    int a = 22; // 10110
    int b = 27; // 11011
    // Calculate XOR
    int x = a ^ b; // 01101, that is 13

    // Function call
    cout << countSetBits(x) << endl;

    //Builtin function 
    cout << __builtin_popcount(x) << endl;
    
    return 0;
}