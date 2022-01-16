active [5] proctype P()
{
  byte a = 0;
  byte b = 0;

  do
  :: a = a + 1
  :: b = b + 1
  :: a > b -> break
  od;

  printf("\nActive processes %d, process id %d : a = %d b = %d\n", _nr_pr, _pid, a, b)
}

