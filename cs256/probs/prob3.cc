//  Read a file of integers and print the three largest values in the file.
#include <iostream>
using namespace std;

#define ARRAYSIZE 3

int main()
{
  int x, i, max[ARRAYSIZE];

  for(x=0;x<ARRAYSIZE;x++)
    max[x] = -1;

  for(;;)
  {
    cin >> x;
    if(cin.eof())
      break;
    for(i=0;i<ARRAYSIZE;i++)
      if((x > max[i]) && (x < max[i-1]))  max[i] = x;
  }

  for(x=0;x<ARRAYSIZE;x++)
    cout << max[x] << endl;
}
