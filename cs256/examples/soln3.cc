
#include <iostream>

using namespace std;

int main()
{
  int i, tmp, num, max[3];

// max[0] will contain largest
// max[1] will contain second largest
// max[2] will contain third largest

  max[0] = -1;
  max[1] = -2;
  max[2] = -3;

  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num > max[0]){
      max[2] = max[1];
      max[1] = max[0];
      max[0] = num;
    } else if(num > max[1]){
      max[2] = max[1];
      max[1] = num;
    } else if(num > max[2]){
      max[2] = num;
    }
  }
  for(i=0;i<3;i++)
    cout << max[i] << endl;
}

