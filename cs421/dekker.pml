/* 
 * Dekker's algorithm -- correct solution for the critical section problem
 *                    -- can spin verify all three properties?
 */

#define p P@csP
#define q Q@csQ
#define mutex !(p && q)

bool wantP = false;
bool wantQ = false;
byte turn = 1;

active proctype P()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       wantP = true;
       do
       :: wantQ -> if
                   :: turn == 2 -> wantP = false; turn == 1; wantP = true
                   :: else -> skip
                   fi;
       :: else -> break
       od;
 csP:  printf("Critical section pid %d\n", _pid);
       turn = 2;
       wantP = false;
  od
}

active proctype Q()
{
  do
    :: printf("Non-critical section pid %d\n", _pid);
       wantQ = true;
       do
       :: wantP -> if
                   :: turn == 1 -> wantQ = false; turn == 2; wantQ = true
                   :: else -> skip
                   fi;
       :: else -> break
       od;
 csQ:  printf("Critical section pid %d\n", _pid);
       turn = 1;
       wantQ = false;
  od
}
/*
proctype verify()
{
  do
  :: assert(!(P@csP && Q@csQ))
  od
}

init{atomic{ P(); Q(); verify() } }
*/
