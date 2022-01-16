// Got this from a "Bug of the Month" article
//  Just wanted to see it in action.
//  Incidentely, the bug is in the calulation of limit
//  Should be limit = sizeof(a);  the rest is gibberish.
#include <iostream>
using namespace std;

int an[4] = {1, 2, 3, 4};
int sum(int a[4]);

int main()
{
  cout << sum(an) << endl;
}

int sum(int a[4])
{
  int limit = sizeof(a) / sizeof(int);
  int result = 0;

  for(int i = 0; i < limit; i++)
    result += a[i];
  return result;
}
