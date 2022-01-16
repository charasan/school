// Written 10/18/2007 by Edward Fuller
//
// I wrote this program in response to a comment my statistics
//  teacher made in class on Wednesday, about someone writing
//  a program to calculate a certain formula for the 99 permutations
//  needed to arrive at the correct answer, as opposed to working
//  out the problem the way we did in class.  I decided to take the
//  challenge :)
// Here's the problem being solved:
//   p(x)= (99 C x) * (.2^x) * (.8 ^ (99-x)), for x = 0, 1, 2, ..., 99
// What we want to find is what value(s) of x is p(x) max.
//
// This should work, in theory, however, 99! is so insanely huge,
//  the program croaks at the thought of it.
#include <iostream>
using namespace std;

long int factorial(int x);
float expo(float x, int y);

int main()
{
    int i;
    float cur;
    float done[100];

    for(i=0;i<=99;i++)
      done[i] = 0.0;


    for(i=0;i<=99;i++)
    {
      cur = factorial(99) / (factorial(i) * factorial(99-i));
      done[i] = cur*(expo(.2, i))*(expo(.8, (99-i)));
    }
    for(i=0;i<=99;i++)
      cout << "p(" << i << ") = " << done[i] << endl;

}

long int factorial(int x)
{
  if(x <= 1)
    return 1;
  else
    return x * factorial(x-1);
}

float expo(float x, int y)
{
    int i;
    float prod = 1.0;
    for(i=0;i<y;i++)
        prod *= x;
    return prod;
}

