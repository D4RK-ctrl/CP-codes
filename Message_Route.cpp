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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>A(n+1);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            A[a].push_back(b);
            A[b].push_back(a);
        }
        vector<int>pt(n+1,-1);
        vector<int>vis(n+1,0);
        deque<int>q;
        q.push_back(1);
        vis[1]=1;
        while(q.size()>0)
        {
            int x = q.front();
            q.pop_front();
            if(x==n)break;
            for(auto it:A[x])
            {
                if(vis[it])continue;
                q.push_back(it);
                vis[it]=1;
                pt[it]=x;
            }
        }
        if(pt[n]==-1)
        {
            cout<<"IMPOSSIBLE";
            continue;
        }
        else
        {
            vi ans;
            int x = n;
            ans.push_back(n);
            while(x!=1)
            {
                x=pt[x];
                ans.push_back(x);
            }
            cout<<ans.size()<<endl;
            reverse(ans.begin(),ans.end());
            for(auto it:ans)
            {
                cout<<it<<" ";
            }
            cout<<endl;
        }
    }
}