
#include <iostream>

#define GRADE_A  90

using namespace std;

int main()
{
  int count, num;
 
  count = 0;
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num >= GRADE_A)
      count++;
  }
  cout << "A " << count << endl;
}

