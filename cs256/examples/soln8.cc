
#include <iostream>

using namespace std;

#define TRUE   1
#define FALSE  0

#define WORDMAX 1024

int isletter(char c);

int main()
{
  int i, nc, nmax;
  char c, word[WORDMAX], longest[WORDMAX];

  nc = 0;
  nmax = 0;
  longest[0] = '\0';
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(isletter(c)){
      word[nc++] = c;
    } else {
      if(nc > nmax){
        nmax = nc;
        for(i=0;i<nc;i++)
          longest[i] = word[i];
        longest[nc] = 0;
      }
      nc = 0;
    }
  }
  cout << longest << endl;
}
int isletter(char c)
{
  if((c >= 'a') && (c <= 'z'))
    return TRUE;
  if((c >= 'A') && (c <= 'Z'))
    return TRUE;
  return FALSE;
}
