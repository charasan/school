#include <iostream>
#include <fstream>
using namespace std;

#define N     100

int main(int argc, char *argv[])
{
  char c;
  char line[N];
  int x;
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
      x++;
    }

    else
    {
      if((line[0] > 'A') && (line[0] < 'Z'))
	cout << line << endl;
      for(x=0;x<N;x++)
	line[x] = 0;
      x = 0;
    }
  }
  
  fd.close();
}
