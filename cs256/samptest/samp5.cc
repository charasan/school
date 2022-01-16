#include <iostream>
using namespace std;

int main()
{
    char c;
    int x = 0;
 
    for(;;)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	if(c == '\n')
	    x++;
    }

    cout << x << endl;
}
