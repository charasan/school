
#include <iostream>

using namespace std;

int square(int n);

int main()
{
  int n;

  cin >> n;
  cout << square(n) << endl;
}
int square(int n)
{
  return n*n;
}
