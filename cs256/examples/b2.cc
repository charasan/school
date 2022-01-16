
#include <iostream>

using namespace std;

int main()
{
  int n, sum;

  sum = 0;
  for(;;){
    cin >> n;
    if(cin.eof())
      break;
    if((n >= 1) && (n <= 9))
      sum += n;
  }
  cout << sum << endl;
}

