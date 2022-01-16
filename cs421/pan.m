#define rand	pan_rand
#if defined(HAS_CODE) && defined(VERBOSE)
	cpu_printf("Pr: %d Tr: %d\n", II, t->forw);
#endif
	switch (t->forw) {
	default: Uerror("bad forward move");
	case 0:	/* if without executable clauses */
		continue;
	case 1: /* generic 'goto' or 'skip' */
		IfNotBlocked
		_m = 3; goto P999;
	case 2: /* generic 'else' */
		IfNotBlocked
		if (trpt->o_pm&1) continue;
		_m = 3; goto P999;

		 /* PROC :never: */
	case 3: /* STATE 1 - line 62 "pan.___" - [(!(!(((P._p==csP)&&(Q._p==csQ)))))] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
		{	static int reported1 = 0;
			if (verbose && !reported1)
			{	printf("depth %d: Claim reached state %d (line %d)\n",
					depth, frm_st0[t->forw], src_claim[1]);
				reported1 = 1;
				fflush(stdout);
		}	}
#endif
		reached[2][1] = 1;
		if (!( !( !(((((int)((P0 *)Pptr(f_pid(0)))->_p)==17)&&(((int)((P1 *)Pptr(f_pid(1)))->_p)==17))))))
			continue;
		_m = 3; goto P999; /* 0 */
	case 4: /* STATE 8 - line 67 "pan.___" - [-end-] (0:0:0 - 1) */
		
#if defined(VERI) && !defined(NP)
		{	static int reported8 = 0;
			if (verbose && !reported8)
			{	printf("depth %d: Claim reached state %d (line %d)\n",
					depth, frm_st0[t->forw], src_claim[8]);
				reported8 = 1;
				fflush(stdout);
		}	}
#endif
		reached[2][8] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC Q */
	case 5: /* STATE 1 - line 35 "pan.___" - [printf('Non-critical section pid %d\\n',_pid)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][1] = 1;
		Printf("Non-critical section pid %d\n", ((int)((P1 *)this)->_pid));
		_m = 3; goto P999; /* 0 */
	case 6: /* STATE 2 - line 36 "pan.___" - [wantQ = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][2] = 1;
		(trpt+1)->bup.oval = ((int)now.wantQ);
		now.wantQ = 1;
#ifdef VAR_RANGES
		logval("wantQ", ((int)now.wantQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 7: /* STATE 3 - line 38 "pan.___" - [(wantP)] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][3] = 1;
		if (!(((int)now.wantP)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 8: /* STATE 4 - line 39 "pan.___" - [((turn==1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][4] = 1;
		if (!((((int)now.turn)==1)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 9: /* STATE 5 - line 39 "pan.___" - [wantQ = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][5] = 1;
		(trpt+1)->bup.oval = ((int)now.wantQ);
		now.wantQ = 0;
#ifdef VAR_RANGES
		logval("wantQ", ((int)now.wantQ));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 10: /* STATE 6 - line 39 "pan.___" - [((turn==2))] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][6] = 1;
		if (!((((int)now.turn)==2)))
			continue;
		_m = 3; goto P999; /* 0 */
/* STATE 7 - line 39 "pan.___" - [wantQ = 1] (0:0 - 1) same as 6 (0:0 - 1) */
	case 11: /* STATE 17 - line 44 "pan.___" - [printf('Critical section pid %d\\n',_pid)] (0:0:0 - 3) */
		IfNotBlocked
		reached[1][17] = 1;
		Printf("Critical section pid %d\n", ((int)((P1 *)this)->_pid));
		_m = 3; goto P999; /* 0 */
	case 12: /* STATE 18 - line 45 "pan.___" - [turn = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[1][18] = 1;
		(trpt+1)->bup.oval = ((int)now.turn);
		now.turn = 1;
#ifdef VAR_RANGES
		logval("turn", ((int)now.turn));
#endif
		;
		_m = 3; goto P999; /* 0 */
/* STATE 19 - line 46 "pan.___" - [wantQ = 0] (0:0 - 1) same as 9 (0:0 - 1) */
	case 13: /* STATE 23 - line 48 "pan.___" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[1][23] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */

		 /* PROC P */
	case 14: /* STATE 1 - line 17 "pan.___" - [printf('Non-critical section pid %d\\n',_pid)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][1] = 1;
		Printf("Non-critical section pid %d\n", ((int)((P0 *)this)->_pid));
		_m = 3; goto P999; /* 0 */
	case 15: /* STATE 2 - line 18 "pan.___" - [wantP = 1] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][2] = 1;
		(trpt+1)->bup.oval = ((int)now.wantP);
		now.wantP = 1;
#ifdef VAR_RANGES
		logval("wantP", ((int)now.wantP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 16: /* STATE 3 - line 20 "pan.___" - [(wantQ)] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][3] = 1;
		if (!(((int)now.wantQ)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 17: /* STATE 4 - line 21 "pan.___" - [((turn==2))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][4] = 1;
		if (!((((int)now.turn)==2)))
			continue;
		_m = 3; goto P999; /* 0 */
	case 18: /* STATE 5 - line 21 "pan.___" - [wantP = 0] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][5] = 1;
		(trpt+1)->bup.oval = ((int)now.wantP);
		now.wantP = 0;
#ifdef VAR_RANGES
		logval("wantP", ((int)now.wantP));
#endif
		;
		_m = 3; goto P999; /* 0 */
	case 19: /* STATE 6 - line 21 "pan.___" - [((turn==1))] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][6] = 1;
		if (!((((int)now.turn)==1)))
			continue;
		_m = 3; goto P999; /* 0 */
/* STATE 7 - line 21 "pan.___" - [wantP = 1] (0:0 - 1) same as 15 (0:0 - 1) */
	case 20: /* STATE 17 - line 26 "pan.___" - [printf('Critical section pid %d\\n',_pid)] (0:0:0 - 3) */
		IfNotBlocked
		reached[0][17] = 1;
		Printf("Critical section pid %d\n", ((int)((P0 *)this)->_pid));
		_m = 3; goto P999; /* 0 */
	case 21: /* STATE 18 - line 27 "pan.___" - [turn = 2] (0:0:1 - 1) */
		IfNotBlocked
		reached[0][18] = 1;
		(trpt+1)->bup.oval = ((int)now.turn);
		now.turn = 2;
#ifdef VAR_RANGES
		logval("turn", ((int)now.turn));
#endif
		;
		_m = 3; goto P999; /* 0 */
/* STATE 19 - line 28 "pan.___" - [wantP = 0] (0:0 - 1) same as 18 (0:0 - 1) */
	case 22: /* STATE 23 - line 30 "pan.___" - [-end-] (0:0:0 - 1) */
		IfNotBlocked
		reached[0][23] = 1;
		if (!delproc(1, II)) continue;
		_m = 3; goto P999; /* 0 */
	case  _T5:	/* np_ */
		if (!((!(trpt->o_pm&4) && !(trpt->tau&128))))
			continue;
		/* else fall through */
	case  _T2:	/* true */
		_m = 3; goto P999;
#undef rand
	}

