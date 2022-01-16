//  Read one line of text into a character array, and print the line backwards.
#include <iostream>
using namespace std;

int main()
{
  char c;
  char txt[1024];
  int i;

  for(i=0;;i++)
  {
    c = cin.get();
    if(cin.eof())
      break;
    txt[i] = c;
  }

  for(i;i>=0;i--)
    cout << txt[i];
  cout << endl;
}
