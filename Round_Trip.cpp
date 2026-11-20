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
        vector<int>pt(n+1,0);
        vector<int>vis(n+1,0);
        int a = -1;
        int b = -1;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            vis[i]=1;
            deque<int>q;
            q.push_back(i);
            pt[i]=i;
            while(q.size()>0)
            {
                int x = q.front();
                // cout<<"x "<<x<<endl;
                q.pop_front();
                for(auto it:arr[x])
                {
                    if(it==pt[x])continue;
                    if(vis[it]==1)
                    {
                        a = x;
                        b = it;
                        break;
                    }
                    else
                    {
                        vis[it]=1;
                        pt[it]=x;
                        q.push_back(it);
                    }
                }
            }
            if(a!=-1)break;
        }
        if(a==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            vector<int>A;
            A.push_back(a);
            int x = a;
            unordered_set<int>st;
            while(pt[x]!=x)
            {
                x=pt[x];
                A.push_back(x);
                st.insert(x);
            }
            vector<int>ans;
            ans.push_back(b);
            x=b;
            int bp = -1;
            while(pt[x]!=x)
            {
                x=pt[x];
                if(st.count(x)){bp=x;break;}
            ans.push_back(x);
        }
        bool add = false;
        for(int i=A.size()-1;i>=0;i--)
        {
            if(A[i]==bp)
            {
                add=true;
            }
            if(add)
            {
                ans.push_back(A[i]);
            }
        }
        // cout<<"check"<<endl;
        ans.push_back(b);
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
            cout<<endl;
        }
    }
}