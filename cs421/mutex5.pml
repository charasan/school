/* VERSION 5 -- syncronization by blocking
 *           -- mutual exclusion holds
 *           -- invalid end states
 *           -- deadlock may happen
 */
bool wantP = false;
bool wantQ = false;
byte critical = 0;

active proctype P()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       wantP = true;
         !wantQ;
       critical++;
       printf("Critical section pid %d\n", _pid);
       assert(critical <= 1);
       critical--;
       wantP = false;
  od
{

active proctype Q()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       wantQ = true;
         !wantP;
       critical++;
       printf("Critical section pid %d\n", _pid);
       assert(critical <= 1);
       wantQ = false;
  od
}
