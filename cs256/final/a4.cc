#include <iostream>
#include <fstream>
using namespace std;

#define N     100

int main(int argc, char *argv[])
{
  char c;
  char line[N];
  int x, key = 0;
  ifstream fd;

  fd.open(argv[1]);
  if(!fd)
  {
    cerr << "ERROR: Cannot find file: " << argv[1] << endl;
    exit(1);
  }

  for(x=0;x<N;x++)
    line[x] = 0;

  x = 0;

  for(;;)
  {
    c = fd.get();
    if(fd.eof())
      break;

    if(c != '\n')
    {
      line[x] = c;
      if(c == ' ')
	key = 1;
      x++;
    }

    else
    {
      if(key == 0)
	cout << line << endl;
      for(x=0;x<N;x++)
	line[x] = 0;
      x = 0;
      key = 0;
    }
  }
  
  fd.close();
}
