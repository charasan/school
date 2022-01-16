
#include <iostream>

#define GRADE_A  90
#define GRADE_B  80
#define GRADE_C  70
#define GRADE_D  60

using namespace std;

char *gradesymbol="ABCDF";  // character string

int main()
{
  int gradecount[5];

//
// initializes the gradecount array
//

  for(;;){
    cin >> score;
    if(cin.eof())
      break;
//
// increment (add one to) the appropriate gradecount
//   
  if(score >= GRADE_A)
    gradecount[0]++;
  else if(score >= ...)
    ....

  }
//
// print out information
//

  for(i = 0 ; i < 5 ; i++)
    cout << gradesymbol[i] << " " << gradecount[i] << endl;
}

