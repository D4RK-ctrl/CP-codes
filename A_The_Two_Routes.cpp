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
// if there is a railroad from 1 to n, then will check for roads
// else there is a road from 1 to n, so will check for rails
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
        vector<set<int>>arr(n+1);
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].insert(b);
            arr[b].insert(a);
        }
        if(arr[1].count(n)==1)
        {   
            // cout<<"toggle"<<endl;
            vector<set<int>>array(n+1);
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i==j)continue;
                    if(arr[i].count(j)==0)
                    {
                        array[i].insert(j);
                    }
                }
            }
            arr=array;
        }
        deque<int>q;
        q.push_back(1);
        vi vis(n+1,-1);
        vis[1]=0;
        while(q.size()>0)
        {
            int x = q.front();
            // cout<<"x "<<x<<endl;
            for(auto it:arr[x])
            {   
                // cout<<"x it "<<it<<endl;
                if(vis[it]==-1)
                {
                    vis[it]=vis[x]+1;
                    q.push_back(it);
                }
            }
            q.pop_front();
        }
        if(vis[n]==-1)
        {
            cout<<-1<<endl;
        }
        else
        {
            cout<<vis[n]<<endl;
        }
    }
}