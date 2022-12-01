#include<bits/stdc++.h>

using namespace std;


/*Keep count of the no K elements, and whenever we reach an non K element swap it with
  array[count]*/
void moveKtoEnd(int array[], int n, int K)
{
    //Count of number of non K elements
    //Inshort count represents the index of probable k, if it exists in our array
    int count = 0;

    for(int i = 0; i < n; i ++)
    {
        if(array[i] != K)
        {
            swap(array[i], array[count]);
            count ++;
        }
    }

}

int main(void)
{
    //Size of array
    int n;

    //Take input
    cin >> n;

    //Declare an array of size n
    int array[n];

    //Take array input
    for(int i = 0; i < n; i ++)
    {
        cin >> array[i];
    }

    moveKtoEnd(array, n, 0);

    //Print new array
    for(int i = 0; i < n; i ++)
    {
        cout << array[i] << " ";
    }

    return 0;
}