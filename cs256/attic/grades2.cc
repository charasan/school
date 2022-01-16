#include <iostream>
using namespace std;

#define GRADES_A  90
#define GRADES_B  80
#define GRADES_C  70
#define GRADES_D  60

char *letters = "ABCDF";

int main()
{
    int grades[5];
    int num, i;

    num = 0;
    for(i=0;i<5;i++)
	grades[i] = 0;

    for(;;)
    {
      cin >> num;
      if(cin.eof())
	break;
      if(num >= GRADES_A)
        grades[0]++;
      else if(num >= GRADES_B)
	grades[1]++;
      else if(num >= GRADES_C)
	grades[2]++;
      else if(num >= GRADES_D)
	grades[3]++;
      else
	grades[4]++;
    }
    
    for(i=0;i<5;i++)
	cout << letters[i] << " " << grades[i] << endl;
}
