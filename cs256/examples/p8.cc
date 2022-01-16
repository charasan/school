
#include <iostream>

using namespace std;

// antidisestablishmentarianism

int main()
{
  char c;
  int current = 0,longest = 0;

  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if((c >= 'a') && (c <= 'z')){
      current++;
    } else if(current > 0){
      if(current > longest)
        longest = current;
      current = 0;
    }
  }
  cout << longest << endl;
}

