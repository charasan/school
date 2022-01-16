
#include <iostream>

using namespace std;

int main()
{
  char c;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if((c >= 'a') && (c <= 'z'))
      c = c - ('a' - 'A');
    cout.put(c);
  }
}

