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
    while(t--){
        int n;
        cin>>n;
        vi arr(n);
        f(n)cin>>arr[i];
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]].size()==0)
            {
                mp[arr[i]].push_back(-1);
            }
            mp[arr[i]].push_back(i);
        }
        vector<pair<int,int>>array;
        for(auto &it:mp)
        {
            it.second.push_back(n);
            int k = 0;
            for(int z=1;z<it.second.size();z++)
            {
                k=max(k,it.second[z]-it.second[z-1]);
            }
            array.push_back({k,it.first});
        }
        sort(array.begin(),array.end());
        // for(int i=0;i<array.size();i++)
        // {
        //     cout<<array[i].first<<" "<<array[i].second;
        //     cout<<endl;
        // }
        // cout<<endl;


        array.push_back({n,n});

        int prev = INT_MAX;
        vector<int>ans(n+1);
        int p = 0;
        for(int i=1;i<=n;i++)
        {
            if(array[p].first==(i))
            {
                ans[i]=min(prev,array[p].second);
                prev=ans[i];
                int tmp = p;
                while(array[tmp].first==array[p].first)
                {
                    tmp++;
                }
                p=tmp;
            }
            else
            {
                ans[i]=prev;
            }


            if(ans[i]==INT_MAX)
            {
                cout<<-1<<" ";
            }
            else
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }
}