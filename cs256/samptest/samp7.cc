#include <iostream>
using namespace std;

int main()
{
    char c;
    int curlen = 0;
    int longest = 0;
 
    for(;;)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	if(c == '\n')
	{
	    if(curlen > longest)
		longest = curlen;
            curlen = 0;
	}
	else
	    curlen++;
    }

    cout << longest << endl;
}
