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
        vector<vector<int>>arr(n+1);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        vector<int>ans(n+1);
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(ans[i])continue;
            ans[i]=1;
            deque<int>q;
            q.push_back(i);
            while(q.size()>0)
            {
                int x = q.front();
                q.pop_front();
                for(auto it:arr[x])
                {
                    if(ans[it] and ans[it]==ans[x])
                    {
                        flag=false;
                        break;
                    }
                    else if(ans[it])
                    {
                        continue;
                    }
                    else
                    {
                        ans[it]= 1 + (1-(ans[x]-1));
                        q.push_back(it);
                    }
                }
            } 
        }   
        if(!flag)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
    }
}