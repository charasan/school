// Program #4 - Eddie Fuller
//  Implementing doubly linked lists to apend a string
//  first by adding a new b following the first c, and
//  then by removing the first b, each time printing the
//  string both forward and backward.
#include <iostream>
#include <fstream>

using namespace std;

typedef char Elem;

#define TRUE      1
#define FALSE     0
#define DLS       50

struct Node
{
  Elem element;
  Node *next;
  Node *prev;

  Node(const Elem& e, Node* prevp = NULL, Node* nextp = NULL)
  {
    element = e;
    prev = prevp;
    next = nextp;
  }

  Node(Node* prevp = NULL, Node* nextp = NULL)
  {
    prev = prevp;
    next = nextp;
  }

};

class LList
{
  private:
    Node* head;
    Node* tail;
    Node* fence;
    int leftcnt;
    int rightcnt;
    char ch;

    void init()
    {
      fence = tail = head = new Node;
      leftcnt = rightcnt = 0;
    }

    void removeall()
    {
      while(head != NULL)
      {
        fence = head;
        head = head->next;
        delete fence;
      }
    }

  public:
    LList(int size=DLS) { init(); }
    ~LList() { removeall(); }

    void clear()
    {
      removeall();
      init();
    }

    bool insert(const Elem& item);
    bool remove(Elem& it);
    bool prev();

    void setStart()
    {
      fence = head;
      rightcnt += leftcnt;
      leftcnt = 0;
    }

    void setEnd()
    {
      fence = tail;
      leftcnt += rightcnt;
      rightcnt = 0;
    }

    bool next()
    {
      if(fence != tail)
      {
        fence = fence->next;
        rightcnt--;
        leftcnt++;
        return TRUE;
      }
      return FALSE;
    }

    int leftLength() const { return leftcnt; }
    int rightLength() const { return rightcnt; }

    bool getValue(Elem& it) const
    {
      if(rightLength() == 0) return FALSE;
      it = fence->next->element;
      return TRUE;
    }

    void print_forward()
    {
      setEnd();
// This part threw me for a bit, then I realized that getValue() always prints
//  the value of the NEXT node, so I had to move to the fence to the previous
//  node in order to get it to print the values properly. -- Eddie
      fence = fence->prev;
      do
      {
        getValue(ch);
        if(leftLength() != 0)
          cout << ch;
      }
      while(prev());
      cout << endl;
    }

    void print_backwards()
    {
      setStart();

      do
      {
        getValue(ch);
        if(rightLength() != 0)
          cout << ch;
      }
      while(next());
      cout << endl;
    }

};

bool LList::insert(const Elem& item)
{
  Node *p;

  p = new Node;
  p->element = item;
  p->next = fence->next;
  p->prev = fence;

  if(fence != tail)
    fence->next->prev = p;
  else
    tail = p;
  
  fence->next = p;
  rightcnt++;
  return TRUE;
}

bool LList::remove(Elem& it)
{
  if(fence->next == NULL) return FALSE;
  it = fence->next->element;
  Node* ltemp = fence->next;
  if(ltemp->next != NULL) ltemp->next->prev = fence;
  else tail = fence;
  fence->next = ltemp->next;
  delete ltemp;
  rightcnt--;
  return TRUE;
}

bool LList::prev()
{
  if(fence != head)
  {
    fence = fence->prev;
    leftcnt--;
    rightcnt++;
    return TRUE;
  }
  return FALSE;
}

int main(int argc, char *argv[])
{
  ifstream fd;
  LList DL;
  char ch;

  fd.open(argv[1], ios::in);
  if(!fd)
  {
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }

  DL.setStart();

  for(;;)
  {
    ch = fd.get();
    if(fd.eof())
      break;
    if(ch != '\n')
    {
      cout << ch;  // First, print the original line forward
      DL.insert(ch);
      continue;
    }

    cout << endl;
// End original line forward

    DL.print_backwards();
    cout << endl;

// End original line backwards

    DL.setEnd();
    
    int cnt = 0;
    do // Now, insert a new b following first c
    {
      DL.getValue(ch);
      if((ch == 'c') && (cnt == 0))
      {
        cnt = 1;
        DL.insert('b');
      }
    }
    while(DL.prev()); // end insert

// Now, we print this new line forward and backwards

    DL.print_forward();
    DL.print_backwards();
    cout << endl;

// NOW, we remove the first b in the string
    DL.setEnd();
    cnt = 0;
    do
    {
      DL.getValue(ch);
      if((cnt == 0) && (ch == 'b'))
      {
        DL.remove(ch);
        cnt = 1;
      }
    }
    while(DL.prev());
// Now print the whole damned thing backward and forward again
    DL.print_forward();
    DL.print_backwards();
    cout << endl;
    cout << "========================================\n"; // A divider for next data

// Now, if we have additional lines, we can start all over again
    DL.clear();
    DL.setStart();
    cout << endl;
  }
}
