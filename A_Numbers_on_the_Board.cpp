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
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(a==0 and b==0)
        {
            cout<<0<<endl;
        }
        else if(a==0 or b==0)
        {
            cout<<max(abs(a),abs(b))-1<<endl;
        }
        else if(a>0 and b>0)
        {
            cout<<b-a<<endl;
        }
        else if(a<0 and b>0)
        {
            cout<<max(0ll,max(abs(a),abs(b)) - min(abs(a),abs(b)) - 1)<<endl;
        }
        else if(a<0 and b<0)
        {
            a=a*(-1);
            b=b*(-1);
            cout<<a-b<<endl;
        }
    }
}