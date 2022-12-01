#include<iostream>

using namespace std;

int main(void)
{
    int a = 3;   //00011
    int b = 7;   //00111
    int c = 18;  //10010

    //Bitwise &
    unsigned int d = b&c; //00010

    //Bitwise |
    d = a|b;     //00111

    //Bitwise XOR
    d = a^b;     //00100

    //Left shift
    d = a << 2;  //01100

    //Right shift
    d = c >> 1;  //01001

    //One's Complement
    d = ~b;      //11000


    //Set 3rd bit of a to 1
    a = 10; //1010
    int mask = 1 << (3-1); // Create a mask
    a = a | mask; //Use bitwise operation


    //Clear 2nd bit of a
    a = 10; //1010
    mask = ~(1 << (2-1)); // Create a mask
    a = a & mask; //Use bitwise operation


    //Check if 2nd bit is set
    a = 10;
    mask = 1 << (2-1); //Create a mask
    if((a & mask) != 0)
    {
        cout << "Bit is set";
    }
    else 
    {
        cout << "Bit is not set";
    }

    return 0;
}