/*Author : Abdallah Hemdan */
/**************************/
/*Dear online judge:
* I've read the problem, and tried to solve it.
* Even if you don't accept my solution, you should respect my effort.
* I hope my code compiles and gets accepted.
*  ___   __
* |\  \|\  \
* \ \  \_\  \
*  \ \   ___ \emdan
*   \ \  \\ \ \
*    \ \__\\ \_\
*     \|__| \|__|
*/
#include <iostream>
#include <cmath>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <iomanip>
#include <assert.h>
#include <vector>
#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <numeric>
#include <array>
#include <tuple>
#include <stdexcept>
#include <utility>
#include <functional>
#include <locale>
#define       mp                            make_pair
#define       pb                            push_back
#define      endl                             '\n'
#define       f                              first
#define       s                              second
#define       sz                              size()
#define       len                            length()
#define       IO            ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define     all(v)                  ((v).begin()), ((v).end())
#define    rall(v)                  ((v).rbegin()), ((v).rend())
#define   lop(i,init,n)              for(int i=init;i<n;++i)
#define     Even(Num)                       Num % 2 == 0
#define   mms(Arr,Value)           memset(Arr,Value,sizeof(Arr))
#define   SetPre(Ans,num)        fixed << setprecision(num) << (Ans)
#define     vi                           vector<int>
#define     vll                          vector<ll>
#define     si                            set<int>
#define     sll                           set<ll>
typedef   long long int                     ll;
typedef   long double                       ld;


const double EPS = 1e-9;
const int MOD = 1e9 + 7;

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);

//ll GCD(ll a, ll b) {
//  if (b == 0) return a;
//  return GCD(b, a%b);
//}

//ll LCM(ll a, ll b) {
//  return a / (GCD(a, b))* b;
//}

const int dx[] = { 1,-1,0,0,0,0 };
const int dy[] = { 0,0,1,-1,0,0 };
const int dz[] = { 0,0,0,0,1,-1 };

using namespace std;

int parent[100001]; 
int Sizei[100001];

//function to find the connected component that the ith node belongs to
int findParent(int i, int parent[]){
    if (parent[parent[i]] != parent[i])
        parent[i] = findParent(parent[i], parent);
    return parent[i];
}

//to merge the connected components of nodes a and b
void unionNodes(int a, int b, int parent[], int size[]){
    int parent_a = findParent(a, parent), parent_b = findParent(b, parent);
    if (parent_a == parent_b)
        return;

    //the larger connected component eats up the smaller one
    if (size[parent_a] >= size[parent_b]){
        size[parent_a] += size[parent_b];
        parent[parent_b] = parent_a;
    }
    else{
        size[parent_b] += size[parent_a];
        parent[parent_a] = parent_b;
    }
    return;
}
int main()
{
    int t; 
    cin >> t; 
    while (t--) {
        int N, M, a, b, Q;
        cin >> N >> M >> Q;
        lop(i,1,N+1){
            parent[i] = i;
            Sizei[i] = 1;
        }
        lop(i, 0, M) {
            cin >> a >> b;
            unionNodes(a, b, parent, Sizei);
        }

        string Res = "";
        lop(i, 0, Q) {
            cin >> a >> b;

            // Means that a, b are reachable to each others
            if (findParent(a, parent) == findParent(b,parent)) {
                Res += '1';
            }
            else { // Means that a, b are not reachable to each others
                Res += '0';
            }
        }
        cout << Res << endl;
    }
    return 0;
}
