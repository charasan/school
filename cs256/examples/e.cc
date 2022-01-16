
#include <iostream>

using namespace std;

char *oldc = "abcdefghijklmnopqrstuvwxyz";
char *newc = "qwertyuioplkhgfdsazxcvbnmj";

int main()
{
  char c;
  int i,n;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if((c >= 'a') && (c <= 'z')){
      for(i=0;i<26;i++)
        if(c == oldc[i]){
          n = i;
          break;
        }
      c = newc[n];
    }
    cout.put(c);
  }
}

