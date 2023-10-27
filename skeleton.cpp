#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define srt(v) sort(v.begin(),v.end())
#define desort(v) sort(v.begin(),v.end(),greater<int>())
#define MOD 1000000007
#define double long double
#define F first
#define S second
#define print(a) for(auto x:a)cout << x << " "; cout << endl;
#define input(a) for(auto &x:a)cin >> x;
#define all(x) x.begin(),x.end()
vector<bool> isprime;
void sieve(int n)
{
    isprime.resize(n+2,true);
    for (int p=2; p*p<=n+1; p++)
        if (isprime[p] == true)
            for (int i=p*2; i<=n+1; i += p)
                isprime[i] = false;
}
int LCM(int a, int b) {
    return (a * b) / __gcd(a, b);
}
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
void solve(){
    
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
   int t=1;
   cin >> t;
   while(t--)
   {
        solve();  
   }
}
