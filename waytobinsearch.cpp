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
#define input(a) for(auta &x:a)cin >> x;
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
int n,x,y;
bool isgood(int t){
    if(t<min(x,y))
    return false;
    // ek copy pehle banana padega then aur copies
    int cnt=1;
    t-=min(x,y);
    cnt+=t/x+t/y;
    if(cnt>=n)return true;return false;
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(0);
   cin >> n >> x >> y;
   int l=0; // cnt < n
   int r=max(x,y)*n; // cnt>=n
   int ans=0;
   while(r>l+1){
    int mid=l+(r-l)/2;
    if(isgood(mid))
        {ans=mid;r=mid;}
    else
        l=mid;
   }
    cout << r << endl;
}
