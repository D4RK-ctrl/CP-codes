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
#define str to_string
vector<int> arrify(string s){
    vector<int>ans;
    for(int i=0;i<s.size();i++){
        ans.push_back(s[i]-'0');
    }
    return ans;
}
vector<int> arrify(int n){
    return arrify(to_string(n));
}
vector<int> rice(vector<int> n, int to_base, int self_base=10){
    if(to_base==self_base)return n;
    if(n.size()==1 and n[0]==0)return n;
    if(self_base!=10){
        int ans = 0;
        for(int i=0;i<n.size();i++){
            ans=(ans*self_base)+(n[i]);
        }
        n = arrify(ans);
    }
    if(to_base==10){
        return n;
    }
    vector<int>ans;
    int x = 0;
    for(int i=0;i<n.size();i++)
    {
        x=x*10;
        x+=n[i];
    }
    while(x>0){
        ans.push_back(x%to_base);
        x/=to_base;
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> rice(string n,int to_base,int self_base=10){
    return rice(arrify(n),to_base,self_base);
}
vector<int>rice(int n,int to_base, int self_base){
    return rice(arrify(n),to_base,self_base);
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
        vi arr(n);
        f(n)
        {
            cin>>arr[i];
        }
        vector<vector<int>>a(n);
        for(int i=0;i<n;i++)
        {
            a[i]=rice(arr[i],2,10);
            while(a[i].size()<33)
            {
                a[i].push_back(0);
            }
            // for(auto it:a[i])
            // {
                // cout<<it<<" ";
            // }
            // cout<<endl;
        }
        vector<vector<int>>B(33,vector<int>(n+1));
        for(int k=0;k<=32;k++)
        {   
            for(int i=1;i<=n;i++)
            {
                B[k][i]=B[k][i-1];
                if(a[i-1].size()<=k)
                {
                    continue;
                }
                if(a[i-1][k]==0)
                {
                    B[k][i]++;
                }
            }
        }
        for(int k=0;k<5;k++)
        {
            for(int i=0;i<=n;i++)
            {
                // cout<<B[k][i]<<" ";
            }
            // cout<<endl;
        }
        while(q--)
        {
            int l,r;
            cin>>l>>r;
            int ans = 0;
            for(int k=0;k<33;k++)
            {
                if(B[k][l-1]==B[k][r])
                {
                    ans+=power(2,k);
                }
            }
            cout<<ans<<endl;
        }
    }
}