// Assignment #2
//  Eddie Fuller, CS258
//  - Linked stack used to interpret "perfect data" concerning
//    postfix data.  Note that atof() won't work here for converting
//    char to float, because atof() reads from a string, sadly
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

const int DefaultListSize = 100;
typedef float Elem;

#define TRUE      1
#define FALSE     0

bool operand(char ch);
float eval(float lop, char x, float rop);
float to_float(char ch);

class Link
{
  public:
    Elem element;     // Value for this node
    Link *next;       // Pointer to next node in list
    Link(const Elem& elemval, Link* nextval = NULL)
    {
      element = elemval;
      next = nextval;
    }
    Link(Link* nextval = NULL) { next = nextval; }
};

class LStack
{
  private:
    Link* top;        // Pointer to first element
    int size;         // Count number of elements

  public:
    LStack(int sz=DefaultListSize)
    {
      top = NULL;
      size = 0;
    }

    ~LStack() { clear(); }   // Destructor
    void clear()
    {
      while(top != NULL)
      {
        Link* temp = top;
        top = top->next;
        delete temp;
      }
      size = 0;
    }

    bool push(const Elem& item)
    {
      top = new Link(item, top);
      size++;
      return TRUE;
    }

    bool pop(Elem& it)
    {
      if(size == 0) return FALSE;
      it = top->element;
      Link* ltemp = top->next;
      delete top;
      top = ltemp;
      size--;
      return TRUE;
    }

    bool topValue(Elem& it) const
    {
      if(size == 0) return FALSE;
      it = top->element;
      return TRUE;
    }

    int length() const { return size; }

    bool isEmpty() const
    {
      if(top == NULL) return TRUE;
      else return FALSE;
    }
};


int main(int argc, char *argv[])
{

  LStack S;
  ifstream fd;
  float val, rop, lop;
  char ch;
  int cnt = 0;

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
      cout << ch;  // Echo line back to screen
      cnt++;       // Counts characters in argument - just for formatting purposes
      if(operand(ch)) S.push(to_float(ch));
      else
      {
	S.pop(rop);
	S.pop(lop);
	val = eval(lop, ch, rop);
	S.push(val);
      }
      continue;
    }
    S.pop(val);
    cout << setw(15-cnt) << right << " == " << setw(10) << left << val << endl;
    cnt = 0;
  }
  return 1;
}

float to_float(char ch)
{
  switch(ch)
  {
    case '0':
      return 0.0;
    case '1':
      return 1.0;
    case '2':
      return 2.0;
    case '3':
      return 3.0;
    case '4':
      return 4.0;
    case '5':
      return 5.0;
    case '6':
      return 6.0;
    case '7':
      return 7.0;
    case '8':
      return 8.0;
    case '9':
      return 9.0;
    default:
      return 0.0;
  }
}

bool operand(char ch)
{
  if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4'
  || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9')
    return TRUE;

  else return FALSE;
}

float eval(float lop, char x, float rop)
{
  switch(x)
  {
    case '+':
      return (lop + rop);

    case '-':
      return (lop - rop);

    case '*':
      return (lop * rop);

    case '/':
      return (lop/rop);

    case '^':
      return pow(lop, rop);

    default:
      return 0.0;
  }
}

