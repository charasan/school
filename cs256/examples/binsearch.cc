
#include <iostream>
#include <fstream>
#include <iomanip>

#define MAXLISTSIZE 10000

#define NUMBERFILE "numberfile"

using namespace std;

void printlist(int li[], int n);
void sortlist(int li[], int n);
int binarysearch(int key, int list[], int n);

int main(int argc, char *argv[])
{
  ifstream fd;   
  int list[MAXLISTSIZE];
  int listsize;
  int num, key, pos;

  fd.open(NUMBERFILE,ios::in);    // open the file for reading
  if(!fd){
    cerr << "Cannot open " << NUMBERFILE << endl;
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
  sortlist(list,listsize);
  for(;;){
    cout << "enter a number: ";
    cin >> key;
    pos = binarysearch(key,list,listsize);
    if(pos < 0)
      cout << key << " is not on the list" << endl;
    else
      cout << key << " was found at position " << pos << endl;
  }
}
void printlist(int li[], int n)
{
  int i;

  for(i=0;i<n;i++)
    cout << setw(6) << li[i] << endl;
}
void sortlist(int li[], int n)
{
// Selection Sort

  int i,j,min,where;

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
  }
}
int binarysearch(int key, int li[], int n)
{
  int lo, hi, mid;

  lo = 0;
  hi = n-1;
  while(lo <= hi){
    mid = (lo+hi)/2;
    cout << "lo = " << lo << ", hi = " << hi << ", mid = " << mid << endl;
    cout << "list[mid]=" << li[mid] << endl;
    if(li[mid] == key)
      return mid;
    else if(li[mid] > key)
      hi = mid-1;
    else
      lo = mid+1;
  }
  return -1;
}
