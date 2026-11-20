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



int fact (int n,int m=mod){
    if(n<0){cout<<"";return 0;}
    if(n==0){cout<<"";return 1;}
    int res=1;
    for(int i=2;i<=n;i++) res=(res*i)%m;
    return res;
}
int inv(int n, int m){
    if(n==0)cout<<"";
    return powmod(n,m-2,m);
}
int nCr(int n, int r, int m=mod){
    if(r<0 || r>n){cout<<"";return 0;}
    int numerator = fact(n, m);
    int denominator = (inv(fact(r, m), m) * inv(fact(n-r, m), m)) % m;
    return (numerator * denominator) % m;
}

// number of permutations without any restrictions = n!
// given -> position of k numbers is fixed
// so only positions of the other numbers will change

// Approach -> 1 

// To choose numbers which will be fixed = nCk
// permutations amongst others = (n-k)!

// It is wrong bcos, there will be duplications.
// eg: if n=4 and two numbers are same. Then we will consider, 1,2,3,4 4C2 times


// Approach -> 2
// To count:
// exactly 1 same + exactly 2 same + exactly 3 same + .....
// This will avoid repition, as 1,2,3,4 will be counted only in: Exactly 4 same
// Math :
// For finding exactly i same amongst n -> nCi [choosing i elements] * Dearrangement of (n-i) [ie: They are not at the correct position]


// Mistake
// my D[i] was overflowing, I do not need to calculate till D[n] as D[4] is max, bcos at most 4 elements will be not correctly placed


// Mistake
// I am using mod = 1e9+7 in all the functions, but answer can go beyond that

// Mistake
// I thought of changing 1e9+7 to 1e18+3 thinking now it should give correct answer
// as answer wont go above that
// But for powmod to be in limits, I want mod to be less or else with mod = 1e18+3, powmod will overflow long long
// So for my answer to work I want: mod to be prime, mod>answer limit, not more that sqrt(LLONG_MAX) so that powmod dont overflow
// Its better to avoid this by not using nCr at all

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
        vi D(n+1);
        D[0]=1;
        D[1]=0;
        for(int i=2;i<=4;i++)
        {
            D[i] = (i-1) * (D[i-1]+D[i-2]);
        }
        k=n-k; // to find at most k correct

        int ans = 0;
        int C1 = n;
        int C2 = n*(n-1)/2;
        int C3 = n*(n-1)*(n-2)/6;
        int C4 = n*(n-1)*(n-2)*(n-3)/24;
        for(int i=k;i<=n;i++)
        {   
            if(n-i==0)
            {
                ans+=1;
            }
            if(n-i==1)
            {
                ans += C1 * D[n-i]; 
            }
            if(n-i==2)
            {
                ans += C2 * D[n-i]; 
            }
            if(n-i==3)
            {
                ans += C3 * D[n-i]; 
            }
            if(n-i==4)
            {
                ans += C4 * D[n-i]; 
            }
        }

        cout<<ans<<endl;
    }
}