// ACM ICPC Training
// Math 
--------------------------------------------------------------
1- IsPrime
	
	bool IsPrime(ll Num){
		if(Num==2)
			return true ; 
		if(Num<2 || Num%2==0)
			return false ; 
		for(ll i=3 ; i*i<=Num ; i+=2){
			if(Num%i==0)
				return false ; 
		}
		return true ;
	}
--------------------------------------------------------------
2- gcd, lcm 

//Euclidean Algorithm
int gcd(int a, int b){
	if(b==0)
		return a ; 
	return gcd(b,a%b) ;
}

int lcm(int a, int b){
	return a/gcd(a, b)*b ;	
}
---------------------------------------------------------------
3- Count Divisors of a Number
ll CountDivisors (ll n){
	ll Cnt = 0 , i;
	for(i=1 ; i*i<=n ; i++){
		if(n%i==0)
			Cnt+=2 ;  
	}
	if(i*i==n)
		Cnt++ ;  
	return Cnt ;
}
----------------------------------------------------------------
4- Generate Divisors
vector<int> GetDivisors(ll n){
	vector<int> Divs ; 
	ll i ;
	for(i=1 ; i*i<=n ;i++){
		if(n%i==0){
			Divs.push_back(i) ; 
			Divs.push_back(n/i);
		}	
	}
	if(i*i==n)
		Divs.push_back(i);
	sort(Divs.begin(),Divs.end());
	return Divs ; 
}
----------------------------------------------------------------
5- No.Digits of a Number
	//Digits of a Num = 1+floor(log10(n));
----------------------------------------------------------------
6- Calculate nCr
int nCr(int n, int r) {
	if (n < r)
		return 0;
	if (r == 0)
		return 1;
	return n * nCr(n - 1, r - 1) / r;
}
----------------------------------------------------------------
7- All SubArrays
void PrintSubArrays(vector<int> Arr, int n){
	int Max  = INT_MIN;
	for(int i=0 ; i<n ; i++){
		for(int j=i ; j<n ; j++){
			for(int k=i ; k<=j ; k++){
				cout << Arr[k] << " " ; 
			}
		}
	}
}
----------------------------------------------------------------
8- Choose K Array Element Such That The Difference between 
Max, Min is Minimized 

// Idea : 
// 	1- Sort
// 	2- Calc The Diff (Max of K ele - Min of K ele)
// 	3- Return The Minimum of all the values Obtained From Step 2 

	int n, k ; 
	cin >> n >> k ;
	int arr[n] ; 
	for(int i=0 ;i<n ; i++)
		cin >> Arr[i] ;
	sort(arr, arr+n);
	int Mini = INT_MAX ;
	for(int i=0 ;i<=n-k ; i++){
		Mini = min(Mini,arr[k+i-1]-arr[i]);
	}
	cout << Mini << endl ;
--------------------------------------------------------------------	
9- memset 
memset(Arr, Value, noOfEle*sizeof(Arr[0])) ;
--------------------------------------------------------------------	
10- GCD of Consective Numbers in Range From a ====> b
	Complicated GCD
	if(a==b){
		Ans = a = b ; 
	}
	else
		Ans = 1 ; 

	As The Fact of GCD of 
	(any two Consective Numbers = 1, e.g gcd(2,3)=1 , gcd(5,6)=1)
--------------------------------------------------------------------	
11- Check if The Number Can Be Expressed as a Sum of 2 
Or More Consective Number Or Not

If The Number if a Power of 2 ==> We Can Not 
Else ==> We Can

The Idea Based on 
	1- Sum of Any Two Numbers is Odd As one of Them is 
		Even, Odd

	bool CanOrNot(int n){
		// This Check if The Num is a Power of 2 Or Not
		// If Not a power ==> True 
		// else ==> False
		return ((n&(n-1))&&n);
	}
--------------------------------------------------------------------	
12- Generate_Primes From 1 to n (Using Sieve)
	// Generates all the prime numbers from 1 to the given number n
	// using Sieve of Eratosthenes' algorithm.
	// After calling this function, prime[i] will be equal 1 if i is prime, 0 otherwise.
	// O(n.log(log(n)))
	void Generate_Primes(int n){
		vector<bool> IsPrime(n+1,true);
		IsPrime[0] = IsPrime[1] = false ;

		for(int i=2 ; i*i<=n ; i++){
			if(IsPrime[i]){
				for(int j=2*i ; j<=n ; j+=i)
					IsPrime[j] = false ;
			}
		}
		// After That We Have All The Primes Numbers up to n
		// So We Can Loop in them To Count The Primes Or Just Return Print It
		// Or Make Any Operations On it 
	}

-------------------------------------------------------------------------
13- Gcd Of Factorials Of Two Numbers

