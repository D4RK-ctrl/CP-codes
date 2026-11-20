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
// struct SegTree {
//     int n;
//     vector<int> tree;

//     SegTree(int n) {
//         this->n = n;
//         tree.assign(4 * n, 0);
//     }

//     // change this for the problem
//     int merge(int a, int b) {
//         return a + b;   // default: sum
//     }

//     // change this for the problem
//     int identity() {
//         return 0;       // default for sum
//     }

//     void build(int id, int l, int r, vector<int> &arr) {
//         if (l == r) {
//             tree[id] = arr[l];
//             return;
//         }

//         int mid = (l + r) / 2;
//         build(id * 2, l, mid, arr);
//         build(id * 2 + 1, mid + 1, r, arr);
//         tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
//     }

//     // point update: a[idx] = val
//     void update(int id, int l, int r, int idx, int val) {

//         if(l>idx or r<idx)return;

//         if (l == r) {
//             tree[id] = val;
//             return;
//         }

//         int mid = (l + r) / 2;
//         // if (idx <= mid) update(id * 2, l, mid, idx, val);
//         // else update(id * 2 + 1, mid + 1, r, idx, val);
//         update(id * 2, l, mid, idx, val);
//         update(id * 2+1, mid+1, r , idx, val);

//         tree[id] = merge(tree[id * 2], tree[id * 2 + 1]);
//     }

//     // range query on [ql, qr]
//     int query(int id, int l, int r, int ql, int qr) {
//         if (r < ql || qr < l) return identity();
//         if (ql <= l && r <= qr) return tree[id];

//         int mid = (l + r) / 2;
//         int leftAns = query(id * 2, l, mid, ql, qr);
//         int rightAns = query(id * 2 + 1, mid + 1, r, ql, qr);
//         return merge(leftAns, rightAns);
//     }
// };
struct SegTree
{
    int n;
    vector<int>tree;
    SegTree(int n)
    {
        this->n = n;
        tree.assign(4*n,0);
    }
    int merge(int a,int b)
    {
        return a + b;
    }
    int identity()
    {
        return 0;
    }
    void build(int id, int l, int r, vector<int>&arr)
    {
        if(l==r)
        {
            tree[id] = arr[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(id*2,l,mid,arr);
        build(id*2+1,mid+1,r,arr);
        tree[id] = merge(tree[id*2],tree[id*2+1]);
    }
    void update(int id, int l, int r, int idx, int val)
    {   
        if(l>idx or r<idx)return;
        if(l==r)
        {
            tree[id] = val;
            return;
        }
        int mid = l + (r-l)/2;
        update(id*2,l,mid,idx,val);
        update(id*2+1,mid+1,r,idx,val);
        tree[id] = merge(tree[id*2],tree[id*2+1]);
    }
    int query(int id, int l, int r, int ql, int qr)
    {
        if(qr<l or r<ql)return identity();
        if(ql<=l and qr>=r)return tree[id];
        int mid = l + (r-l)/2;
        int L = query(id*2,l,mid,ql,qr);
        int R = query(id*2+1,mid+1,r,ql,qr);
        return merge(L,R);
    }
};

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    t=1;
    // cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vi arr(n);
        f(n)cin>>arr[i];
        SegTree st(n);
        st.build(1,0,n-1,arr);
        while(q--)
        {
            int ch;
            cin>>ch;
            if(ch==1)
            {
                int id,v;
                cin>>id>>v;
                st.update(1,0,n-1,id,v);
            }
            else if(ch==2)
            {   
                int l,r;
                cin>>l>>r;
                r--;
                cout<<st.query(1,0,n-1,l,r)<<endl;
            }
        }
    }
}