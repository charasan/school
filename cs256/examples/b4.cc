
// Find shortest line in a file

#include <iostream>

#define N 1024

using namespace std;

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
        for(i=0 ; i < n ; i++)
          save[i] = line[i];
        save[n] = 0;
        maxlinelen = n;
      }
      n = 0;
    }
  }
  cout << maxlinelen << endl;
  cout << "manually\n";
  for(i = 0 ; save[i] != 0 ; i++)
    cout.put(save[i]);
  cout << "automatic\n";
  cout << save;
}

