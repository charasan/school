#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

#define N     10

int main(int argc, char *argv[])
{
  char c;
  char grade[N], correct[N], name[N];
  int x, grd = 0, i = 0, fst = 1, key = 0;
  ifstream fd;

  fd.open(argv[1]);
  if(!fd)
  {
    cerr << "ERROR: Cannot find file: " << argv[1] << endl;
    exit(1);
  }

  for(x=0;x<N;x++)
  {
    correct[x] = 0;
    name[x] = 0;
    grade[x] = 0;
  }

  x = i = 0;

  for(;;)
  {
    c = fd.get();
    if(fd.eof())
      break;

    if(c != '\n')
    {
      if(c == ' ')
        key = 1;
      if(key == 0)
	name[x++] = c;

      else
      {
	if(fst)
	  correct[i++] = c;
	else
	  grade[i++] = c;
      }
    }

    else
    {
      grd = 0;

      for(x=0;x<N;x++)
	if(grade[x] == correct[x])
	  grd++;
      if(!fst)
        cout << setw(6) << name << " " << setw(2) << grd << endl;

      fst = 0;
      for(x=0;x<N;x++)
      {
	grade[x] = 0;
	name[x] = 0;
      }
      x = i = key = 0;
    } 
  }
  
  fd.close();
}
