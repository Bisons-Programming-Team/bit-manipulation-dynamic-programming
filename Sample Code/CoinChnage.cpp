#include <bits/stdc++.h>

using namespace std;

int minCoinsRec(int amount, int coins[], int numCoins)
{
    if (amount == 0)
    {
        return 0;
    }

    // Initialize ans to a large value
    int minCoins = INT_MAX;

    for (int i = 0; i < numCoins; i++)
    {
        //If we take the current coin, whats the amount left
        int amountLeft = amount - coins[i];

        // If it is possible to take this coin
        if (amountLeft >= 0)
        {
            int subAnswer = minCoinsRec(amountLeft, coins, numCoins);

            // In case where none of the coins are not possible, we will get
            // INT_MAX as subAnswer and we will check if that is the case
            if ((subAnswer != INT_MAX) && (subAnswer + 1 < minCoins))
            {
                minCoins = subAnswer + 1;
            }
        }
    }

    return minCoins;
}


int minCoinsRecMem(int amount, int coins[], int numCoins, int dp[])
{
    if (amount == 0)
    {
        return 0;
    }

    // Initialize ans to a large value
    int minCoins = INT_MAX;

    for (int i = 0; i < numCoins; i++)
    {
        //If we take the current coin, whats the amount left
        int amountLeft = amount - coins[i];

        // If it is possible to take this coin
        if (amountLeft >= 0)
        {
            //Initialise subAnswer
            int subAnswer = 0;

            //If we have already computed the answer, then use it
            if(dp[amountLeft] != -1)
            {
                subAnswer = dp[amountLeft];
            }
            else 
            {
                subAnswer = minCoinsRecMem(amountLeft, coins, numCoins, dp);
            }

            // In case where none of the coins are not possible, we will get
            // INT_MAX as subAnswer and we will check if that is the case
            if ((subAnswer != INT_MAX) && (subAnswer + 1 < minCoins))
            {
                minCoins = subAnswer + 1;
            }
        }
    }

    //Store answer in dp
    dp[amount] = minCoins;

    return minCoins;
}


int minCoinsIterative(int amount, int coins[], int numCoins)
{
    //Initialize a dp
    int dp[amount+1];
    for(int i = 0; i < amount+1; i ++)
    {
        dp[i] = amount + 1; //Initilize it to some large not possible value
    }

    dp[0] = 0;

    for(int currAmount = 1; currAmount < amount + 1; currAmount ++)
    {
        //Check for all coins
        for(int j = 0; j < numCoins; j ++)
        {
            //Check the amount left
            int amountLeft = currAmount - coins[j];

            if(amountLeft >= 0)
            {
                //+1 for the current coin which we are using
                dp[currAmount] = min(dp[amountLeft] + 1, dp[currAmount]);
            }
        }
    }

    if(dp[amount] != amount+1)
    {
        return dp[amount];
    }
    else //Not possible value
    {
        return -1;
    }
}



void solve()
{
    int numCoins;
    cin >> numCoins;

    int coins[numCoins] = {0};
    for (int i = 0; i < numCoins; i++)
    {
        cin >> coins[i];
    }

    int amount;
    cin >> amount;

    cout << minCoinsRec(amount, coins, numCoins) << endl;

    //Recursion with Memoization
    //Here any index of dp represents min number of coins required to makeup that amount
    int dp[amount + 1]; 


    //Initialising all values to -1
    for(int i = 0; i < amount+1; i ++)
    {
        dp[i] = -1;
    }

    //Initialise dp[0] to 0
    dp[0] = 0;

    cout << minCoinsRecMem(amount, coins, numCoins, dp) << endl;

    cout << "DP contains :" << endl;
    for(int i = 0; i < amount+1; i ++)
    {
        cout << dp[i] << " ";
    }

    cout << endl;

    cout << "Iterative dp: " << minCoinsIterative(amount, coins, numCoins) << endl; 
}

int main(void)
{
    int testCases;
    scanf("%d", &testCases);

    while (testCases--)
    {
        solve();
    }

    return 0;
}