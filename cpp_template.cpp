#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>  
#include <functional>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define print(a) for(auto i:a)cout << i << " ";cout << endl;
#define input(a) for(auto &i:a)cin >> i;
#define all(x) x.begin(),x.end()
// const int MOD =  998244353;
const int MOD = 1e9+7;
int modadd(int a, int b, int m){a=a%m;b=b%m;return (((a+b)%m)+m)%m;}
int modmul(int a, int b, int m){a=a%m;b=b%m;return ((((ll)a*(ll)b)%m)+m)%m;}
int modsub(int a, int b, int m){a=a%m;b=b%m;return (((a-b)%m)+m)%m;}
int modpow(int x, int y){ll res=1;x=x%MOD;while(y>0){if(y&1)res=(res*(ll)x)%MOD;y=y>>1;x=((ll)x*(ll)x)%MOD;}return res;} 
int modinv(int x){return modpow(x , MOD-2);} 
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
ll cdiv(ll a, ll b) {return a / b + ((a ^ b) > 0 && a % b);}
ll binpow(ll a, ll b) {ll res=1;while(b>0){if(b&1)res=res*a;a=a*a;b>>=1;}return res;}
void go() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

void solve() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    cin >> _;
    while (_--) {
        solve();
    }
}

