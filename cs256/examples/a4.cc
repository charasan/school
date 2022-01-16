
#include <iostream>

using namespace std;

int getseconds(int t);
int getminutes(int t);

int main(int argc, char *argv[])
{
  int t;

  t = time(0);
  cout << getminutes(t) << ":" << getseconds(t) << endl;
}
int getseconds(int t)
{
  return t % 60;
}
int getminutes(int t)
{
  t /= 60;
  return t % 60;
}
