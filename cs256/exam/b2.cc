// I realize this isn't the best way to do this.
//  A number like 009 would mess this up, but
//  given that I can review the file being used
//  for the purposes of this program, this works :)
#include <iostream>
using namespace std;

int main()
{
    int x, sum = 0;

    for(;;)
    {
	cin >> x;
	if(cin.eof())
	    break;
        if(x < 10)
	    sum += x;
	else
	    continue;
    }
    cout << sum << endl;
}
