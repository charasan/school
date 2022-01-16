
#include <iostream>

using namespace std;

int main()
{
  char c;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(c == ' ')
      c = '\n';
    cout.put(c);
  }
}

