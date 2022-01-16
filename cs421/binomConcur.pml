int m = 12;
int k = 5;
int y1 = m;
int y2 = 1;
int b = 1;

proctype binom1()
{
  do
  :: y1 > m - k -> b = b * y1; y1 = y1 - 1
  :: y1 <= m - k -> assert (_nr_pr == 3); break
  od
}

proctype binom2()
{
  do
  :: y2 <= k && y1 + y2 <= m -> b = b / y2; y2 = y2 + 1
  :: y2 > k -> break
  od;
}

init
{
  atomic{run binom1(); run binom2()}
  _nr_pr == 1 -> printf ("Number of active processes is %d; %d choose %d = %d\n", _nr_pr, m, k, b)
}
