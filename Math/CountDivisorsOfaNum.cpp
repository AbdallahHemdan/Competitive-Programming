// Returns The Number Of divisors of a given number.
// O(sqrt(n))
ll CountDivisors(ll n){
    ll cnt = 0 ; 
    ll i ; 
    for (i = 1; i * i <= n; ++i)
        if (n % i == 0)
          cnt+=2 ; 
    if(i*i==n)
       cnt++;
    return cnt;
}
