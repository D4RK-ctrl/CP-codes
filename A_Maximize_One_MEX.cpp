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
        int n,k;
        cin>>n>>k;
        vi arr(n);
        f(n)cin>>arr[i];
        if(k==1)
        {
            cout<<-1<<endl;
            continue;
        }
        int id = n-k;
        int mnid = id+1;
        for(int i=id+1;i<n;i++)
        {
            if(arr[i]<arr[mnid])
            {
                mnid=i;
            }
        }
        int mxid = 0;
        for(int i=0;i<=id;i++)
        {
            if(arr[i]>arr[mxid])
            {
                mxid=i;
            }
        }
        if(arr[mxid]==id)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<< mxid+1 << " " << mnid+1 << endl;
    }
}