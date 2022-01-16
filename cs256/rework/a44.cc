// Written by Eddie Fuller - 12/4/07
//  This is problem #4 on Exam 2, done using fstream.
//  This version of the program doesn't rely on arrays, so
//  it should be fine for any sized file.  One thing I did learn
//  about fstream in this is that you can't reuse ifstream variables.

#include <iostream>
#include <fstream>
using namespace std;


int main(int argc, char *argv[])
{

  ifstream fle, fd;
  int x, i = 0, cnt = 0, top = 0;

  fle.open(argv[1]);

  if(!fle)
  {
    cerr << "Error opening file: " << argv[1] << endl;
    exit(0);
  }

  for(;;)
  {
    fle >> x;
    
    if(fle.eof())
    {
      top = x;
      break;
    }

  }

  fle.close();

  fd.open(argv[1]);

  if(!fd)
  {
    cerr << "Error: Missing file: " << argv[1] << endl;
    exit(0);
  }


  for(;;)
  {
    fd >> x;

    if(fd.eof())
      break;

    if(top == x)
      cnt++;
  }

  fd.close();

  cout << cnt << endl;
}
