
#include <iostream>

using namespace std;

#define N 10

int main()
{
  int i, num, moon, histo[N];
//
// moon = Most Often Occurring Number
//

  for(i=0;i<N;i++)
    histo[i] = 0;
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num < 0)
      continue;
    if(num >= N)
      continue;
    histo[num]++;
  }
  moon = 0;
  for(i=1;i<N;i++)
    if(histo[i] > histo[moon])
      moon = i;
  cout << moon << " occurred " << histo[moon] << " times\n";
}
