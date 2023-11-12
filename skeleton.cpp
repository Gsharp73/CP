#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define desort(v) sort(v.begin(),v.end(),greater<int>())
#define MOD 1000000007
#define db long double
#define F first
#define S second
#define pb push_back
#define print(a) for(auto i:a)cout << i << " "; cout << endl;
#define input(a) for(auto &i:a)cin >> i;
#define all(x) x.begin(),x.end()
#define FOR(i,a,n) for(int i=a;i< n;i++)
#define FORN(i,a,n) for(int i=0;i<=n;i++)
#define mp make_pair
#define pb push_back
#define sz(x) int((x).size())
#define tcT template<class T

using str = string; 
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

vector<bool> isprime;
void sieve(int n)
{
    isprime.resize(n+2,true);
    for (int p=2; p*p<=n+1; p++)
        if (isprime[p] == true)
            for (int i=p*2; i<=n+1; i += p)
                isprime[i] = false;
}
tcT> bool ckmin(T& a, const T& b) {
	return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
	return a < b ? a = b, 1 : 0; }
// helper funcs
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x)) 
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
// to get ith bit and with 1<<i
// lower bound -> greater than or equal to x
// upper bound -> greater than x
int lcm(int a, int b) {
    return (a * b) / __gcd(a, b);
}
int binpow(int a,int b){int ans=1;while(b>0){if(b&1)ans=ans*a;a*=a;b>>=1;}return ans;}
bool checkprime(ll a)
{
    if(a<2) return false;
    else if(a==2) return true;
    else if(a%2==0) return false;
    else{
        for(int i=3;i*i<=a;i+=2){
            if(a%i==0) return false;
        }
    }
    return true;
}

// to take input string with spaces after taking input integers 
// cin.ignore(numeric_limits<streamsize>::max(), '\n');
// getline(cin,s);

void go(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void solve(){
	
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
	int _=1;
	cin >> _;
	while(_--){
		solve();
	}
}
