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
    // cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        // if((s1=="zun" and s2=="yi") or (s1=="zhen" and s2=="yuan"))
        // {
        //     cout<<"No"<<endl;
        // }
        // else
        // {
        //     cout<<"Yes"<<endl;
        // }
        if(s1=="an" and s2=="shun")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="zhi" and s2=="jin")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="da" and s2=="fang")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="shi" and s2=="qian")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="li" and s2=="ping")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="fu" and s2=="quan")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="an" and s2=="long")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="pu" and s2=="ding")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="si" and s2=="nan")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(s1=="zhen" and s2=="feng")
        {
            cout<<"Yes"<<endl;
            continue;
        }
        cout<<"No"<<endl;
    }
}