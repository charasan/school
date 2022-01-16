
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
    if(c == '\n')
      ct++;
  }
  cout << ct << endl;
}

