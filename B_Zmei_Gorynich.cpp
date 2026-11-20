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
        int n,x;
        cin>>n>>x;
        vpii array(n);
        int mxD = -1;
        int mxB = -1;
        for(int i=0;i<n;i++)
        {
            cin>>array[i].first;
            cin>>array[i].second;
            mxD = max(mxD,array[i].first-array[i].second);
            mxB=max(mxB,array[i].first);
        }
        // cout<<"mxD "<<mxD<<endl;
        // cout<<"mxB "<<mxB<<endl;
        if(mxD<=0 and mxB<x)
        {
            cout<<-1<<endl;
        }
        else
        {
            if(mxB>=x)
            {
                cout<<1<<endl;
                continue;
            }
            // cout<< ((x - mxB + mxD - 1)/mxD + 1)<<endl;
            x = x - mxB;
            cout<< (x + mxD - 1)/mxD + 1<<endl;
        }
    }
}