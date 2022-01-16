// Assignment #5
//  Eddie Fuller, CS258
//  - Building a binary search tree to sort a file of integers
//    in increasing order.
#include <iostream>
#include <fstream>
using namespace std;

typedef int Elem;

struct TLink
{

    Elem element;

    TLink* Lchild; // pointer to left subtree
    TLink* Rchild; // pointer to right subtree
    TLink(const Elem& e, TLink* Lchildp = NULL, TLink* Rchildp = NULL)
    {
      element = e;
      Lchild = Lchildp;
      Rchild = Rchildp;
    }

    TLink(TLink* Lchildp = NULL, TLink* Rchildp = NULL)
    {
      Lchild = Lchildp;
      Rchild = Rchildp;
    }
};

// Function declarations need to go AFTER the struct, otherwise
// the compiler won't recognize them.  Good to know.
void BSTree(TLink *&T, Elem n);
void InOrder(TLink* T);

int main(int argc, char *argv[])
{
  int num;
  ifstream fd;
  TLink *Tr = NULL;

  fd.open(argv[1], ios::in);
  if(!fd)
  {
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }

  for(;;)
  {
    fd >> num;
    if(fd.eof())
      break;
    BSTree(Tr, num);
  }
  InOrder(Tr);
  cout << endl; // for screen formatting purposes
  fd.close();
  return 0;
}

void BSTree(TLink *&T, Elem n)
{
  if(T != NULL)
  {
    if(n <= T->element)      // we're randomly picking the equal elements
      BSTree(T->Lchild, n);  // to insert left
    else
      BSTree(T->Rchild, n);
  }

  else
    T = new TLink(n, NULL, NULL); // last two should not really be necessary
} // end BSTree

void InOrder(TLink* T)
{
  if(T != NULL)
  {
    InOrder(T->Lchild);
    cout << T->element << " ";
    InOrder(T->Rchild);
  }
} // end of InOrder

