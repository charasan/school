#include <iostream>
using namespace std;

#define LINESIZE 100
void copyline(char dest[], char src[], int len);

int main()
{
  char c;
  char maxline[LINESIZE], line[LINESIZE];
  int x = 0, max = 0, i = 0;

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
      }
      for (i = 0;i<LINESIZE;i++)
	line[i] = 0;
      x = 0;
    }
  }

  cout << max << ": ";
  for(x=0;x<max;x++)
    cout.put(maxline[x]);
  cout << endl;
}

void copyline(char dest[], char src[], int len)
{
  int i;

  for(i = 0 ; i < len ; i++)
    dest[i] = src[i];
  dest[len] = 0;
}
