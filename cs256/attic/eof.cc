//
// Arrays:
//   This one reads a file containing a list of
//   integers, one per line.  It stops when the
//   end of the file is reached.  A terminating
//   zero is not needed.
//
//   As it reads, it counts the number of integers
//   read.  It prints the count.

#include <iostream>

using namespace std;

int main()
{
  int num, count;

//
// initialize count to 0
//
  for(count = 0 ; ; count++){
    cin >> num;
    if(cin.eof())
      break;      // a break statement: it means 'exit the loop now'
  }
  cout << count << endl;
} 

