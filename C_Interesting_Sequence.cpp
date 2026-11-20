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
        int n,x;
        cin>>n>>x;
        if(x>n)
        {
            cout<<-1<<endl;
            continue;
        }
        if(x==n)
        {
            cout<<n<<endl;
            continue;
        }
        vector<int>N = rice(n,2,10);
        vector<int>X = rice(x,2,10);
        if(x==0)
        {
            int k = N.size();
            // cout<<"check"<<endl;
            cout<<power(2,k)<<endl;
            continue;
        }
        int ans = 0;
        bool flag = false;
        bool done = false;
        // bool once = false;
        while(X.size()!=N.size())
        {
            X.push_back(0);
        }
        for(int i=0;i<N.size();i++)
        {
            if(N[i]==0 and X[i]==0)
            {
                continue;
            }
            if(flag and N[i]!=X[i])
            {
                ans=-1;
                break;
            }
            if(N[i]==0 and X[i]==1)
            {
                ans=-1;
                break;
            }
            if(N[i]==1 and X[i]==0)
            {   
                ans = n + (power(2,i));
                cout<<"ans "<<ans<<endl;
                int k = n;
                for(int j=n;j<=ans;j++)
                {
                    k=(k&j);
                }
                if(k != x)
                {
                    // cout<<"check1"<<endl;
                    ans=-1;
                    break;
                }
                else
                {   
                    done=true;
                    break;
                }
            }
            if(N[i]==1 and X[i]==1)
            {
                ans+=power(2,i);
                flag=true;
                continue;
            }
        }
        if(ans==-1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(done)
        {
            cout<<ans<<endl;
            continue;
        }
        int id = N.size();
        for(int i=N.size()-1;i>=0;i--)
        {   
            if(N[i]!=X[i])break;
            // cout<<N[i]<<" "<<X[i]<<endl;
            if(N[i]==0)id=i;
        }
        // cout<<"id "<<id<<endl;
        ans+=power(2,id);
        cout<<ans<<endl;
    }
}