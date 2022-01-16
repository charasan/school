/* VERSION 7 -- atomic is used to prevent deadlock
 *              (each process waits for the other's variable to become false;
 *              once this happens, it sets its own variable true, before the
 *              other process may execute)
 *           -- labels are used to refer to certain control points
 *           -- instead of using ghost variables, an additional process is used
 *              to verify that mutual exclusion holds on all computations
 *           -- starvation is possible; cannot verify this using assertions,
 *              because it is a property of an entire computation.
 */
bool wantP = false;
bool wantQ = false;
//byte critical = 0;

proctype P()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       atomic { !wantQ; wantP = true};
  cs:  printf("Critical section pid %d\n", _pid);
       wantP = false;
  od
}

proctype Q()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       atomic { !wantP; wantQ = true };
  cs:  printf("Critical section pid %d\n", _pid);
       wantQ = false;
  od
}

proctype verify()
{
  do
  :: assert(!(P@cs && Q@cs))
  od
}

init { atomic{ run P(); run Q(); run verify()} }

// If !(P@cs && Q@cs) is false in some state, then mutex does not hold
