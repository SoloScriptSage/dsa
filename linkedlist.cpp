#include <bits/stdc++.h>
using namespace std;

// Typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pll> vpl;
typedef vector<vl> vve;
typedef map<ll,ll> mll;
typedef set<ll> sll;

// Defines
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define INF 1e9
#define DIM 107
#define f first
#define s second
#define pb push_back
#define fill(a,val) memset(a, val, sizeof(a));
#define rep(n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i = a; i < b; ++i)
#define sortv(v) sort(v.begin(), v.end())
#define sortvr(v) sort(v.rbegin(), v.rend())
#define MOD 1000000007
#define ADD(a,b) ((a+b) % MOD)
#define MUL(a,b) ((a*b) & MOD)
#define endl "\n"
#define LOCAL_TESTING 0

// Templates
template<typename T>
constexpr T gcd(T m, T n) {
    // Euclidean algorithm for finding GCD
    while (n != 0) {
        T temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}

template<typename T>
constexpr T lcm(T m, T n) {
    if (m == 0 || n == 0) return 0;
    T abs_m = (m < 0) ? -m : m;
    T abs_n = (n < 0) ? -n : n;
    return (abs_m / gcd(abs_m, abs_n)) * abs_n;
}
ll inrange(ll num, ll LEFT, ll RIGHT){
    return num >= LEFT && num <= RIGHT;
}

ll bs(ll b[], ll n, ll ai_1, ll ai){
    ll l=0, h=n-1;
    ll res;
    while(l<=h){
        ll m = (l+h)/2;

        if(b[m]-ai >= ai_1){
            res=m;
            h=m-1;
        }else
            l=m+1;

    }
    return res;

    //O(log N)
}

// Actual Code Starts Here

void solve() {
    int a, b, c, d, K;
    cin >> a >> b >> c >> d >> K;
    int sum = abs(a-c) + abs(b-d);
    if(sum<=K && (K-sum)%2==0) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    fast;

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
