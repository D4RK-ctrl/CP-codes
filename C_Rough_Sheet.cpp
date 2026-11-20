#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl "\n"
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
        int n;
        cin>>n;
        vi a(n);
        f(n)cin>>a[i];
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        // cout<<(-2)%(12)<<endl;
        if(a.back()==0)
        {
            int p = n-1;
            while(p>=0 and a[p]==0)
            {
                p--;
            }
            if(p==-1)
            {
                cout<<0<<endl;
                continue;
            }
            else
            {
                cout<<abs(a[p])<<endl;
                continue;
            }
        }
        int x = a.back();
        while(a.size()>1 and a.back()%x==0)
        {
            a.pop_back();
        }
        // cout<<a.back()<<" "<<x<<endl;
        int ff = a.back();
        int ss = x;
        if(ss<0)
        {
            ss=ss*(-1);
            ff=ff*(-1);
        }
        int k = (((ff%ss)+ss)%ss);
        cout<<min(k,ss-(k))<<endl;
    }
}