#include <iostream>
using namespace std;

int main()
{
  int x = 0, sum = 0;

  for(;;)
  {
    cin >> x;
    if(cin.eof())
      break;
    sum += x;
  }

  cout << sum << endl;
}
