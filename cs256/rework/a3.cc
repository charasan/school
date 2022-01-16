#include <iostream>
using namespace std;

#define LINESIZE 100
void copyline(char dest[], char src[], int len);

int main()
{
  char c;
  char maxline[LINESIZE], line[LINESIZE];
  int i, x = 0, max = 0, linenum = 1, maxlinenum = 1;

  for(;;)
  {
    c = cin.get();
    if(cin.eof())
      break;
    if(c != '\n')
    {
      line[x] = c;
      x++;
    }
    else
    {
      if(x > max)
      {
	max = x;
        copyline(maxline, line, max);
	maxlinenum = linenum;
      }
      for (i = 0;i<LINESIZE;i++)
	line[i] = 0;
      x = 0;
      linenum++;
    }
  }

// An array can be used in cout without a for loop to read each separate.

  cout << maxlinenum << ": " << maxline << endl;

}

void copyline(char dest[], char src[], int len)
{
  int i;

  for(i = 0 ; i < len ; i++)
    dest[i] = src[i];
  dest[len] = 0;
}
