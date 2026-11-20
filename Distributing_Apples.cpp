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
int fact (int n,int m=1e9+7){
    if(n<0){cout<<"";return 0;}
    if(n==0){cout<<"";return 1;}
    int res=1;
    for(int i=2;i<=n;i++) res=(res*i)%m;
    return res;
}
int inv(int n, int m){
    if(n==0)cout<<"";
    return powmod(n,m-2,m);
}
int nCr(int n, int r, int m=1000000007){
    if(r<0 || r>n){cout<<"";return 0;}
    int numerator = fact(n, m);
    int denominator = (inv(fact(r, m), m) * inv(fact(n-r, m), m)) % m;
    return (numerator * denominator) % m;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a = fact(n+m-1);
        int b = (fact(m) * fact(n-1))%mod;
        int ans = (a * powmod(b,mod-2))%mod;
        cout<<ans<<endl;
    }
}