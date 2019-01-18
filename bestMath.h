/*
 * This header file defines a reliable modular function
 * I was sick of the flawed % and remainder(), so, here
 * you go!
 *
 * If f is == 0 then the function will retuen -1 without
 * printing a waring. use this value to detect improper use
 *
 * Built by Alex Bestoso
 */

signed int bestModu(signed int n, size_t f){
	signed int ret = 0;
	if(f == 0){
		return -1;
	}
	
	if(n == 0){
	/*
	 * returning 0 because that is what the
	 * result would be!
	 */
		return 0;

	}else if(n >= 1){
	/* calculate the working % relative to
	 * positive numbers!
	 */	
		while(n >= 1){
			ret++;				/* increment ret*/
			
			if(ret >= f || ret <= -1)	/* is ret outside of the finite field? -1 is bc hackers*/
				ret = 0;		/* yes, set to 0 bc if ret >= f we land in a nonexisting "pie slice"*/
							/* no, rets value is correct */
			n--;				/* decrement the amount of steps remaining */
		}	
		return ret;				
	}else{
	/* calculate the working % relative to
         * negative numbers!
         */
		while(n <= -1){
			ret--;				/* decrement ret */
			if(ret <= -1 || ret >= f)	/* is ret negative? f is bc hackers */
				ret = f-1;		/* yes, set ret to f-1 bc to the left of 0 is f-1, not -1(positve amt of "pie slices")*/
							/* no, rets value is correct */
			n++;				/* increment total amunt of required steps bc negative n. */
		}
		return ret;
	}

	/* incase of undefined errror */
	ret = 1;
	return ret;
}
