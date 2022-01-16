
#include <iostream>

using namespace std;

int main()
{
  int num,max;

  cin >> max;
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num > max)
      max = num;
  }
  cout << max << endl;
}

