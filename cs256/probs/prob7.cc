//  Read a file containing at most 100 integers into an array of integers, 
//   find the average, and print the integer closest to the average.
// (The array seems a bit superfluous...this can be done w/o an array,
//  but oh well)
#include <iostream>

using namespace std;

#define ARRAYSIZE 100

int main()
{
  int nums[ARRAYSIZE];
  int x = 0, sum = 0, count = 0, mean, answer = -1;

  for(x=0;x<ARRAYSIZE;x++)
    nums[x] = 0;

  for(count = 0;;count++)
  {
    cin >> x;
    if(cin.eof())
      break;
    nums[count] = x;
    sum += x;
  }

  mean = sum / count;
  for(x=0;x<ARRAYSIZE;x++)
  {
    if((nums[x]+x == mean) && answer != -1)
      answer = nums[x] + x;
    else if((nums[x]-x == mean) && answer != -1)
      answer = nums[x] - x;
    else if(nums[x] == mean)
      answer = nums[x];
    else continue;
  }
  cout << mean << ":" << answer << endl;
}
