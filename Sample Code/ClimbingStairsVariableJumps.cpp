#include<bits/stdc++.h>

using namespace std;

int numPaths(int n, int jumps[])
{
    int dp[n+1] = {0};

    //Base case, there is one way to go to nth step from nth step, don't move
    dp[n] = 1;

    //Calculate the number of ways possible from left to right
    for(int i = n-1; i >= 0; i--)
    {
        //Add number of ways corresponding to all lengths of jumps possible
        for(int j = 1; (j <= jumps[i]) && ((i + j) <= n); j ++)
        {
            dp[i] += dp[i + j];
        }   
    }

    return dp[0];
}

int main(void)
{
    //Lets consider this test case
    // n = 6
    // possible jumps corresponding to positions = 3 3 0 2 2 3 

    //The stair to reach
    int n;
    scanf("%d", &n);

    //Store the lengths of jumps in an array
    int jumps[n];
    for(int i = 0; i < n; i ++)
    {
        scanf("%d", &jumps[i]);
    }

    cout << "Number of ways :" << numPaths(n, jumps) << endl;
}