//  Read a file of text and print the longest word in the file.
//  NOTE: This program isn't perfect.  It won't count compound
//   words joined by a hyphen, for example.  But for most
//   normal words, it should be fine :}
//  I started to try and do the same thing using strings, but
//   strings in C++ are missing things I'm used to, such as
//   explode().  I'll have to research how stings work and
//   try again later.
#include <iostream>
#include <string>
using namespace std;

// #define WORDSIZE 31
// void copyline(char dest[], char src[], int len);

int main()
{
  string c;
  string maxword;
  int x = 0, max = 0, i = 0;

  for(;;)
  {
    getline(cin, c);
    if(cin.eof())
      break;
    i = c.length();
    if(i > max)
    {
      max = i;
      maxword = c;
    }
  }

  cout << maxword << " (" << max << ")\n";
}
/*
void copyline(char dest[], char src[], int len)
{
  int i;

  for(i = 0 ; i < len ; i++)
    dest[i] = src[i];
  dest[len] = 0;
}
*/
