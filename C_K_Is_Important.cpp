// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// // #define endl "\n"
// #define vi vector<int>
// #define vc vector<char>
// #define vs vector<string>
// #define vpii vector<pair<int,int>>
// #define vpci vector<pair<char,int>>
// #define vpic vector<pair<int,char>>
// #define f(n) for(int i=0;i<n;i++)
// #define F(m,n) for(int i=m;i<n;i++)
// #define mod 1000000007
// long long power(long long a, long long b) {
//   long long res = 1;
//   while (b > 0) {
//       if (b & 1) res *= a;
//       a *= a;
//       b >>= 1;
//   }
//   return res;
// }
// int powmod(int x, int y, int m = mod) {
//     int res = 1;
//     x = x % m;
//     while (y > 0) {
//         if (y & 1) res = (1LL * res * x) % m;
//         y = y >> 1;
//         x = (1LL * x * x) % m;
//     }
//     return res;
// }
// signed main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cout.tie(NULL);
//     int t;
//     t=1;
//     cin>>t;
//     while(t--){
//         int n,k;
//         cin>>n>>k;
//         vi arr(n);
//         int sum = 0;
//         f(n)
//         {
//             cin>>arr[i];
//             sum+=arr[i];
//         }
//         int sum1 = 0;
//         int sum2 = 0;
//         for(int i=0;i<k-1;i++)
//         {
//             sum1+=arr[i];
//         }
//         int i = n-1;
//         int cnt = k-1;
//         while(cnt--)
//         {
//             // cout<<"chk"<<endl;
//             sum2+=arr[i];
//             i--;
//         }
//         cout<<sum-min(sum1,sum2)<<endl;
//     }
// }


#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// #ifndef vibing
//     #define vid(...) cout << "[" << #VA_ARGS << "]:", debug_out(VA_ARGS)
// #else
//     #define vid(...)
// #endif

template <typename T> std::ostream &operator<<(std::ostream &stream, const vector<T> &vec) {for (size_t i = 0; i < vec.size(); i++) { stream << vec[i]; if (i != vec.size() - 1) stream << ' '; }; return stream; } template <typename T> std::istream &operator>>(std::istream &stream, vector<T> &vec) {for (T &x : vec) stream >> x; return stream; } template <typename T, typename U> std::ostream &operator<<(std::ostream &stream, const pair<T, U> &pr) {stream << pr.first << ' ' << pr.second; return stream; } template <typename T, typename U> std::istream &operator>>(std::istream &stream, pair<T, U> &pr) {stream >> pr.first >> pr.second; return stream; } template <typename A, typename B> string to_string(pair<A, B> p); template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p); template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p); string to_string(const string &s) { return '"' + s + '"'; } string to_string(char c) {string s; s += c; return s; } string to_string(const char *s) { return to_string((string)s); } string to_string(bool b) { return (b ? "1" : "0"); } string to_string(vector<bool> v) {bool first = true; string res = "{"; for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", "; } first = false; res += to_string(v[i]); } res += "}"; return res; } template <size_t N> string to_string(bitset<N> v) {string res = ""; for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]); } return res; } template <typename A> string to_string(A v) {bool first = true; string res = "{"; for (const auto &x : v) {if (!first) {res += ", "; } first = false; res += to_string(x); } res += "}"; return res; } template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; } template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; } template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } void debug_out() { cout << endl; } template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cout << " " << to_string(H); debug_out(T...); }

#define int long long
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define v vector
#define ss second
#define reutrn return
#define fo(i, a, b) for (int i = a; i < b; i++)

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<vi> vvi;

const int MOD = 1e9+7;
const int INF = 1e18;

int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }
int pow_setBit(int x){return 1 << (31 - __builtin_clz(x));}
int power(int a , int b ) {int ans = 1; while(b){if (b & 1)ans = ans*a%MOD;a= a*a%MOD;b >>=1;}return ans;}

bool ansh = 1;

void solve() {
    // write your solution here
    
    int n ,k;
    cin >>n >> k;

    vi vec(n+1);

    for(int i  =1; i<=n; i++) cin >> vec[i];

    int ans = 0;



    for(int i = k; i<=n-k+1 ; i++){
        ans += vec[i];
    }

    int l = k-1;
    int r = n-k+2;

    if (k > n-k+1) {
        l = n-k+1;
        r = k;
    }


    // cerr << l <<' ' << r <<"\n";

    while(l) {

        ans += max(vec[l] , vec[r]);

        l--;
        r++;
    }
    cout << ans <<"\n";


}
int32_t main() {
    fastio;
    int t = 1;
    ansh && cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
