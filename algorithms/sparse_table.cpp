#include <bits/stdc++.h>
using namespace std;
#define ll long long
// max min or gcd
template <typename T>
class SparseTable {
private:
    vector<vector<T>> table;
    vector<int> bin_log;
    int n;

public:
    SparseTable(vector<T>& arr) {
        n = arr.size();
        int log = 32 - __builtin_clz(n);
        table.resize(n, vector<T>(log));
        bin_log.resize(n + 1);
        bin_log[1] = 0;
        for (int i = 2; i <= n; i++) {
            bin_log[i] = bin_log[i / 2] + 1;
        }

        build(arr);
    }

    void build(vector<T>& arr) { // Nlog(N)
        for (int i = 0; i < n; i++) {
            table[i][0] = arr[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int L, int R) {
        int length = R - L + 1;
        int k = bin_log[length];
        return min(table[L][k], table[R - (1 << k) + 1][k]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        for (auto &i: v) cin >> i;

        SparseTable<ll> spt(v);
        ll q;
        cin >> q;
        while (q--) {
            ll l, r;
            cin >> l >> r;
            // l--, r--;
            cout << spt.query(l, r) << endl;
        }
    }
}
