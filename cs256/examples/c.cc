
#include <iostream>

using namespace std;

int main()
{
  char c;
  int nlines = 0;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(c == '\n')
      nlines++;
  }
  cout << nlines << endl;
}

