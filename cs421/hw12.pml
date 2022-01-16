active proctype hoare()
{
  int z = 0;
  byte y = 4;
  byte x = 7;
  int n = y;

  do
  :: n > 0 -> z = z + x; n = n - 1
  :: n <= 0 -> break;
  od;

  printf("%d X %d = %d\n", x, y, z);
  printf("\n%d = n\n", n);
}
