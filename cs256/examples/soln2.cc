
#include <iostream>

using namespace std;

int main()
{
  int tmp, num, max[2];

// max[0] will contain largest
// max[1] will contain second largest

  cin >> max[0];
  cin >> max[1];
  if(max[0] < max[1]){
    tmp = max[0];
    max[0] = max[1];
    max[1] = tmp;
  }
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num > max[0]){
      max[1] = max[0];
      max[0] = num;
    } else if(num > max[1]){
      max[1] = num;
    }
  }
  cout << max[0] << endl;
  cout << max[1] << endl;
}

