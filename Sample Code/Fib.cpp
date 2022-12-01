#include<bits/stdc++.h>

using namespace std;
 

int fib(int n)
{  
    // Declare an array to store
    int f[n + 2];
    int i;
 
    // 0th and 1st number of the
    // series are 0 and 1
    f[0] = 0;
    f[1] = 1;
 
    for(i = 2; i <= n; i++)
    {
         
       //Add the previous 2 numbers
       // in the series and store it
       f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}



int fibBetterSpace(int n)
{  
    if(n == 0)
    {
        return 0;
    }

    // 0th and 1st number of the
    // series are 0 and 1
    int prevOne = 0;
    int prevTwo = 1;
 
    for(int i = 2; i <= n; i++)
    {
         
       //Add the previous 2 numbers
       int nextFib = prevOne + prevTwo;

       //Update the two variables to last two fibonacci numbers
       prevOne = prevTwo;
       prevTwo = nextFib;
    }
    return prevTwo;
}
 
int main ()
{
    int n = 2;
     
    cout << fib(n) << endl;

    cout << fib(n) << endl;

    return 0;
}