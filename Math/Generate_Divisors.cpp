// Returns a list of divisors of the given number.
// O(sqrt(n))
vector<int> getDivisors(int n){
    vector<int> divs;
    int i ; 
    for (i = 1; i * i <= n; ++i)
        if (n % i == 0) {
            divs.push_back(i);
            divs.push_back(n / i);
        }
    if(i*i==n)
        divs.push_back(i) ;
    sort(divs.begin(), divs.end());
    return divs;
}
