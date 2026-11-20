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
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int LCM(int a,int b)
{
    return a/gcd(a,b) * b;

}
int LCM(int a,int b,int c)
{      
    return LCM(LCM(a,b),c);
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int a,b,c,n;
        cin>>a>>b>>c>>n;
        // int hcf1=lcm(a,b);
        // cout<<"lcm1 "<<hcf1<<endl;
        // int hcf2=lcm(b,c);
        // int hcf3=lcm(a,c);
        int ans = 0;
        int ans1 = n/a;
        int ans2 = n/b;
        int ans3 = n/c;
        int ans4 = n/(LCM(a,b));
        int ans5 = n/(LCM(b,c));
        int ans6 = n/(LCM(a,c));
        // int ans7 = n/(LCM(LCM(hcf1,hcf2),hcf3));
        int ans7 = n/(LCM(a,b,c));
        // cout<<ans1<<endl;
        // cout<<ans2<<endl;
        // cout<<ans3<<endl;
        // cout<<ans4<<endl;
        // cout<<ans5<<endl;
        // cout<<ans6<<endl;
        // cout<<ans7<<endl;
        // ans=ans1+ans2+ans3-ans4-ans5-ans6+ans7;
        ans = ans4 + ans5 + ans6 - 2*ans7;
        cout<<ans<<endl;
    }
}