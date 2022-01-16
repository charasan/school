#include <iostream>
using namespace std;

#define MAXINTEGERS   1024

int main()
{
  int all[MAXINTEGERS];
  int x, i, curr = 0, cnt = 0, max = 0;

  for(x=0;x<MAXINTEGERS;x++)
    all[x] = -1;

  for(;;)
  {
    cin >> all[curr++];
//    cin >> i;
    if(cin.eof())
      break;
//    all[curr++] = i;
  }

  max = all[curr - 1];

  for(x=curr;x>=0;x--)
    if(all[x] == max)
      cnt++;

  cout << cnt << endl;
}
