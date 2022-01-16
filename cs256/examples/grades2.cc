
#include <iostream>

#define SYMS     "ABCDF"
#define NGRADES   5

#define GRADE_A  90
#define GRADE_B  80
#define GRADE_C  70
#define GRADE_D  60

#define COUNT_A   0
#define COUNT_B   1
#define COUNT_C   2
#define COUNT_D   3
#define COUNT_F   4

using namespace std;


int main()
{
  int i, num;
  int count[NGRADES];
  char *gradesymbol = SYMS;
 
  for(i = 0 ; i < NGRADES ; i++)
    count[i] = 0;
  for(;;){
    cin >> num;
    if(cin.eof())
      break;
    if(num >= GRADE_A)
      count[COUNT_A]++;
    else if(num >= GRADE_B)
      count[COUNT_B]++;
    else if(num >= GRADE_C)
      count[COUNT_C]++;
    else if(num >= GRADE_D)
      count[COUNT_D]++;
    else
      count[COUNT_F]++;
  }
  for(i = 0 ; i < NGRADES ; i++)
    cout << gradesymbol[i] << "  " << count[i] << endl;
}

