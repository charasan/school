
#include <iostream>

using namespace std;

int main()
{
  char c;
  int nc = 0;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    nc++;
  }
  cout << nc << endl;
}

