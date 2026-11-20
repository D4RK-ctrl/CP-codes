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
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}
#define mod 1000000007
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
    if(n<0){cout<<"error";return 0;}
    if(n==0){cout<<"error";return 1;}
    int res=1;
    for(int i=2;i<=n;i++) res=(res*i)%m;
    return res;
}
int inv(int n, int m){
    if(n==0)cout<<"error";
    return powmod(n,m-2,m);
}
int nCr(int n, int r, int m=1000000007){
    if(r<0 || r>n){return 0;}
    int numerator = fact(n, m);
    int denominator = (inv(fact(r, m), m) * inv(fact(n-r, m), m)) % m;
    return (numerator * denominator) % m;
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
    reverse(ans.begin(),ans.end());
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
    // cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans = 0;
        int n = s.size();
        map<char,vector<char>>a;
        f(n)
        {
            if(s[i]=='E')
            {
                a['E'].push_back(i);
            }
            else if(s[i]=='G')
            {
                a['G'].push_back(i);
            }
            else
            {
                a['O'].push_back(i);
            }
        }     
        vi chk(n);
        string pr = "#";
        int ans = 0;
        // int p0 = 0;
        // int p1 = 0;
        // int p2 = 0;
        map<char,int>pt;
        pt['E']=0;
        pt['G']=0;
        pt['O']=0;
        for(int i=0;i<n;i++)
        {
            if(chk[i])continue;
            else if(pr=="#")
            {   
                pr="";
                pr+=s[i];
                ans++;
                continue;
            }
            else if(pr!="#")
            {
                pr+=s[i];
            }
            if(pr[0]!='E' and pr[1]!='E')
            {
                pr+='E';
            }
            if(pr[0]!='G' and pr[1]!='G')
            {
                pr+='G';
            }
            if(pr[0]!='O' and pr[1]!='O')
            {
                pr+='O';
            }
            int k = 2;
            int big = i;
            while(a[pr[k%3]].size()>pt[pr[k%3]])
            {   
                auto it = upper_bound(a[pr[k%3]].begin(), a[pr[k%3]].end(),big);
                if (it != a[pr[k%3]].end()) {
                    int val = *it; // The value just bigger than x
                    // int idx = it - a[pr[k%3]].begin(); // Its index
                    chk[val]=1;
                }
                pt[pr[k%3]]++;
                k++;
            }
        }
    }
}