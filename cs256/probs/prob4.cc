//  Read a file of integers and print the ten largest values in the file.
//   I wrote prob3.cc so all you need to do is adjust the ARRAYSIZE to
//   find the x largest integers in a file :P
#include <iostream>
using namespace std;

#define ARRAYSIZE 10

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
