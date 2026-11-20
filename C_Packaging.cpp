#include <bits/stdc++.h>
    using namespace std;
    #define int long long
    // #define double long double

int mod=1e13+3;
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
    if(r<0 || r>n){cout<<"error";return 0;}
    int numerator = fact(n, m);
    int denominator = (inv(fact(r, m), m) * inv(fact(n-r, m), m)) % m;
    return (numerator * denominator) % m;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,q,x;
    cin>>n>>q>>x;
    vector<int>a(n);
    for(int d=0;d<n;d++) cin>>a[d];
    vector<int>first(2*n);
    first[0]=a[0];
    for(int i=0;i<n;i++) a.push_back(a[i]);
    for(int d=1;d<2*n;d++){
        first[d]+=first[d-1]+a[d];
    }
    for(auto it:first)cout<<it<<" ";
    cout<<endl;
    int count=n+1;
    int u=0;
    int sum=first[n-1];
    int ex = (x/sum)*(n);
    int y=x%sum;
    if(y==0)
    {
        y=sum;
        ex=ex-n;
    }    
    vector<int>ans;
    int L = -1;
    int cnt=1;
    map<int,int>p; // start id, ship number
    while(cnt<=count){
        int g=first[u]-a[u]+y;
        cout<<"cnt "<<cnt<<endl<<" g "<<g<<endl;
        auto it=lower_bound(first.begin(),first.end(),g);
        int id=it-first.begin();
        cout<<" id "<<id<<endl;
        id%=n;
        if(p[id]!=0){
            L=cnt-p[id];
            break;
        }
        else {
            ans.push_back(id);
            p[id]=cnt;
        }
        u=(id+1)%n;
        cnt++;
    }
    cout<<"L "<<L<<endl;
    cout<<"ans.size() "<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    while(q--)
    {
        int ep1=-1;
        int val;
        cin>>val;
        int og=val;
        if(val==1)
        {
            val--;
            val=val%L;

            int ep2 = ans[val];
            cout<<"ep2 "<<ep2<<" ep1 "<<ep1<<endl;
            cout<<(ex)+ep2-ep1<<endl;
            continue;
        }
        val--;
        val=val%L;

        int ep2 = ans[val];

        val--;
        if(val==-1)val=ans.size()-1;
        ep1 = ans[val];

        while(ep1>=ep2)
        {
            ep2+=n;
        }
        cout<<"ep2 "<<ep2<<" ep1 "<<ep1<<endl;
        cout<<(ex)+ ep2 - ep1<<endl;
    }
}