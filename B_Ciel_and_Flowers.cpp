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
// Each and every operation gives 1 output from 3 inputs

int fact (int n,int m=LONG_LONG_MAX){
    if(n<0){cout<<"error";return 0;}
    if(n==0){cout<<"error";return 1;}
    int res=1;
    for(int i=2;i<=n;i++) res=(res*i)%m;
    return res;
}
int inv(int n, int m){
    if(n==0)cout<<"error";
    return powmod(n,m-2,m);
}
int nCr(int n, int r, int m=1000000007){
    if(r<0 || r>n){cout<<"error";return 0;}
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
        int a,b,c;
        cin>>a>>b>>c;
        vi rem(3);
        rem[a%3]++;
        rem[b%3]++;
        rem[c%3]++;
        if(max({rem[0],rem[1],rem[2]})==3)
        {
            cout<<(a+b+c)/3<<endl;
        }
        else if(rem[0]==2 and rem[1]==1)
        {
            cout<<(a+b+c-1)/3<<endl;
        }
        else if(rem[0]==2 and rem[2]==1)
        {
            cout<<(a+b+c-2)/3<<endl;
        }
        else if(rem[1]==1 and rem[2]==2)
        {
            if(min({a,b,c})==1)
            {
                cout<<a/3+b/3+c/3<<endl;
            }
            else
            {
                cout<<(a+b+c-2)/3<<endl;
            }
        }else if(rem[2]==1 and rem[1]==2)
        {
            cout<<(a+b+c-1)/3<<endl;
        }
        else if(max({rem[0],rem[1],rem[2]})==1)
        {
            cout<<(a+b+c-3)/3<<endl;
        }
        else if(rem[0]==1 and rem[1]==2)
        {
            cout<<(a+b+c-1)/3<<endl;
        }
        else if(rem[0]==1 and rem[2]==2)
        {   
            if(min({a,b,c})!=0)
            cout<<(a+b+c-1)/3<<endl;
            else
            {
                cout<<a/3+b/3+c/3<<endl;
            }
        }
        else
        {
            cout<<"error"<<endl;
        }
    }
}