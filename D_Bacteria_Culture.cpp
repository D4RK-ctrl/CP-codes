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
        int n,m;
        cin>>n>>m;
        vector<int>a(n),p(n),b(n);
        for(int d=0;d<n;d++){
            cin>>a[d];
        }
        int i=0;
        for(int d=0;d<n;d++) cin>>b[d];
        for(int d=0;d<n;d++){
            
            int x=a[d];
            if(a[d]==0 and b[d]!=0)
            {
                i=1;
                break;
            }
            if(b[d]<a[d])
            {
                i=1;
                break;
            }
            if(b[i]>m and a[i]<b[i])
            {
                i=1;
                break;
            }
            int count=0;
            while(x<b[d] && x<m){
                x*=2;
                count++;
            }
            if(x>=m) x=m;
            if(x!=b[d]){
                i=1;
                break;
            }
            p[d]=count;
        }
        // for(int d=0;d<n;d++) cout<<p[d]<<" ";
        // cout<<endl;
        if(i==1){
            cout<<-1<<endl;
            continue;
        }
        int ans=0;
        for(int d=0;d<33;d++){
            int count=0;
            

            for(int r=0;r<n;r++){
                if(p[r]==0){
                    if((2*b[r]>m && m==b[r]) || 2*b[r]==b[r]){
                        
                    }
                    else{
                        if(count!=0){
                            count=0;
                            ans++;
                        }
                    }
                }
                else{
                    count++;
                    p[r]--;
                }
            }
            if(count!=0) ans++;

        }
        cout<<ans<<endl;

    }
}