// Assignment #1
//  Eddie Fuller, CS258
//  - Array implementation of stack used to determine
//    if grouping symbols are being used properly.
#include <iostream>
#include <fstream>
using namespace std;

const int DefaultListSize = 100;
typedef char Elem;

#define TRUE      1
#define FALSE     0

bool opener(char ch);
bool closer(char ch);
bool match(char ch1, char ch2);

class AStack
{
  private:
    int size;         // Maximum size of stack
    int top;          // Index for top element
    Elem *listArray;  // Array holding stack elements

  public:
    AStack(int sz = DefaultListSize)
    {
      size = sz;
      top = 0;
      listArray = new Elem[sz];
    }

    ~AStack()
    {
      delete [] listArray;
    }

    void clear() { top = 0; }

    bool push(const Elem& item)
    {
      if(top == size) return false;
      else
      {
	listArray[top++] = item;
	return TRUE;
      }
    }

    bool pop(Elem& it)
    {
      if(top == 0) return 0;
      else
      {
	it = listArray[--top];
	return TRUE;
      }
    }

    bool topValue(Elem& it) const
    {
      if(top == 0) return false;
      else
      {
	it = listArray[top-1];
	return TRUE;
      }
    }

    int length() const { return top; }

    bool IsEmpty() const { return (top==0); }
};

int main(int argc, char *argv[])
{
  AStack S;
  ifstream fd;
  int error = FALSE, x = 0;
  char ch, chs;

  fd.open(argv[1], ios::in);
  if(!fd)
  {
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }

  for(;;)
  {
    ch = fd.get();
    if(fd.eof())
      break;
    if(ch != '\n')
    {
      cout << ch;

      if(opener(ch)) S.push(ch);

      if(closer(ch))
      {
	if(S.IsEmpty())
	  error = TRUE;
	else
	{
	  S.pop(chs);
	  if(!match(chs, ch)) error = TRUE;
	}
      }
      continue;
    }
    if(!S.IsEmpty()) error = TRUE;
    if(error)
      cout << ": BAD String\n";
    else
      cout << ": GOOD String\n";
    error = FALSE;
    S.clear();
  }

  return 1;
}

bool opener(char ch)
{
  if((ch == '(') || (ch == '[') || (ch == '{')) return TRUE;
  else return FALSE;
}

bool closer(char ch)
{
  if((ch == ')') || (ch == ']') || (ch == '}')) return TRUE;
  else return FALSE;
}

bool match(char ch1, char ch2)
{
  if((ch1 == '(' && ch2 == ')')
   ||(ch1 == '[' && ch2 == ']')
   ||(ch1 == '{' && ch2 == '}'))
  return TRUE;

  else return FALSE;
}
