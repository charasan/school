#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int num[2];
    int i, x, tmp;
    ifstream fd;

    for(i=0;i<2;i++)
      num[i] = 0;

    fd.open(argv[1]);

    if(!fd)
    {
      cerr << "Error: Cannot find file " << argv[1] << endl;
      exit(1);
    }
    
    for(;;)
    {
      fd >> x;
      if(fd.eof())
	break;
      if(x > num[0])
      {
	tmp = num[0];
	num[0] = x;
	num[1] = tmp;
      }
// If the first number read is largest, num[1] would be 0 throughout
//  this protects from that.
      if((x > num[1]) && (x < num[0]))
	num[1] = x;
    }

    fd.close();
    
    cout << num[1] << endl;
}
