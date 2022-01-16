#include <iostream>
using namespace std;

int main()
{
  int x, i;

  x = 6;

  for(i = 0; i < 100; i++)
  {
    x = x + 7;
    cout << x << endl;
  }

  return 0;
}
