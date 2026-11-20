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
    // cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vi> arr(n+1);
        vi ct(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>ct[i];
        }
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        vi cc(n+1,-1);
        cc[1]=ct[1];
        deque<int>q;
        q.push_back(1);
        int ans = 0;
        while(q.size()>0)
        {
            int x = q.front();
            // cout<<"check"<<endl;
            if(cc[x]<=k){
                // cout<<x<<endl;
                if(arr[x].size()==1 and x!=1)
                {
                    ans++;
                }
                for(auto it:arr[x])
                {
                    if(cc[it]==-1)
                    {
                        q.push_back(it);
                        // cc[it]=cc[x]+ct[it];
                        if(cc[x] and ct[it])
                        {
                            cc[it]=cc[x]+1;
                        }
                        else if(ct[it])
                        {
                            cc[it]=1;
                        }
                        else
                        {
                            cc[it]=0;
                        }
                    }
                }
            }
            q.pop_front();
        }
        cout<<ans<<endl;
    }
}