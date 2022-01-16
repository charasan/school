#include <iostream>
using namespace std;

#define MAXINTEGERS   999

int main()
{
  int all[MAXINTEGERS];
  int x = 0, curr = 0, cnt = 0, max = 0;

  for(x=0;x<MAXINTEGERS;x++)
    all[x] = 0;

  for(;;)
  {
    if(cin.eof())
    {
      curr = all[x--];
      max = x--;
      break;
    }
    cin >> all[x++];
  }

//  cout << curr << " - " << max << endl;
  for(x=max;x>=0;x--)
  {
    cout << all[x] << endl;
    if(curr == all[x])
      cnt++;
  }

  cout << cnt << endl;
}
