#include <iostream>
using namespace std;

int main()
{
  int x, max = -1;

  for(;;)
  {
    if(cin.eof())
      break;
    cin >> x;
    if(x >= max)
      max = x;
  }

  cout << max << endl;
}
