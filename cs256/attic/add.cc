// Written by Eddie Fuller (CS256)
//
// I wrote this program to check the results of grades1.cc and
//  grades2.cc
//  I pipe the results of grep -c for each grade range into a file,
//  then run this program on the file to compare the results.
// Mathematical concept - always check your work :)
#include <iostream>
using namespace std;

int main()
{
    int x, sum;
    sum = x = 0;

    for(;;)
    {
	cin >> x;
        if(cin.eof())
	  break;
	sum += x;
    }
    cout << sum << endl;
}
