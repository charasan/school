#include <iostream>
#include <fstream>
using namespace std;

#define N  21

int main(int argc, char *argv[])
{
  char word[N];
  char c;
  int i, x = 0, bit = 0;
  ifstream fd;

  fd.open(argv[1]);

  if(!fd)
  {
    cerr << "ERROR:  Cannot find file - " << argv[1] << endl;
    exit(1);
  }

  for(i=0;i<N;i++)
    word[i] = 0;

  for(;;)
  {
    c = fd.get();
    if(fd.eof())
      break;

    if(c != '\n')
    {
      if(bit == 0)
      {
        word[x++] = c;
        if(x > 20)
          bit = 1;
      }

    }

    else
    {
      if(bit == 1)
      {
	cout << "Word too long - skipping.\n";
        bit = 0;
      }
      else
      {
        for(i=(20-x);i>0;i--)
	  cout << " ";
	cout << word << endl;
      }
      for(i=0;i<N;i++)
	word[i] = 0;
      x = 0;
    }
  }
  fd.close();
}
