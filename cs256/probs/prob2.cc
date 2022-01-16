//  Read a file of integers and print the two largest values in the file.
#include <iostream>
using namespace std;

#define ARRAYSIZE 2

int main()
{
  int x, max[ARRAYSIZE];

  for(x=0;x<ARRAYSIZE;x++)
    max[x] = -1;

  for(;;)
  {
    cin >> x;
    if(cin.eof())
      break;
    if(x > max[0]) max[0] = x;
    else if((x > max[1]) && (x < max[0])) max[1] = x;
  }

  for(x=0;x<ARRAYSIZE;x++)
    cout << max[x] << endl;
}
