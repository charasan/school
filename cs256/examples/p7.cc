
#include <iostream>

using namespace std;

int main()
{
  char c;
  int current,longest;

  longest = current = 0;
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(c != '\n'){
      current++;
    } else {
      if(current > longest)
        longest = current;
      current = 0;
    }
  }
  cout << longest << endl;
}

