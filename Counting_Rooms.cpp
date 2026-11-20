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
bool chk(int x,vector<char>&A)
{
    if(x<0 or x>=A.size())return false;
    if(A[x]=='#')return false;
    return true;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<char>A;
        for(int i=0;i<n*m;i++)
        {
            char ch;
            cin>>ch;
            A.push_back(ch);
        }
        int ans = 0;
        vector<int>vis(n*m);
        int id = -1;
        for(int i=0;i<n*m;i++)
        {   
            if(A[i]=='A')
            {
                id=i;
            {
        }
        vector<int>pt(n*m,-1);
        pt[id] = n*m;
        deque<int>q;
        q.push_back(id);
        vis[id]=1;
        bool ans = false;
        int id2 = -1;
        while(q.size()>0)
        {
            int x = q.front();
            q.pop_front();
            if(A[x]=='B')
            {
                id2=x;
                ans=true;
                break;
            }
            if(x%m!=m-1 and chk(x+1,A) and !vis[x+1])
            {
                int it = x+1;
                vis[it]=1;
                q.push_back(x+1);
            }
            if(x%m!=0 and chk(x-1,A) and !vis[x-1])
            {
                int it = x-1;
                vis[it]=1;
                q.push_back(x-1);
                pt[it]=x;
            }
            if(chk(x+m,A) and !vis[x+m])
            {
                int it = x+m;
                vis[it]=1;
                q.push_back(x+m);
                pt[it]=x;
            }
            if(chk(x-m,A) and !vis[x-m])
            {
                int it = x-m;
                vis[it]=1;
                q.push_back(x-m);
                pt[it]=x;
            }
        }
        if(!ans)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            string ANS = "";
            int cur = id2;
            while(pt[cur]!=n*m)
            {
                if(pt[cur]==cur+1)
                {
                    ANS+='L';
                }
                if(pt[cur]==cur-1)
                {
                    ANS+='R';
                }
                if(pt[cur]==cur+m)
                {
                    ANS+='D';
                }
                if(pt[cur]==cur-m)
                {
                    ANS+='U';
                }
                cur=pt[cur];
            }
            cout<<ANS<<endl;
        }
        
    }
}