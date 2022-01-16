#include <iostream>
using namespace std;

#define GRADES_A  90

int main()
{
    int num, grades;

    num = grades = 0;

    for(;;)
    {
      cin >> num;
      if(cin.eof())
	break;
      if(num >= GRADES_A)
        grades++;
    }
    
    cout << "A " << grades << endl;
}
