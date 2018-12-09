// If We Have Polygon of ( N vertices = N Sides)
// So The Total Number of The Lines in The Polygon ( Dimeters , Sides ) = nC2
// Number of shape diameters = Total Number of The Lines - Number of Sides = nC2 - n 

int nC2(int n){
	return n*(n-1)/2 ;
} 

int nCr(int n, int r) {
 if (n < r)
 return 0;
 if (r == 0)
 return 1;
 return n * nCr(n - 1, r - 1) / r;
}

int n ; 
cin >> n ; 
int TotNumOfShapeLines = nC2(n) ;
int NumberOfShapeDiameters = TotNumOfShapeLine - n ; 

// Number Of Triangles Can Be Formed by Connecting 3 vertices of The Polygon = nC3 
int NumOfTriangles = nCr(n,3) ;   