// Calculate The GCD of The Factorial Of Two Numbers GCD(a!,b!)
// Using The Fact : GCD of The Factorial Of Two Numbers 
// Is The Factorial Of The Minimum Of them Fact(min(a , b))	
typedef   long long int               ll ;

ll Fact(ll x) { 
    if (x <= 1) 
        return 1; 
    ll res = 2; 
    for (int i = 3; i <= x; i++) 
        res = (ll)res * i; 
    return res; 
} 
  
ll GcdOfFactorial(int m, int n) { 
    return Fact(min(m, n)); 
} 
--------------------------------------------------------------
13- LCM Of Factorials Of Two Numbers

// Calculate The LCM of The Factorial Of Two Numbers LCM(a!,b!)
// Using The Fact : LCM of The Factorial Of Two Numbers 
// Is The Factorial Of The Maximum Of them Fact(max(a , b))	
typedef   long long int               ll ;

ll Fact(ll x) { 
    if (x <= 1) 
        return 1; 
    ll res = 2; 
    for (int i = 3; i <= x; i++) 
        res = (ll)res * i; 
    return res; 
} 
  
ll LCMOfFactorial(int m, int n) { 
    return Fact(max(m, n)); 
} 
--------------------------------------------------------------
14- Number Of Lines And Diameters in Polygon

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
-------------------------------------------------------
15- Transform
transform(s.begin(),s.end(),s.begin(),::tolower);
transform(s.begin(),s.end(),s.begin(),::toupper);
-------------------------------------------------------
16- Change The Case of Char
	s[0] = toupper(s[0]);
-------------------------------------------------------
17- Max element in Array
int maxi = * max_element(Arr, Arr+n);
int mini = * min_element(Arr, Arr+n);
-------------------------------------------------------
18- Lower,Upper bound
// lower_bound ==> Return a Pointer To First Element
// which is >= Target
// upper_bound ==> Return a Pointer To First Element
// which is > Target
int Res = lower_bound(Arr, Arr+n,Target)-Arr ; 
int Res = lower_bound(Vec.begin(),Vec.end(),Target)-Vec.begin() ; 
int Res = upper_bound(Arr, Arr+n,Target)-Arr ; 
int Res = upper_bound(Vec.begin(),Vec.end(),Target)-Vec.begin() ; 

-------------------------------------------------------
* inclusion-exclusion
	// says that in order to count only unique ways of doing a task,
	// we must add the number of ways to do it in one way
	// and the number of ways to do it in another 
	// and then subtract the number of ways to do the task that are common to both
	// sets of ways.
-------------------------------------------------------

19- Count the numbers divisible by ‘M’ in a given range [A:B]

	// It's Obseved That The Number of divisible by M 
	// 	= B/M - A/M 

	// But There is a Fail Case
	// 		if A is divisible by M, ‘b – a’ will exclude the count for A,
	// 		so the count will be less by 1. Thus, in this case we add 1 explicitly.
	// Code:


		// Returns count of numbers in [A B] that 
		// are divisible by	 M.	 
		int countDivisibles(int A, int B, int M){
		    // Add 1 explicitly as A is divisible by M 
			if(A%M ==0)
				return ((B/M) - (A/M) + 1) ;
		
			return ((B/M)-(A/M));
		}
-------------------------------------------------------------------------
20-	How many numbers between 1 and 1000, including both, are divisible by 3 or 4? 

// Numbers Divisible by 3 + Numbers Divisible by 4 - Numbers Divisible by (3 and 4) 
// Sol = 1000/3 + 1000/4 - 1000/(3*4)

int countDivisibles(int N, int a, int b){
	return (N/a)+(N/b)-(N/(a*b));
} 
-------------------------------------------------------------------------
21- Given N numbers and a number M,
find out how many numbers from 1 to M are divisible by any of the N given 
numbers.

// Using inclusion-exclusion principle, we can get the correct number of multiples
// e.g
// How Many numbers in Range [1:100]
// divisible by 2,3,5 Or 7 

// Note : F(Num) = 100/Num

// Ans = F(2)+F(3)+F(5)+F(7)-F(2,3)-F(2,5)-F(2,7)-F(3,5)-F(3,7)-F(5,7)-F(2,3,5,7)

// code :

// Count The Numbers from 1 to M are divisible by 2, 3, 5, 7
int CountDivisibles(int n) {
	int Cnt = 0;
	for (int i2 = 0; i2 < 2; i2++) {
		for (int i3 = 0; i3 < 2; i3++) {
			for (int i5 = 0; i5 < 2; i5++) {
				for (int i7 = 0; i7 < 2; i7++) {
					int d = 1, ElementCnt = 0; 
					
					if (i2) d *= 2, ElementCnt++;
					if (i3) d *= 3, ElementCnt++;
					if (i5) d *= 5, ElementCnt++;
					if (i7) d *= 7, ElementCnt++;
					
					if (ElementCnt == 0)
						continue; 

					int Sign = (ElementCnt % 2 == 1) ? 1 : -1;
					Cnt += Sign * n / d;
				}
			}
		}
	}
	return Cnt;
}
-----------------------------------------------------------------------
22- Cumulative Sum (Prefix Sum)

