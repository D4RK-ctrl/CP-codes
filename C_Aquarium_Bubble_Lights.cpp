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
        int n,q;
        cin>>n>>q;
        // cout
        vi arr(n);
        map<int,int>mp;
        int ans = n;
        f(n)
        {
            cin>>arr[i];
            // cout<<arr[i]<<" ";
            mp[arr[i]]++;
        }
        // cout<<endl;
        ans=ans-mp[0];
        int cnt = 0;
        while(q--)
        {
            cnt++;
            int id,k;
            cin>>id>>k;
            // if(id==0)continue;
            id--;
            // cout<<"mp[cnt] "<<cnt<<" "<<mp[cnt]<<endl;
            ans=ans-mp[cnt];
            // cout<<ans<<" ";
            if(id>=0)
            {   
                // cout<<"k "<<k<<" cnt "<<cnt<<endl;
                if(k+cnt>arr[id])
                {   
                    // cout<<"id "<<id<<" k "<<k<<" ";
                    mp[arr[id]]--;
                    mp[k+cnt]++;
                    if(arr[id]<=cnt and k>0)
                    {
                        ans++;
                    }
                    arr[id]=k+cnt;
                }
            }
            cout<<ans<<endl;
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]-cnt<0)cout<<0<<" ";
            else cout<<arr[i]-cnt<<" ";
        }
        cout<<endl;
    }
}