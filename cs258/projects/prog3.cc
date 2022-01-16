// Assignment #3
//  Eddie Fuller, CS258
//  - Array implementation of stack along with a queue used to
//    pack palindromes and determine if a string IS a packed
//    palindrome.
#include <iostream>
#include <fstream>
using namespace std;

const int DefaultListSize = 50;
typedef char Elem;

#define TRUE      1
#define FALSE     0

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

    bool isEmpty() const { return (top==0); }
};

class AQueue
{
  private:
    int size;
    int front;
    int rear;
    int count;
    Elem *listArray;

  public:
    AQueue(int sz=DefaultListSize)
    {
      size = sz;
      clear();
      count = 0;
      listArray = new Elem[size];
    }
    
    ~AQueue() { delete [] listArray; } // Destructor, who fought Gigantor, I believe

    void clear()
    {
       rear = 0;
       front = 1;
    }

    bool enqueue(const Elem& it)
    {
      if(count == size)  return FALSE;
      rear = (rear+1) % size;  // Circular increment
      listArray[rear] = it;
      count++;
      return TRUE;
    }

    bool dequeue(Elem& it)
    {
      if(count == 0) return FALSE;
      it = listArray[front];
      front = (front+1) % size;  // Circular increment
      count--;
      return TRUE;
    }

    bool frontValue(Elem& it) const
    {
      if(count == 0) return FALSE; // empty
      it = listArray[front];
      return TRUE;
    }

    int length() const { return count; }

    bool isEmpty() const { return (count == 0); }
};

int main(int argc, char *argv[])
{
  AStack S;
  AQueue Q;
  ifstream fd;
  int flg = 0, cnt = 0;
  int error = 0;
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
      if(cnt == 0 && ch == '#') // This little section allows me
                                //  to add comments to the data file
      {
	flg = 1;
	cnt++;
	continue;
      }

      if(flg == 1) continue;

      cout << ch;
      if( ((ch >= 'A') && (ch <= 'Z'))
       || ((ch >= 'a') && (ch <= 'z')))
      {
	S.push(ch);
	Q.enqueue(ch);
	cnt++;
      }
      continue;
    }

    if(flg == 1)
    {
      cnt = error = flg = 0;
      continue;
    }
    if(S.length() != Q.length()) error = 1; // error checking
       // or 'idiot proofing' as we used to call it :)

    while(!S.isEmpty())
    {
      S.pop(ch);
      Q.dequeue(chs);
      if(ch == chs) continue;
      else error = 1;
    }
    if(!Q.isEmpty()) error = 1;

    if(!error) cout << " is a packed palindrome.\n";
    else cout << " is NOT a packed palindrome.\n";

    cnt = error = flg = 0;
    
  }
  return 1;

}
