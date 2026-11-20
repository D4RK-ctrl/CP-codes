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
        string s;
        cin>>s;
        bool ok = false;
        int cnt = 0; 
        int iv = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cnt++;
            }
            else
            {
                iv+=cnt;
            }
        }
        string str = s;
        sort(str.begin(),str.end());
        if(str[0]==str[n-1] or str==s)
        {
            cout<<"Bob"<<endl;
            continue;
        }
        if(iv%2==1)
        {
            ok=true;
        }
        while(s.size()>0 and s.back()=='1')
        {
            s.pop_back();
        }
        int i=0;
        for(i=0;i<n;i++)
        {
            if(s[i]=='1')
            break;
        }
        // cout<<"i "<<i<<endl;
        i++;
        // cout<<"cnt "<<cnt<<endl;
        cnt=1;
        for(i;i<s.size();i++)
        {
            if(s[i]==s[i-1])
            {
                cnt++;
            }
            else
            {
                if(cnt%2==1)
                {   
                    // cout<<"cnt "<<cnt<<endl;
                    ok=true;
                    break;
                }
                cnt=1;
            }
            // cout<<"i cnt "<<i<<" "<<cnt<<endl;
        }
        if(cnt%2==1)
        ok=true;
        if(ok)
        {
            cout<<"Alice"<<endl;
        }
        else
        {
            cout<<"Bob"<<endl;
        }
    }
}