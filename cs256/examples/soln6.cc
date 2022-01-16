
#include <iostream>

using namespace std;

#define LINEMAX 1024

int main()
{
  int i, nc;
  char c, line[LINEMAX];

  nc = 0;
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(c == '\n')
     break;
    line[nc++] = c;
    if(nc == LINEMAX)
      break;
  }
  for(i=nc-1;i>=0;--i)
    cout.put(line[i]);
  cout.put('\n');
}
