
#include <iostream>

using namespace std;

int main()
{
  char c;
  int nuc = 0, nlc = 0;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if((c >= 'a') && (c <= 'z'))
      nlc++;
    else if((c >= 'A') && (c <= 'Z'))
      nuc++;
  }
  cout << "uppercase " << nuc << endl;
  cout << "lowercase " << nlc << endl;
}

