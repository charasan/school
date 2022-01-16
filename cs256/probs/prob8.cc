//  Read a file of text and print the longest word in the file.
//  NOTE: This program isn't perfect.  It won't count compound
//   words joined by a hyphen, for example.  But for most
//   normal words, it should be fine :}
#include <iostream>
using namespace std;

#define WORDSIZE 31
void copyline(char dest[], char src[], int len);

int main()
{
  char c;
  char maxword[WORDSIZE], word[WORDSIZE];
  int x = 0, max = 0, i = 0;

  for(;;)
  {
    c = cin.get();
    if(cin.eof())
      break;
    if(((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
    {
      word[x] = c;
      x++;
    }
    else
    {
      if(x > max)
      {
	max = x;
        copyline(maxword, word, max);
      }
      for (i = 0;i<WORDSIZE;i++)
	word[i] = 0;
      x = 0;
    }
  }

  for(x=0;x<max;x++)
    cout.put(maxword[x]);
  cout << " (" << max << ")\n";
}

void copyline(char dest[], char src[], int len)
{
  int i;

  for(i = 0 ; i < len ; i++)
    dest[i] = src[i];
  dest[len] = 0;
}
