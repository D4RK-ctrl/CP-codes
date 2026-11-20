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
    int ans = 1;
    while(t--){
        int n,k;
        cin>>n>>k;
        vi a(n+1);
        F(1,n+1)cin>>a[i];
        vi pt(n+1);
        map<int,int>mp; // start length
        for(int i=1;i<=n;i++)
        {   
            if(pt[i]) // visited check
            {
                continue;
            }
            bool ok = true;
            int cnt = 1;
            if(i==1){ // one wala edge case
                cnt--;
            }
            pt[i]=i; // khud ko khud ka pt bana diya
            int x = i;
            while(true)
            {
                x=a[x]; // DFS
                if(x==1)
                {
                    ans+=cnt;
                    ok=false;
                    break;
                }
                if(pt[x]==0) // agar banda naya hai, usko apna bana lenge
                {
                    cnt++;
                    pt[x]=i;
                }
                else if(pt[x]==i) // agar apna banda wapas mil gaya, toh khatam
                {   
                    break;
                }
                else
                {   
                    ok=false;
                    int X=x;
                    while(X!=pt[X])
                    {
                        X=pt[X];
                    }
                    pt[i]=X;
                    mp[X]+=cnt;
                    break;
                }
            }
            if(ok)
            mp[i]=cnt;
        }
        vi pade;
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
            pade.push_back(it.second);
        }
        sort(pade.rbegin(),pade.rend());
        for(int i=0;i<min(k,(int)pade.size());i++)
        {
            ans+=pade[i];
        }
        cout<<ans<<endl;
    }
}