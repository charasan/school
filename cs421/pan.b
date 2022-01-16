	switch (t->back) {
	default: Uerror("bad return move");
	case  0: goto R999; /* nothing to undo */

		 /* PROC :never: */
;
		;
		
	case 4: /* STATE 8 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC Q */
;
		;
		
	case 6: /* STATE 2 */
		;
		now.wantQ = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 9: /* STATE 5 */
		;
		now.wantQ = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 12: /* STATE 18 */
		;
		now.turn = trpt->bup.oval;
		;
		goto R999;

	case 13: /* STATE 23 */
		;
		p_restor(II);
		;
		;
		goto R999;

		 /* PROC P */
;
		;
		
	case 15: /* STATE 2 */
		;
		now.wantP = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 18: /* STATE 5 */
		;
		now.wantP = trpt->bup.oval;
		;
		goto R999;
;
		;
		;
		;
		
	case 21: /* STATE 18 */
		;
		now.turn = trpt->bup.oval;
		;
		goto R999;

	case 22: /* STATE 23 */
		;
		p_restor(II);
		;
		;
		goto R999;
	}

