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
        f(n)
        cin>>arr[i];
        // int ans = 0;
        // int sum = 0;
        // int cnt = 0;
        // for(int i=0;i<n;i++)
        // {   
        //     sum+=arr[i];
        //     cnt++;
        //     if(sum%cnt==0)
        //     {
        //         ans=max(ans,cnt);
        //     }
        //     else
        //     {
        //         sum=arr[i];
        //         cnt=1;
        //     }
        // }
        // cout<<ans<<endl;
        set<int>st;
        vi array;
        f(n)st.insert(arr[i]-i);


        for(auto it:st)
        {   
            array.push_back(it);
        }
        sort(array.begin(),array.end());
        int ans = 1;
        int val = 1;
        for(int i=1;i<array.size();i++)
        {
            if(array[i]==array[i-1]+1)
            {
                val++;
            }
            else
            {
                val=1;
            }
            ans=max(ans,val);
        }
        cout<<ans<<endl;
    }
}