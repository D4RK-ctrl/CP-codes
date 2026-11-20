#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pair<int,int>>
#define vpci vector<pair<char,int>>
#define vpic vector<pair<int,char>>
#define f(n) for(int i=0;i<n;i++)
#define F(m,n) for(int i=m;i<n;i++)
#define mod 1000000007
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
      if (b & 1) res *= a;
      a *= a;
      b >>= 1;
  }
  return res;
}
int powmod(int x, int y, int m = mod) {
    int res = 1;
    x = x % m;
    while (y > 0) {
        if (y & 1) res = (1LL * res * x) % m;
        y = y >> 1;
        x = (1LL * x * x) % m;
    }
    return res;
}
long long gcd_ll(long long a, long long b) {
    // always work with non-negative numbers
    a = llabs(a);
    b = llabs(b);

    // handle 0 separately (gcd(0,0) undefined but we can return 0)
    if (a == 0 or b == 0) return 0;

    // iterative Euclid algorithm
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a; // always ≥ 0
}
vector<pair<int,int>> pfactorization(int n, vector<int>&primes)
{   
    vector<pair<int,int>>pfactors;
    // 0 and 1 will return null vector
    if(n<2)return pfactors;
    for(int i=0;i<primes.size();i++)
    {   
        if(primes[i]*primes[i]>n)break;
        if(n%primes[i]==0)pfactors.push_back({primes[i],0});
        while(n%primes[i]==0)
        {
            pfactors.back().second++;
            n = n/primes[i];
        }
    }
    if(n>1)
    pfactors.push_back({n,1});
    return pfactors;
}
int fact (int n,int m=INT_MAX){
    if(n<0){return 0;}
    if(n==0){return 1;}
    int res=1;
    for(int i=2;i<=n;i++) res=(res*i)%m;
    return res;
}
int inv(int n, int m){
    if(n==0)cout<<"error";
    return powmod(n,m-2,m);
}
int nCr(int n, int r, int m=1000000007){
    if(r<0 || r>n){return 0;}
    int numerator = fact(n, m);
    int denominator = (inv(fact(r, m), m) * inv(fact(n-r, m), m)) % m;
    return (numerator * denominator) % m;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int maxA = 1000000;
    int limit = floor(sqrt(maxA)) + 1; // sqrt of max constraint of element of array
    vector<char>isPrime(limit+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=limit;i++)
    {   
        if(isPrime[i]==false)continue;
        for(int j=i*i;j<=limit;j+=i) // long long or else i*i -> over flow
        {
            isPrime[j]=false;
        }
    }
    vector<int>primes;
    for(int i=2;i<=limit;i++)
    {
        if(isPrime[i])primes.push_back(i);
    }
    int t;
    t=1;
    cin>>t;
    while(t--){
        
    }
}