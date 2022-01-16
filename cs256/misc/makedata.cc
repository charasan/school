// Written 11/13/2007 by Eddie Fuller
// I took the random number program generated in class and expanded upon it.
// Now the program prompts you for the # of random numbers, the highest value
// a random number should be, and the name of a file to pipe the data to.
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  int i, num, highest;
  char fle[50];

  srand(time(0));

  cout << "How many random numbers should be generated?\n";
  cin >> num;
  cout << "What should be the highest possible value of the numbers?\n";
  cin >> highest;
  cout << "What should the file be called?\n";
  cin >> fle;

  ofstream data(fle);

  if(num <= 1 || highest <= 1)
  {
    cerr << "Both numbers should be higher than 2 at least.\n";
    return 1;
  }
  for(i=1;i<num;i++){
    data << rand() % (highest+1) << endl;
  }
}

