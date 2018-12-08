// Function To Solve a Quadratic Equation 
// If The Returned Roots equal To INT_MIN So The Roots are complex 
vector<double> SolveQuadratic(double a , double b , double c){
    vector<double> Roots(2) ; 
    if(b*b-4*a*c<0){
        Roots[0]=INT_MIN , Roots[1]=INT_MIN ; 
    }
    else{
        Roots[0] = (-b+sqrt(b*b-4*a*c))/(2*a) ; 
        Roots[1] = (-b-sqrt(b*b-4*a*c))/(2*a) ; 
    }
    return Roots ; 
}

// If The Roots Are Complex 
int d = b*b - 4*a*c; 
double sqrt_val = sqrt(abs(d));

// Root1 => -(double)b/(2*a) << " + i" << sqrt_val ; 
// Root2 => -(double)b/(2*a) << " - i" << sqrt_val ; 
