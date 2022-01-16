#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
  int x, cnt = 0;
  ifstream fd;

  fd.open(argv[1]);
  if(!fd)
  {
    cerr << "ERROR: Cannot find file: " << argv[1] << endl;
    exit(1);
  }

  for(;;)
  {
    fd >> x;
    if(fd.eof())
      break;

    if((x > 0) && (x < 100))
      cnt++;
  }
  
  fd.close();
  cout << cnt << endl;
}
