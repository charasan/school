
#include <iostream>

#define NSCORES  101

using namespace std;

int main()
{
  int histo[NSCORES];
  int num, max, score, i;

  for(i=0;i<NSCORES;i++)
    histo[i] = 0;

  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    histo[num]++;
  }
  max = -1;
  for(i=0;i<NSCORES;i++)
    if(histo[i] > max){
      max = histo[i];
      score = i;
    }
  cout << score << " " << max << endl;
}

