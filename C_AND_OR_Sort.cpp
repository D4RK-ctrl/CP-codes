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
        int n;
        cin>>n;
        string s;
        cin>>s;
        vi one(n+1);
        vi zero(n);
        if(s[0]=='1')
        {
            one[1]=1;
        }
        if(s[n-1]=='0')
        {
            zero[n-1]=1;
        }        
        for(int i=1;i<=n;i++)
        {
            one[i]=one[i-1];
            if(s[i]=='1')
            {
                one[i]++;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            zero[i]=zero[i+1];
            if(s[i]=='0')
            {
                zero[i]++;
            }
        }
        if(s[0]=='1')
        {
            cout<<zero[0]<<endl;
            continue;
        }



        // f(n+1)
        // {
        //     cout<<one[i]<<" ";
        // }
        // cout<<endl;
        zero.push_back(0);
        // f(n+1)
        // {
        //     cout<<zero[i]<<" ";
        // }
        // cout<<endl;
        int ans = n;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,one[i]+zero[i+1]);
        }
        cout<<ans<<endl;
    }
}