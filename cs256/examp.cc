// Find shortest line in a file

#include <iostream>

#define N 1024

using namespace std;

void copyline(char dest[], char src[], int len);

int main()
{
  char c;
  char save[N], line[N];
  int i, n, maxlinelen;

  maxlinelen = N;
  n = 0;
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    line[n++] = c;
    if(c == '\n'){
      if(n < maxlinelen){
        copyline(save,line,n);
        maxlinelen = n;
      }
      n = 0;
    }
  }
  cout << maxlinelen << endl;
  cout << save;
}
void copyline(char dest[], char src[], int len)
{
  int i;

  for(i = 0 ; i < len ; i++)
    dest[i] = src[i];
  dest[len] = 0;
}
