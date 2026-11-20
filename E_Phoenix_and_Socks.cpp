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
        int l;
        int r;
        cin>>l>>r;
        vector<pair<int,int>>a(n+1);
        for(int i=0;i<l;i++)
        {   
            int tmp;
            cin>>tmp;
            a[tmp].first++;
        }
        for(int i=l;i<n;i++)
        {   
            int tmp;
            cin>>tmp;
            a[tmp].second++;
        }

        // remove pairs
        int L = 0;
        int R = 0;
        for(int i=0;i<n;i++)
        {
            int mn = min(a[i].first,a[i].second);
            a[i].first-=mn;
            a[i].second-=mn;
            L+=a[i].first;
            R+=a[i].second;
            // cout<<a[i].first<<" "<<a[i].second<<endl;
        }

        // cnt1 and cnt2
        int cnt1 = 0;
        int cnt2 = 0;
        
        
        // changing colours
        int ans = 0;
        if(R>L)
        {
            for(int i=0;i<=n;i++)
            {
                swap(a[i].first,a[i].second);
            }
            swap(L,R);
        }
        if(L>=R){
            for(int i=0;i<=n;i++)
            {
                cnt2+=a[i].first/2;
                cnt1+=a[i].first%2;
                // cout<<a[i].first<<" ";
            }
            // cout<<endl;
            // cout<<cnt1<<" "<<cnt2<<endl;
            for(int i=0;i<=n;i++)
            {
                if(a[i].second%2==1 and cnt1>0)
                {
                    cnt1--;
                    ans++;
                }
                else if(a[i].second%2==1)
                {
                    cnt2--;
                    cnt1++;
                    ans++;
                }
                if(a[i].second%2==0)
                {
                    int x =  a[i].second;
                    if(x>=cnt1)
                    {   
                        ans+=cnt1;
                        x=x-cnt1;
                        cnt1=0;
                        if(x%2==1)
                        {
                            cnt2--;
                            cnt1++;
                            ans++;
                            x--;

                            ans+=x;
                            cnt2 = cnt2 - x/2;
                            x=0;
                        }
                        else
                        {
                            ans+=x;
                            cnt2 = cnt2 - x/2;
                            x=0;
                        }
                    }
                    else
                    {
                        ans+=x;
                        cnt1=cnt1-x;
                        x=0;
                    }
                }
            }
        }
        ans+=cnt2;
        ans+=cnt1;
        cout<<ans<<endl;
    }
}