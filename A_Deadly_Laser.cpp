#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define endl "\n"
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
        int n,m,sx,sy,d;
        cin>>n>>m>>sx>>sy>>d;
        sx--;
        sy--;

        int X1 = sx-d;
        int X2 = sx+d;
        int Y1 = sy-d;
        int Y2 = sy+d;

        // cout<<"X "<<X1<<" "<<X2<<endl;
        // cout<<"Y "<<Y1<<" "<<Y2<<endl;
        if((X1<=0 and Y1<=0))
        {   
            // cout<<"chk1"<<endl;
            cout<<-1<<endl;
            continue;
        }
        if((X2>=n-1 and Y2>=m-1))
        {
            // cout<<"chk2"<<endl;
            cout<<-1<<endl;
            continue;
        }
        if(X1<=0 and X2>=n-1)
        {
            cout<<-1<<endl;
            continue;
        }
        if(Y1<=0 and Y2>=m-1)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            cout<<n+m-2<<endl;
        }



        // set<pair<int,int>>L;
        // L.insert({sx,sy});
        // deque<pair<int,int>>q;
        // q.push_back({sx,sy});
        // while(q.size()>0)
        // {
        //     pair<int,int> P = q.front();
        //     int x = P.first;
        //     int y = P.second;
        //     if(abs(x-sx) + abs(y-sy)>d)
        //     {
        //         break;
        //     }
        //     L.insert({x,y});
        //     if(!L.count({x+1,y}) and x+1>=0 and x+1<n and y>=0 and y<m)
        //     {   
        //         q.push_back({x+1,y});
        //     }
        //     if(!L.count({x-1,y}) and x-1>=0 and x-1<n and y>=0 and y<m)
        //     {   
        //         q.push_back({x-1,y});
        //     }
        //     if(!L.count({x,y+1}) and x>=0 and x<n and y+1>=0 and y+1<m)
        //     {
        //         q.push_back({x,y+1});
        //     }
        //     if(!L.count({x,y-1}) and x>=0 and x<n and y-1>=0 and y-1<m)
        //     {
        //         q.push_back({x,y-1});
        //     }
        //     q.pop_front();
        // }
        // // for(int i=0;i<n;i++)
        // // {
        // //     for(int j=0;j<m;j++)
        // //     {
        // //         if(L.count({i,j}))
        // //         {
        // //             cout<<'#';
        // //         }
        // //         else
        // //         {
        // //             cout<<'.';
        // //         }
        // //     }
        // //     cout<<endl;
        // // }
        // if(L.count({0,0})==1 or L.count({n-1,m-1})==1)
        // {
        //     cout<<-1<<endl;
        //     continue;
        // }
        // int ans = 0;
        // deque<pair<int,int>>Q;
        // Q.push_back({0,0});
        // map<pair<int,int>,int>vis;
        // vis[{0,0}]=0;
        // bool ok = false;
        // while(Q.size()>0)
        // {
        //     auto P = Q.front();
        //     int x  = P.first;
        //     int y = P.second;
        //     if(!L.count({x+1,y}) and !vis.count({x+1,y}) and x+1>=0 and x+1<n and y>=0 and y<m)
        //     {   
        //         vis[{x+1,y}]=vis[{x,y}]+1;
        //         Q.push_back({x+1,y});
        //     }
        //     if(!L.count({x-1,y}) and !vis.count({x-1,y}) and x-1>=0 and x-1<n and y>=0 and y<m)
        //     {   
        //         vis[{x-1,y}]=vis[{x,y}]+1;
        //         Q.push_back({x-1,y});
        //     }
        //     if(!L.count({x,y+1}) and !vis.count({x,y+1}) and x>=0 and x<n and y+1>=0 and y+1<m)
        //     {
        //         vis[{x,y+1}]=vis[{x,y}]+1;
        //         Q.push_back({x,y+1});
        //     }
        //     if(!L.count({x,y-1}) and !vis.count({x,y-1}) and x>=0 and x<n and y-1>=0 and y-1<m)
        //     {
        //         vis[{x,y-1}]=vis[{x,y}]+1;
        //         Q.push_back({x,y-1});
        //     }
        //     Q.pop_front();
        // }
        // if(vis.count({n-1,m-1}))
        // {
        //     cout<<vis[{n-1,m-1}]<<endl;
        // }
        // else
        // {
        //     cout<<-1<<endl;
        // }
    }
}