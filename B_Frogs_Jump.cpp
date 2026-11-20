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
        string s1,s2;
        cin>>s1>>s2;
        // int cnt1 = 0;
        // int cnt2 = 0;
        // for(int i=0;i<n;i++)
        // {
        //     if(s1[i]=='f' and s2[i]=='o')cnt1++;
        //     if(s1[i]=='o' and s2[i]=='f')cnt2++;
        // }
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='f')ans++;
            if(s2[i]=='f')ans++;
        }
        if(ans%2==0)
        {
            cout<<0<<endl;
        }
        else
        {
            cout<<1<<endl;
        }
    }
}