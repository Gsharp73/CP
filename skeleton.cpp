#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional> // for less
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define desort(v) sort(v.begin(),v.end(),greater<int>())
#define db long double
#define F first
#define S second
#define pb push_back
#define print(a) for(auto i:a)cout << i << " "; cout << endl;
#define input(a) for(auto &i:a)cin >> i;
#define all(x) x.begin(),x.end()
#define FOR(i,A,n) for(int i=A;i< n;i++)
#define FORR(i,A,B) for(int i=A;i>=B;i--)
#define FORN(i,A,n) for(int i=A;i<=n;i++)
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define tcT template<class T
#define str string 
#define theforce ios::sync_with_stdio(false);cin.tie(0);
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;
tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;
typedef tree<int, null_type, less<int>, rb_tree_tag,  
            tree_order_statistics_node_update>  
    ordered_set;
// to take input string with spaces after taking input integers 
// cin.ignore(numeric_limits<streamsize>::max(), '\n');
// getline(cin,s);

constexpr int pct(int x) {return __builtin_popcount(x);} // # of bits set
constexpr int bits(int x){return 31-__builtin_clz(x);} // floor(log2(x)) 
ll cdiv(ll a, ll b){return a/b+((a^b)>0&&a%b);} // divide a by b rounded up
ll ffdiv(ll a, ll b){return (a/b)-((a^b)<0&&a%b);} // divide a by b rounded down
tcT > bool ckmin(T &a, const T &b){return b < a ? a = b, true : false;} 
tcT > bool ckmax(T &a, const T &b){return a < b ? a = b, true : false;}

// to get ith bit and with 1<<i
// lower bound -> greater than or equal to x
// upper bound -> greater than x

void go(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
int N=1e5+10;
vector<vector<int>> gp(N);
vb vis(N); 
const int MOD = 1e9+7;

void solve(){
     
}

int main()
{
    theforce;
    int _=1;
    cin >> _;
    while(_--){
        solve();
    }
}

/* do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 */
