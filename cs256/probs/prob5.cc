//  Read a file containing one digit integers (0 to 9), and count how many 
//   times each integer appears in the file.
#include <iostream>
#include <iomanip>

using namespace std;

#define ARRAYSIZE 10

int main()
{
  int count[ARRAYSIZE];
  int x;

  for(x=0;x<ARRAYSIZE;x++)
    count[x] = 0;

  for(;;)
  {
    cin >> x;
    if(cin.eof())
      break;
    if((x < 0) || (x > 9)) continue;
    count[x]++;
  }

  for(x=0;x<ARRAYSIZE;x++)
    cout << setw(1) <<  x << ":" << setw(2) << count[x] << endl;
}
