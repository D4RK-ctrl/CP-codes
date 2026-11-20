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
char nc(char ch)
{
    ch++;
    if(ch>'Z')
    {
        ch='A';
    }
    return ch;
}
int nd(int n)
{
    n++;
    return n%10;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = 0;
        char ch = 'A';
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                if(j%2==1)
                {
                    cout<<ch;
                    ch=nc(ch);
                }
                else
                {
                    cout<<x;
                    x=nd(x);
                }
            }
            // cout<<"i "<<i<<endl;
            // for(int j=i+1;j<(2*n)-i;j++)
            // {
            //     cout<<" ";
            // }
            int cnt = 2*n-i*2;
            while(cnt--)
            {
                cout<<" ";
            }
            for(int j=(2*n)-i+1;j<=2*n;j++)
            {
                if(j%2==1)
                {
                    cout<<ch;
                    ch=nc(ch);
                }
                else
                {
                    cout<<x;
                    x=nd(x);
                }
            }
            cout<<endl;
        }
    }
}