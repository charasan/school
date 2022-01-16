
#include <iostream>

using namespace std;

int main()
{
  char c;
  int ct;

  ct = 0;
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if((c >= 'A') && (c <= 'Z'))
      ct++;
  }
  cout << ct << endl;
}

