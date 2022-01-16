#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  int flag = 1;
  char x;

  fd.open(argv[1], ios::in);
  if(!fd)
  {
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }

  for(;;)
  {
    ch = fd.get();
    if(fd.eof())
      break;
    if(ch != '\n')
    {
      if((x >= 'a') && (x <= 'z'))
        x = x+32;
    )
    if(!flag)
    {
      if((x >= 'A') && (x <= 'Z'))
        x = x-32;
    }

  cout << x << endl;
  return 1;
}
