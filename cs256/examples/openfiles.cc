
// 
// This program opens a file named as a command line
// argument using a declared file descriptor, fd.
// Pay close attention to the syntax of the line
// that opens the file.
// 
// When you run the program, give it the name of a
// text file as a command line argument, and it will
// open the file, read it a character at a time, and
// print the file to the terminal window.
// 

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream fd;   
  char c;

  fd.open(argv[1],ios::in);    // open the file for reading
  if(!fd){
    cerr << "Cannot open " << argv[1] << endl;
    exit(1);
  }
  for(;;){
    c = fd.get();
    if(fd.eof())
      return 0;
    cout.put(c);
  }
  fd.close();
}

