
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
    if((n > 0) && (n%2 == 1))
      ct++;
  }
  cout << ct << endl;
}

