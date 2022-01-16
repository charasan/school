#include <iostream>
#include <fstream>
using namespace std;

#define N     1024

int main(int argc, char *argv[])
{
  char line[N];
  char c;
  int x, i = 0;
  ifstream fd;

  fd.open(argv[1]);
  if(!fd)
  {
    cerr << "ERROR: Cannot find file: " << argv[1] << endl;
    exit(1);
  }

  for(x=0;x<N;x++)
    line[x] = 0;

  for(;;)
  {
    c = fd.get();
    if(fd.eof())
      break;

    if(c != '\n')
    {
      line[i] = c;
      i++;
    }

    else
    {
      if(line[i-1] == '.')
	cout << line << endl;
      i = 0;
      for(x=0;x<N;x++)
	line[x] = 0;
    }
  }

  fd.close();
}
