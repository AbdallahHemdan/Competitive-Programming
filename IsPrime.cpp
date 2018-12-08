// Check if The Number Is Prime Or Not
bool IsPrime(int n){
    if(n==2) return true ; 
    if(n<2 || n%2==0) return false ; 
    for(int i=3 ; i*i<=n;i+=2)
        if(n%i==0)
            return false ; 
    return true ; 
}
