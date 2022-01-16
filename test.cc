#include <iostream>
using namespace std;

int main()
{
  pid_t pid;
  pid = fork();

  if(pid < 0)
  {
    cout << "Error message\n";
    return 0;
  }

  else if (pid == 0)
    execlp("bin/ls", "ls", NULL);

  else
  {
    wait(NULL);
    printf("Child done\n");
  }
  return 1;
}