ll CumulativeSum(const vector<int> &Arr, int n, int q) {
	vector<int> Sums(Arr.begin(),Arr.end());

	for (int i = 1; i < n; i++) {
		Sums[i] += Sums[i - 1];
	}

	return Sums[q];
}
-----------------------------------------------------
23- accumulate()
// is a BuiltIn Function to Get The Sum of Elements in The Array 
// But Still Cumulative Sum is More Effiecnt if There are a Lot of Queries

// In Array 
int arraySum(int a[], int n)  { 
    int initial_sum  = 0;
    // We Can Change The Starting, Ending Points By Changign 
    // a , a+n  
    return accumulate(a, a+n, initial_sum); 
} 

// In Vector
int arraySum(vector<int> &v)  { 
    int initial_sum  = 0; 

    // We Can Change The Starting, Ending Points By Changign 
    // v.begin() , v.end()
    return accumulate(v.begin(), v.end(), initial_sum); 
} 
   
------------------------------------------------------------------
// Math Fact: 
if al⊕al+1⊕…⊕amid=amid+1⊕amid+2⊕…⊕ar 
	then al⊕al+1⊕…⊕ar=0 
(it comes from the fact that for some integers A, B, C if A⊕B=C then A=B⊕C).
------------------------------------------------------------------
B. Energy exchange

bool Ok(double num, vector<int> Arr, int n, int k) {
	double lo = 0, up = 0; 
	
	for (int i = 0; i < n; i++)
		if (Arr[i] < num)
			lo += (num -Arr[i]);
		else
			up += (Arr[i]- num);

	return ((up - up*k / 100.0) >= lo);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> Arr(n);
	
	for (int i = 0; i < n; i++)
		cin >> Arr[i]; 

	double l = 0, r = 1e3; 

	for (int i = 0; i < 100; i++) {
		double mid = (l + r) / 2;
		if (Ok(mid,Arr,n,k))
			l = mid;
		else
			r = mid; 
	}
	cout << fixed << setprecision(9) << l << endl;	
}
------------------------------------------------------------------

// Get the intersection between 2 vectors :

	vector<int> a = { 1,3,5,2,7 };
	vector<int> b = { 7,3,12,5,9};

	// The two vectors must be sorted
	sort(all(a)); 
	sort(all(b));

	int MaxSize = 500007;
	vector<int> Ans(MaxSize);

	auto r = set_intersection(all(a), all(b), Ans.begin());

	int size = r - Ans.begin();
	lop(i,0,size){
		cout << Ans[i] << " ";
	}

------------------------------------------------------------------
bool IsPrime[1000000];
vector<int> Primes;

void SievePrimes() {
	fill(IsPrime, IsPrime + 1000000, true);
	IsPrime[0] = IsPrime[1] = false;

	for (int i = 1; i<500000; i++)
		IsPrime[2 * i] = false;

	Primes.push_back(2);
	for (int i = 3; i<1000000; i += 2) {
		if (IsPrime[i]) {
			if (i<500000)
				Primes.push_back(i);
			for (int j = 2; j*i<1000000; j++)
				IsPrime[i*j] = false;
		}
	}
}
----------------------------------------------------------------------
Find the Area of Triangle using the lengths of the sides
	S = (a+b+c)/2
	Area = sqrt(S*(S-a)*(S-b)*(S-c))
----------------------------------------------------------------------
Find Number in the range (L,R) 
that is s have maximum product of its digits 

Approach : 
	The key idea here is to iterate over the digits of the number R 
starting from the most significant digit Going from left to right. 
i.e. from most sigificant digit to the least significant digit,
replace the current digit with one less than current digit and replace all the digits
after current digit in the number with 9,
since the number has already become smaller than R at the current position
so we can safely put any number in the following digits to maximize the product of digits.
Also, check if the resulting number is greater than L to remain in the range
and update the maximum product.
----------------------------------------------------------------------
Learn from DubSet ^ ^
string a = "WUB"; 
int main() {
	IO;
	string S; 
	cin >> S;
	if (S.len < 3) {
		return cout << S << endl, 0; 
	}
	lop(i, 0, S.len - 2) {
		if (S.substr(i, 3) == a) {
			S.replace(i, 3, " ");
		}
	}
	cout << S << endl;
}
----------------------------------------------------------------------
insert in c++ STL =====> it also works in String 
https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/

insert() is a built-in function in C++ STL which inserts
new elements before the element at the specified position

// Before:
vec = { 10, 20, 30, 40 }

vec.insert(vec.begin(), 3);

// After
vec = { 3, 10, 20, 30, 40 }
----------------------------------------------------------------------
