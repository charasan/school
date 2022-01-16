
#include <iostream>
#include <fstream>
#include <iomanip>

#define MAXLISTSIZE 10000

using namespace std;

void printlist(int li[], int n);
void sortlist(int li[], int n);

int main(int argc, char *argv[])
{
  ifstream fd;   
  int list[MAXLISTSIZE];
  int listsize;
  int num;

  fd.open(argv[1],ios::in);    // open the file for reading
  if(!fd){
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }
  listsize = 0;
  for(;;){
    fd >> num;
    if(fd.eof())
      break;
    list[listsize++] = num;
  }
  fd.close();
  printlist(list,listsize);
  sortlist(list,listsize);
  printlist(list,listsize);
}
void printlist(int li[], int n)
{
  int i;

  cout << "the list:\n";
  for(i=0;i<n;i++)
    cout << setw(6) << li[i] << endl;
}
void sortlist(int li[], int n)
{
// Selection Sort

  int i,j,min,where;
  char c;

  for(i=0;i<n-1;i++){
    min = li[i];
    where = i;
    for(j=i+1;j<n;j++)
      if(li[j] < min){
        min = li[j];
        where = j;
      }
    if(where != i){
      li[where] = li[i];
      li[i] = min;
    }
    printlist(li,n);
    c = cin.get();
  }
}
