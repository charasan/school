
#include <iostream>

using namespace std;

#define N    20

void insert(int n, int list[]);

int main()
{
  int i, num, max[N];


  for(i=0;i<N;i++)
    max[i] = -1-i;
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    insert(num,max);
  }
  for(i=0;i<N;i++)
    cout << max[i] << endl;
}
void insert(int n, int list[])
{
  int i, j;

  for(i=N-1;i>=0;--i)   // find where n goes
    if(list[i] > n)
      break;
  if(i == N-1)          // if n is smaller than last guy, leave
    return;
  for(j=N-2;j>i;--j)    // move everyone below where n goes down one
    list[j+1] = list[j];
  list[i+1] = n;        // put n where it goes
}
