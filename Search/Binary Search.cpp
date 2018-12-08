// Ok Funtion To Check If Mid Is a Solution Or Not 
bool Ok(int m) {
	// TODO: to be implemented
	
}

// Binary search on the minimum value fulfilling a certain criteria
int binarySearch() {
	int l = 0, r = 1e9;

    while (l < r) {
        int mid = l + (r - l) / 2;

        if (Ok(mid))
            r = mid;
        else
            l = mid + 1;
    }
}
