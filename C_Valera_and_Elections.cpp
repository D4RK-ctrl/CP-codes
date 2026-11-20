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

// root 1
// will iterate till the leaf, if we find broken road in b/w then ans++
// as we will select the candiate belonging to that leaf


// MISTAKE
//         1
//         2
//        3 4
// If road from 1->2 is broken then we can fix it by using 1 node
// But my approach is giving 2(both the leaves of that whole branch).
// FIX
// what if everytime I reach a leaf, I change ok = false and keep ok as universal
// this will help me to reset ok once we again reach the new dfs iteration


// MISTAKE
//         1
//         2
//        3 4
// If roads from 1->2 and 2->4 are broken, my approach will give ans = [3,4]
// it will consider both nodes 3 and 4, but we can just select node 4
// FIX
// will check for every node and its subtree if there is a broken road
// if there is not but its parent has, then will choose the parent ie: the last banda


void fn(int x,vector<bool> &chk,vi &pt, vector<vi>&arr,map<pair<int,int>,int>&wt,vi &ans)
{   
    // if(wt[{min(x,pt[x]),max(x,pt[x])}]==2)
    // {
    //     // cout<<"x "<<x<<" it "<<it<<endl;
    //     ok=true;
    // }

    // cout<<"x "<<x<<endl;

    bool edge = false;
    if(wt[{min(x,pt[x]),max(x,pt[x])}]==1)
    edge = true;
    
    for(auto it:arr[x])
    {   
        if(pt[it]==-1)
        {   
            pt[it]=x;
            fn(it,chk,pt,arr,wt,ans);
            chk[x] = (chk[x] || chk[it]);
        }
    }
    if(edge and chk[x]==false)
    {
        ans.push_back(x);
        chk[x]=true;
    }


    // if(!once and ok)
    // {
    //     ans.push_back(x);
    //     ok=false;
    // }
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
        cin>>n;
        vector<vi> arr(n+1);
        map<pair<int,int>,int>wt;
        for(int i=0;i<n-1;i++)
        {
            int a,b,w;
            cin>>a>>b>>w;
            arr[a].push_back(b);
            arr[b].push_back(a);
            wt[{min(a,b),max(a,b)}]=w-1;
        }
        vi ans;
        vi pt(n+1,-1);
        pt[1]=0;
        bool ok = false;
        vector<bool> chk(n+1);
        fn(1,chk,pt,arr,wt,ans);
        cout<<ans.size()<<endl;
        for(auto it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
}