// Ok Funtion To Check If Mid Is a Solution Or Not 
bool Ok(int m) {
	// TODO: to be implemented
	
}

// Binary search on the minimum value fulfilling a certain criteria
int binarySearch() {
	int l = 0, r = 1e9, ans, ans = -1;

    while (l <= r) {
        mid = l + (r - l) / 2; // take care of overflow 

	// if the function 0 0 0 0 1 1 1 1 1
        if (Ok(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
	    
	// if the funciton 1 1 1 1 0 0 0 0 0
	/* if (OK(mid))
		l = mid + 1, ans = mid;
	   else 
	   	r = mid - 1;
    }
}
