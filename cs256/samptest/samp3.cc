#include <iostream>
using namespace std;

int main()
{
    int x, count;

    count = 0;

    for(;;)
    {
	cin >> x;
	if(cin.eof())
	    break;
	if(x == 100)
	    count++;
    }

    cout << count << endl;
}
