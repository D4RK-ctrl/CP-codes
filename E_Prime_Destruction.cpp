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


    // int maxA = 2000000;
    // int limit = floor(sqrt(maxA)) + 1; // sqrt of max constraint of element of array
    // vector<char>isPrime(limit+1,true);
    // isPrime[0] = isPrime[1] = false;
    // for(int i=2;i*i<=limit;i++)
    // {   
    //     if(isPrime[i]==false)continue;
    //     for(int j=i*i;j<=limit;j+=i) // long long or else i*i -> over flow
    //     {
    //         isPrime[j]=false;
    //     }
    // }
    // vector<int>primes;
    // for(int i=2;i<=limit;i++)
    // {
    //     if(isPrime[i])primes.push_back(i);
    // }


    int t;
    t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vi arr(n);
        f(n)cin>>arr[i];

        // spf till N template, N must be less than 1e6
        int N = n;
        vi spf(N+1);

        for(int i=0;i<=n;i++)spf[i] = i;
        for(int i=2;i*i<=N;i++)
        {
            if(spf[i]==i)
            {
                for(int j=i*i;j<=N;j+=i)
                {
                    if(spf[j]==j)
                    spf[j]=i;
                }
            }
        }

        // int ans = 0;
        // for(int i=0;i<n;i++)
        // {   
        //     int cnt = 1;
        //     while(arr[i]>k)
        //     {   
        //         int tmp = spf[arr[i]];
        //         ans+=cnt;
        //         cnt*= arr[i]/tmp;
        //         arr[i]=spf[arr[i]];
        //     }
        // }
        // cout<<ans<<endl;


        int ans = 0;
        vi cnt(n+1);
        cnt[0]=0;
        cnt[1]=0;
        for(int i=1;i<=k;i++)
        {
            cnt[i]=0;
        }
        for(int i=k+1;i<=n;i++)
        {
            cnt[i]=INT_MAX;
            int x = i;
            while(x>1)
            {
                int ft = spf[x];

                // cnt[i] = min(1+ft*cnt[x/ft],cnt[i]);
                cnt[i] = min(1+ft*cnt[i/ft],cnt[i]);

                while(x%ft==0)
                {
                    x=x/ft;
                }
                if(x==1)break;
            }
        }
        f(n)
        {
            ans+=cnt[arr[i]];
        }
        cout<<ans<<endl;
    }
}