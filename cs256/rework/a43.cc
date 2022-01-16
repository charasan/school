//  Written 12/4/07 by Eddie Fuller
//   This is problem #4 on Exam 2.  This version opens the file
//   using fstream to read into an array.  This version is still
//   limited by the array size declared, however, as the previous
//   versions were.

#include <iostream>
#include <fstream>
using namespace std;

#define N    1024

int main(int argc, char *argv[])
{
  int all[N];
  ifstream fle;
  int x, i = 0, cnt = 0, top = 0;

  fle.open(argv[1]);

  if(!fle)
  {
    cerr << "Error opening file: " << argv[1] << endl;
    exit(0);
  }

  for(x=0;x<N;x++)
    all[x] = 0;

  for(;;)
  {
    fle >> x;
    
    if(fle.eof())
      break;
    
    all[i++] = x;
  }

  fle.close();

  top = all[i - 1];

  for(x=0;x < i;x++)
    if(top == all[x])
      cnt++;

  cout << cnt << endl;
}
