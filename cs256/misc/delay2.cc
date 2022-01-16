#include <iostream>
#include <string>
using namespace std;


int main()
{
  int i = 0;
  char *text = "I type slow";

  for(;;)
  {
    cout << text[i];
    i++;
    sleep(2);
    if(!text[i])
    {
	cout << endl;
	break;
    }
  }
}
