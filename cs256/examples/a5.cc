
#include <iostream>
#include <string>
#include <iomanip>

#define TIMEZONE 5

using namespace std;

int getseconds(int t);
int getminutes(int t);
int gethours(int t);
int getdays(int t);
int getmonths(int t);
int getdayofmonth(int t);
int getyears(int t);

string days[]={
  "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"
};

string months[]={
  "Jan", "Feb", "Mar", "Apr", "May", "Jun",
  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

int monthdays[]={
  31, 28, 31, 30, 31, 30,
  31, 31, 30, 31, 30, 31
};


int main(int argc, char *argv[])
{
  int t;

  t = time(0) - TIMEZONE*3600;

  cout << days[getdays(t)] << "  "
       << "  " << months[getmonths(t)] << "  "
       << setw(2) << getdayofmonth(t) << "  "
       << setw(4) << getyears(t) << "  "
       << setw(2) << gethours(t) << ":"
       << setw(2)<<  getminutes(t)
       << ":" << setw(2) << getseconds(t) << endl;
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
int gethours(int t)
{
  t /= 3600;
  return t % 24;
}
int getdays(int t)
{
  t /= 86400;  // 86,400 seconds per day
  cout << "days since beginning of time = " << t << endl;
  return (t + 4) % 7;
}
int getyears(int t)
{
  int i,sum;

  t /= 86400;
  for(i=1970;;i++){
    if(i%4 == 0)
      t -= 366;
    else
      t -= 365;
    if(t <= 0)
      return i;
  }
}
int getmonths(int t)
{
  int i,sum;

  t /= 86400;
  for(i=1970;;i++){
    if(i%4 == 0){
      t -= 366;
      if(t < 366)
        break;
    } else {
      t -= 365;
      if(t < 365)
        break;
    }
  }
  for(i=0;;i++){
    t -= monthdays[i];
    if(t < 0)
      return i;
  }
}
int getdayofmonth(int t)
{
  int i,sum;

  t /= 86400;
  for(i=1970;;i++){
    if(i%4 == 0){
      t -= 366;
      if(t < 366)
        break;
    } else {
      t -= 365;
      if(t < 365)
        break;
    }
  }
  for(i=0;;i++){
    t -= monthdays[i];
    if(t < monthdays[i])
      return t+1;
  }
}
