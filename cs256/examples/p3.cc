
#include <iostream>

using namespace std;

int main()
{
  int n,max;

  cin >> max;
  for(;;){
    cin >> n;
    if(cin.eof())
      break;
    if(n > max)
      max = n;
  }
  cout << max << endl;
}

