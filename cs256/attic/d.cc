#include <iostream>
using namespace std;

int main()
{
    int x, y;

//  Read numbers from a file until a zero is read
    x = y = 0;

    do
    {
      cin >> x;
      y = x + y;
    }
    while(x != 0);

    cout << "The sum of the numbers entered is " << y << ".\n";
}
