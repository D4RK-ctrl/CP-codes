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
        int n,m;
        cin>>n>>m;
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x2-x1<=0)
        {
            cout<<"Draw"<<endl;
            continue;
        }
        if((abs(x1-x2)&1)==1)
        {   
            //Alice
            int cnt = (x2-x1)/2;
            int RA = min(y1 + cnt + 1,m);
            int LA = max(y1 - cnt - 1,1ll);
            int RB = min(y2+cnt,m);
            int LB = max(y2-cnt,1ll);
            if(LA<=LB and RA>=RB)
            {
                cout<<"Alice"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
        else
        {   
            // Bob
            // cout<<y2<<endl;
            int cnt = (x2-x1)/2;
            int RA = min(y1 + cnt ,m);
            int LA = max(y1 - cnt ,1ll);
            int RB = min(y2+cnt,m);
            int LB = max(y2-cnt,1ll);
            // cout<<LA<<" "<<RA<<endl;
            // cout<<LB<<" "<<RB   <<endl;
            if(LA>=LB and RA<=RB)
            {
                cout<<"Bob"<<endl;
            }
            else
            {
                cout<<"Draw"<<endl;
            }
        }
    }
}