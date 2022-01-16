
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
  int t;
  int min,sec;

  t = time(0);
  sec = t % 60;
  min = t / 60;
  min = min % 60;
  cout << min << ":" << sec << endl;
}

