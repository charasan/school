#include <iostream>
using namespace std;

#define DEFAULT_MAX     -2147483467

int main()
{
    int x, max, sum;

    sum  = 0;
    max = DEFAULT_MAX;

    for(;;)
    {
        cin >> x;
        if(cin.eof())  break;
        if(x > max)  max = x;
        sum += x;
    }

    cout << "The largest integer was " << max << ", while the sum is " << sum << ".\n";
    return 1;
}
