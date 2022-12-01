#include<bits/stdc++.h>

using namespace std;

//Recursion with Memoization
int countPathsRecMem(int n, int array[])
{
    if(n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    //If it has already been computed, then return it right away
    if(array[n] > 0)
    {
        return array[n];
    }

    //Subproblems
    int numPaths1 = countPathsRecMem(n-1, array);
    int numPaths2 = countPathsRecMem(n-2, array);
    int numPaths3 = countPathsRecMem(n-3, array);

    //Total Paths
    int totalPaths = numPaths1 + numPaths2 + numPaths3;

    //Update array
    array[n] = totalPaths;

    return totalPaths;

}


//Recursive 
int countPathsRec(int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }

    //Subproblems
    int numPaths1 = countPathsRec(n-1);
    int numPaths2 = countPathsRec(n-2);
    int numPaths3 = countPathsRec(n-3);

    //Total Paths
    int totalPaths = numPaths1 + numPaths2 + numPaths3;

    return totalPaths;
}

//Iterative
int countPathsIter(int n)
{
    //Create an array for dp
    int dp[n+1] = {0};

    //One way to reach 0th stair from 0th stair
    dp[0] = 1;

    for(int i = 1; i <= n; i ++)
    {
        //Consider some cases
        if(i == 1) //We can reach step 1 from step 0 in jump of length 1, and jumps
        {          // of length 2 and 3 are not possible
            dp[i] = dp[i-1];
        }
        else if (i == 2) // We can reach step 2 from both step 0 and 1 with jumps of
        {                // length 2 and 1 respectively, but jump of lenght 3 is not possible
            dp[i] = dp[i-1] + dp[i-2];
        }
        else 
        {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
    }

    return dp[n];
}

int main(void)
{
    //The step to reach
    int n;

    //Take input
    cin >> n;

    //Print the number of paths
    cout << countPathsRec(n) << endl;

    //Declare an array and initialize all elements to zero
    int array[n+1] = {0};

    cout << countPathsRecMem(n, array) << endl;

    cout << countPathsIter(n) << endl;
}