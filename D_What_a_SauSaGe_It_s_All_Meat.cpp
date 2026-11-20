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

bool ansh = true;

void solve() {
    // write your solution here
    int n;
    cin >> n;

    int q; cin >> q;

    vi vec(n); cin >> vec;

    vi ye(16);

    ye[0] =1;
    ye[3] =1;
    ye[5] =1;
    ye[6] =1;
    ye[9] =1;
    ye[10] =1;
    ye[12] =1;
    ye[15] =1;

    int ans =0 ;
    for(auto it : vec) {

        if (ye[it]) ans++;
    }

    cout << ans <<" ";

    while(q--) {

        int cnt ;cin  >> cnt;
        cnt--;
        int val ; cin >>val;
        if (ye[vec[cnt]]) ans--;

        vec[cnt] = val;
        if (ye[val]) ans++;

        cout << ans <<" ";
    }
    cout <<"\n";
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
