// Sample Program written under Unix
//  Eddie Fuller - CS256
#include <iostream>
using namespace std;

int main()
{
    char c;

    cout << "You are in a 10X10 plain room with exits in the cardinal directions.\n";
    cout << "Which way to you wish to go?\n";

    for(;;)
    {
      cin.get(c);

      switch(c)
      {
         case '\n':
           break;

         case 's': case 'S': case 'w': case 'W': case 'e': case 'E':
           cout << "You were eaten by a grue.  Game over.\n";
           return 1;

         case 'n': case 'N':
           cout << "You escaped to freedom!  You win!\n";
           return 1;
         
         case 'l':
           cout << "You are in a 10X10 plain room with exits in the cardinal directions.\n";
           cout << "Which way to you wish to go?\n";
           break;
         
         default:
           cout << "You cannot go that way.\n";
           break;
      }
    }
    
}
