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
#define str to_string
vector<int> arrify(string s){
    vector<int>ans;
    for(int i=0;i<s.size();i++){
        ans.push_back(s[i]-'0');
    }
    return ans;
}
vector<int> arrify(int n){
    return arrify(to_string(n));
}
vector<int> rice(vector<int> n, int to_base, int self_base=10){
    if(to_base==self_base)return n;
    if(n.size()==1 and n[0]==0)return n;
    if(self_base!=10){
        int ans = 0;
        for(int i=0;i<n.size();i++){
            ans=(ans*self_base)+(n[i]);
        }
        n = arrify(ans);
    }
    if(to_base==10){
        return n;
    }
    vector<int>ans;
    int x = 0;
    for(int i=0;i<n.size();i++)
    {
        x=x*10;
        x+=n[i];
    }
    while(x>0){
        ans.push_back(x%to_base);
        x/=to_base;
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> rice(string n,int to_base,int self_base=10){
    return rice(arrify(n),to_base,self_base);
}
vector<int>rice(int n,int to_base, int self_base){
    return rice(arrify(n),to_base,self_base);
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
        int XR;
        if(n%4==0)
        {   
            XR = n;
        }
        else if(n%4==1)
        {
            XR=1;
        }
        else if(n%4==2)
        {
            XR=n+1;
        }
        else
        {
            XR=0;
        }

        vi ans(n,0);
        vi num = rice(n,2,10);
        int bits=num.size();
        if(n%4==3)
        {
            int k = 1;
            int bits = 1;
            while(k*2<=n)
            {
                k=k*2;
                bits++;
            }
            // cout<<"bits "<<bits<<endl;
            for(int i=bits;i>=1;i=i-2)
            {
                ans[power(2,i-1)-1]=1;
            }
            // f(n)
            // {
            //     cout<<ans[i]<<" ";
            // }
            // cout<<endl;
        }
        else
        {
            vi N = rice(XR,2,10);
            while(N.size()!=bits)
            {
                N.push_back(0);
            }
            vi st(N.size()+1,0);
            // cout<<"bits "<<bits<<endl;  
            for(int i=N.size()-1;i>=0;i--)
            {
                if(st[i+1])
                {
                    st[i]=N[i];
                }
                else
                {
                    ans[power(2,i)-1]=1;
                    if(N[i]==0)
                    {
                        st[i+1]=1;
                        st[i]=1;
                    }
                    else
                    {
                        st[i+1]=1;
                        st[i]=0;
                    }
                }
            }
        }
        f(ans.size())
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        // if(n%4==3)
        // {
        //     int k = 1;
        //     int bits = 1;
        //     while(k*2<=n)
        //     {
        //         k=k*2;
        //         bits++;
        //     }
        //     cout<<"bits "<<bits<<endl;
        //     for(int i=bits;i>=1;i=i-2)
        //     {
        //         ans[power(2,i-1)-1]=1;
        //     }
        //     f(n)
        //     {
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // else if(n%4==0)
        // {
        //     ans.back()=1;
        //     ans[ans.size()-3]=1;
        //     for(int i=0;i<n;i++)
        //     {
        //         cout<<ans[i]<<" ";
        //     }
        //     cout<<endl;
        // }
        // else if(n%4==1)
        // {

        // }

        int og = 0;
        for(int i=1;i<=n;i++)
        {
            og=(og|i);
        }
        // cout<<og<<endl;
        int nw = 0;
        for(int i=1;i<=n;i++)
        {   
            if(ans[i-1]==1)
            {
                nw=(nw^(2*i));
            }
            else
            {
                nw=(nw^i);
            }
        }
        // cout<<og<<endl;

        // if(nw<2*og)
        // {
        //     cout<<n<<endl;
        // }
    }
}