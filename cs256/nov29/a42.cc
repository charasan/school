// The real solution to problem 4 on Nov29.
//  I was needlessly overcomplicating things.
#include <iostream>
using namespace std;

int main()
{
  int x;
  int all[1000];

  for(x=0;x<1000;x++)
    all[x] = 0;

  for(;;)
  {
    cin >> x;
    if(cin.eof())
    {
      cout << all[x] << endl;
      break;
    }
    all[x]++;
  }
}
