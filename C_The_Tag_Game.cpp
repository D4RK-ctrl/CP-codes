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
int X;
int D=-1;
int XX = X;
void dfs0(int x,int p, vector<vi>&arr, int d)
{   
    d++;
    if(x==X)
    {   
        D=(d-1)/2;
        if(D==0)
        {
            XX=x;
        }
        // cout<<"D "<<D<<endl;
        return;
    }
    for(auto it:arr[x])
    {
        if(it==p)continue;
        dfs0(it,x,arr,d);
    }
    if(D!=-1)
    {
        D--;
        if(D==0)
        {
            XX=x;
            return;
        }
    }
}
void dfs(int x, int p, vector<vi>&arr,int cur1,int curX, int &mx,int &ans)
{   
    cur1++;
    if((curX!=-1) or (curX==-1 and x==XX))
    {
        curX++;
        if(curX>mx)
        {
            mx=curX;
            ans=cur1*2;
        }
    }
    for(auto it:arr[x])
    {
        if(it==p)continue;
        dfs(it,x,arr,cur1,curX,mx,ans);
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n>>X;
        vector<vi>arr(n+1);
        for(int i=0;i<n-1;i++)
        {
            int a,b;
            cin>>a>>b;
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        int mx = -1;
        int ans = 0;
        int d = -1;
        dfs0(1,0,arr,d);
        // cout<<"XX "<<XX<<endl;
        dfs(1,0,arr,-1,-1,mx,ans);
        cout<<ans<<endl;
    }
}