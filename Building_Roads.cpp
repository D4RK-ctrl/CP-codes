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
int find(int x,vector<int>&pt)
{
    if(x==pt[x])return x;

    return pt[x] = find(pt[x],pt);
}
void un(int a,int b,vector<int>&pt,vector<int>&sz)
{
    int x = find(a,pt);
    int y = find(b,pt);
    if(x==y)return;
    if(sz[y]>=sz[x])
    {
        swap(x,y);
    }
    sz[x]+=sz[y];
    pt[y]=x;
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
        vi pt(n+1);
        vi sz(n+1,1);
        for(int i=1;i<=n;i++)
        {
            pt[i]=i;
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            un(a,b,pt,sz);
        }
        for(int i=2;i<=n;i++)
        {
            if(find(i,pt)!=find(i-1,pt))
            {
                un(i,i-1,pt,sz);
                ans.push_back({i-1,i});
            }
        }
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
    }
}