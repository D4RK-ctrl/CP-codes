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
        int n,k;
        cin>>n>>k;
        vi a(n+1);
        f(n)cin>>a[i+1];
        int ans = 0;
        deque<pair<int,int>>q; // end day , freq
        int cnt = 0;
        for(int i=1;i<=n;i++)
        {   
            // cout<<"i "<<i<<" qfront "<<q.front().first<<" "<<q.front().second<<" "<<cnt<<endl;
            if(q.size()>0 and q.front().first<i)
            {
                cnt=cnt-q.front().second;
                q.pop_front();
                // cout<<"i "<<i<<endl;
                // cout<<"cnt "<<cnt<<endl;
                // cout<<"rm"<<endl;
                // for(auto it:q)
                // {
                //     cout<<it.first<<" "<<it.second<<endl;
                // }
                // cout<<"cnt "<<cnt<<endl;
                // cout<<"done"<<endl;
            }
            if(cnt>a[i])
            {
                // cout<<"do"<<endl;
                while(q.size()>0 and cnt-q.front().second>a[i])
                {
                    cnt=cnt-q.front().second;
                    // cout<<"cnt "<<endl;
                    q.pop_front();
                }
                if(q.size()>0 and cnt!=a[i])
                {
                    q.front().second=q.front().second-(cnt-a[i]);
                    cnt=a[i];
                }
                // for(auto it:q)
                // {
                //     cout<<it.first<<" "<<it.second<<endl;
                // }
                // cout<<"done"<<endl;
                continue;
            }
            else
            {
                q.push_back({i+k-1,a[i]-cnt});
                // cout<<q.back().first<<" "<<q.back().second<<endl;
                ans+=a[i]-cnt;
                cnt=a[i];
            }
        }
        cout<<ans<<endl;
    }
}