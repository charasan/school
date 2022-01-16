
#include <iostream>

using namespace std;

#define N 1000

int main()
{
  int i;

  srand(time(0));
  for(i=0;i<N;i++){
    cout << rand() % 10 << endl;
  }
}

