/*
 * Version 6 -- mutual exclusion holds
 *           -- atomic is used to prevent deadlock
 *			    each process waits for the other's variable to become false;
 *              once this happens, it immediately sets its own variable true,
 *              before the other process may execute
 *           -- does not prevent starvation
 */

bool wantP = false;
bool wantQ = false;
byte critical = 0;

active proctype P()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       atomic { !wantQ; wantP = true };
	   critical++;
       printf("Critical section pid %d\n", _pid);
       assert(critical <= 1);
       critical--;
       wantP = false;
  od
}

active proctype Q()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       atomic { !wantP; wantQ= true };
       critical++;
       printf("Critical section pid %d\n", _pid);
       assert(critical <= 1);
       critical--;
       wantQ = false;
  od
}
