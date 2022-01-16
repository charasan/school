/*
 * Eddie Fuller - CS256
 *  This program reads in numbers from a file, ranging from 0 to 100
 *  This program counts how many times each number appears in the file,
 *    and spits out which occurs the most often, and how many times.
 * - October 11, 2007
 */

#include <iostream>
using namespace std;

int main()
{
    int hist[101];
    int i, num, max, top;

// Initialize our variables first of all
    max = top = 0;
    for(i=0;i<=100;i++)
        hist[i] = 0;

    for(;;)
    {
        cin >> num;
        if(cin.eof()) break;
        if(num < 0 || num > 100) return 0; // Wrong data types - exit program
        hist[num]++;
    }
    
    for(i=0;i<=100;i++)
    {
        if(hist[i] > max)
        {
            max = hist[i];
            top = i;
        }
    }
    cout << "The number " << top << " occurs the most often, appearing " << max << " times.\n";
    return 1;
}
