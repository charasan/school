// Oddly enough, this program works just fine in a Windows environment
//  For some reason, though, it doesn't seem to work in Linux
//  Must be something with the time() function from one environment
//  to another.
#include <iostream>
using namespace std;

int main()
{
    int x, i = 0;
    char *c = "I type slow";

    x = time(0) + 1;
    
    for(;;)
    {
        if(time(0) <= x)
            continue;
        else
        {
          if(!c[i]) 
          {
              cout << endl;
              break;
          }
          else
          {
              cout << c[i];
              i++;
              x = time(0) + 1;
          }
          continue;
        }
    }
}
