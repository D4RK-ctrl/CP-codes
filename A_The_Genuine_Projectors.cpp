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
    int maxA = 1000;
    int limit = floor(sqrt(maxA)) + 1; // sqrt of max constraint of element of array
    limit = 1000000;
    vector<char>isPrime(limit+1,true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2;i*i<=limit;i++)
    {   
        if(isPrime[i]==false)continue;
        for(int j=i*i;j<=limit;j+=i) // long long or else i*i -> over flow
        {
            isPrime[j]=false;
        }
    }
    vector<int>primes;
    for(int i=2;i<=limit;i++)
    {
        if(isPrime[i])primes.push_back(i);
    }
    while(t--){
        int l,r;
        cin>>l>>r;
        int ans = 0;
        for(int i=l;i<=r;i++)
        {
            int k = (int)sqrt(i);
            if(k*k==i)
            {
                if(isPrime[k])
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}