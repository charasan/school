#include <iostream>
using namespace std;

int main()
{
    char c;
    int linenum = 1, lc = 0;
    int bigline = 0, max = 0;

    for(;;)
    {
	c = cin.get();
	if(cin.eof())
	    break;
	if((c >= 'a') && (c <= 'z'))
	    lc++;
        if(c == '\n') // new line, check & reset
	{
	    if(lc > max) // If they're equal, this will save the first
		         // such instance
	    {
		max = lc;
		bigline = linenum;
	    }
	    linenum++;
	    lc = 0;
	}
    }
    cout << bigline << " " << max << endl;
}
