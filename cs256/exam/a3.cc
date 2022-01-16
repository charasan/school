//  3. Write a program that reads a file one character at a time and 
//     counts the numbers of times the same character appears 
//     twice in a row.

#include <iostream>
using namespace std;

int main()
{
  char c, prev = 0;
  int x = 0;

  for(;;)
  {
    c = cin.get();
    if(cin.eof())
      break;
// Set this up so it doesn't count blank spaces or newlines
// However, prev can be a space, since "iota and"
// doesn't constitute "in a row"...technically...
    if((c == prev) && (c != ' ') && (c != '\n'))
      x++;
    prev = c;
  }

  cout << x << endl;
}
