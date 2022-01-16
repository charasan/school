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
	if(((c >= 'a') && (c <= 'z'))
        || ((c >= 'A') && (c <= 'Z')))
	    curlen++;
	else
	{
	    if(curlen > longest)
		longest = curlen;
            curlen = 0;
	}
    }

    cout << longest << endl;
}
