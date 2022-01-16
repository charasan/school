#include <iostream>
using namespace std;

#define MAXINTEGERS   999

int main()
{
  int all[MAXINTEGERS];
  int x, curr, cnt = 0, max = 0;

  for(x=0;x<MAXINTEGERS;x++)
    all[x] = -1;

  for(x = 0;;)
  {
    if(cin.eof())
      break;
    cin >> all[x++];
  }

  for(x=MAXINTEGERS;x>=0;x--)
  {
    if(all[x] >= 0)
    {
      max = all[x];
//      cout << all[x] << " - " << x << endl;
      break;
    }
  }
// DEBUG
//  cout << max << endl;

  for(x=MAXINTEGERS;x>=0;x--)
  {
    if(max == all[x])
      cnt++;
  }

  cout << cnt << endl;
}
