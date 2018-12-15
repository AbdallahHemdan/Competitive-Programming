// Calculate The GCD of The Factorial Of Two Numbers GCD(a!,b!)
// Using The Fact : GCD of The Factorial Of Two Numbers Is The Factorial Of The Minimum Of them ( GCD( min(a , b) )
typedef   long long int               ll ;

ll Fact(ll x) { 
    if (x <= 1) 
        return 1; 
    ll res = 2; 
    for (int i = 3; i <= x; i++) 
        res = (ll)res * i; 
    return res; 
} 
  
ll GcdOfFactorial(int m, int n) 
{ 
    return Fact(min(m, n)); 
} 
