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
        int n,l,r,s;
        cin>>n>>l>>r>>s;
        l--;
        r--;
        int N = r-l+1;
        vi array(n);
        int sum = 0;
        for(int i=l;i<=r;i++)
        {
            array[i] = i-l+1;
            sum+=array[i];
        }
        // cout<<sum<<endl;
        if(sum>s)
        {   
            // cout<<"check"<<endl;
            cout<<-1<<endl;
            continue;
        }
        int ul = n;
        int carry = s-sum;
        bool ok = false;
        set<int>st;
        for(int i=r;i>=l;i--)
        {   
            array[i]+=carry;
            carry=0;
            if(array[i]>ul)
            {
                carry = array[i]-ul;
                array[i]=ul;
            }
            st.insert(array[i]);
            ul--;
        }
        
        if(carry)
        {   
            // cout<<"check2"<<endl;
            cout<<-1<<endl;
            continue;
        }
        int p = 1;
        for(int i=0;i<l;i++)
        {   
            while(st.count(p))
            {
                p++;
            }
            array[i] = p;
            st.insert(array[i]);
        }
        for(int i=r+1;i<n;i++)
        {
            while(st.count(p))
            {
                p++;
            }
            array[i] = p;
            st.insert(array[i]); 
        }
        f(n)
        {
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}