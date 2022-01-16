#include <iostream>
#include <string>
using namespace std;

int main()
{
  string c("doggie");
  string d(5, 'c');
  string e(c, 2, 3);

  cout << c << endl;
  cout << d << endl;
  cout << e << endl;

  return 1;
}  
