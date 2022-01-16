
#include <iostream>

using namespace std;

#define N 100

int main()
{
  int i, num, count, ave, sum, dfa;  // dfa = Distance From Average
  int mindist, who;
  int list[N];

  count = 0;
  sum = 0;
  while(count < N){
    cin >> num;
    if(cin.eof())
      break;
    list[count++] = num;
    sum += num;
  }
  if(count == 0){
    cerr << "No numbers found\n";
  } else {
    ave = sum/count;
    mindist = list[0] - ave;
    if(mindist < 0)
      mindist = -mindist;
    who = 0;
    for(i=1;i<count;i++){
      dfa = list[i] - ave;
      if(dfa < 0)
        dfa = -dfa;
      if(dfa < mindist){
        mindist = dfa;
        who = i;
      }
    }
    cout << list[who] << " is " << mindist << " from " << ave << endl;
  }
}
