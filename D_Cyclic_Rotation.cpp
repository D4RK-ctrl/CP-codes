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
        vi array(n);
        f(n)cin>>array[i];
        f(n)cin>>a[i];

        bool ans = true;

        map<int,int>mp;
        int p1 = 0;
        int p2 = 0;
        int prev = -1;
        while(true)
        {   
            if(p2<n and a[p1]==array[p2])
            {
                // cout<<"p1 "<<p1<<endl;
                prev=array[p2];
                p1++;
                p2++;
            }
            else if(a[p1]==prev and mp[prev]>0)
            {
                p1++;
                mp[prev]--;
            }
            else
            {   
                if(p2==n)
                {
                    ans=false;
                    break;
                }
                while(a[p1]!=array[p2])
                {   
                    mp[array[p2]]++;
                    p2++;
                    if(p2==n)
                    {
                        ans=false;
                        break;
                    }
                }
            }
            if(p1==n)
            {
                break;
            }
            if(!ans)
            {
                break;
            }
        }
        if(!ans)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}