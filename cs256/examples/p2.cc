
#include <iostream>

using namespace std;

int main()
{
  int n,ct;

  ct = 0;
  for(;;){
    cin >> n;
    if(cin.eof())
      break;
    if(n == 100)
      ct++;
  }
  cout << ct << endl;
}

