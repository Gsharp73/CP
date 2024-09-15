#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <class T> class Math {
  public:
    vector<T> fac;
    vector<T> invfac;
    Math() {

    }
    Math(int n) {
        fac.resize(n);
        invfac.resize(n);
        fac[0] = invfac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = mod(i * fac[i - 1]);
            invfac[i] = modinv(fac[i]);
        }
    }
    T modinv(T x, T m = MOD) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = MOD) {
        T res = 1;
        while (exp) {
            if (exp & 1) {
                res = mod(res * base, m);
            }
            base = mod(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n) {
            return 0;
        }
        T ans = fac[n];
        ans = mod(ans * invfac[n - k]);
        ans = mod(ans * invfac[k]);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {

    }
}

