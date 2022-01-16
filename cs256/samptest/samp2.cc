#include <iostream>
using namespace std;

int main()
{
    int x, max;

    max = -1;

    for(;;)
    {
	cin >> x;
	if(cin.eof())
	    break;
	if(x > max)
	    max = x;
    }
    cout << max << endl;
}
