
#include <iostream>

using namespace std;

int main()
{
  char c;
  int linenum, count, maxcount, where;

  maxcount = -1;
  linenum = 1;
  count = 0;
  for(;;){
    c = cin.get();
    if(cin.eof())
      break;
    if(c != '\n'){
      if((c >= 'a') && (c <= 'z'))
        count++;
    } else {
      if(count > maxcount){
        where = linenum;
        maxcount = count;
      }
      count = 0;
      linenum++;
    }
  }
  cout << where << " " << maxcount << endl;
}

