#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T>
class SparseTable {
private:
    vector<vector<T>> table;
    vector<int> logValues;
    int n;

public:
    SparseTable(vector<T>& v) {
        n = v.size();
        int log = 32 - __builtin_clz(n);
        table.resize(n, vector<T>(log));
        logValues.resize(n + 1);

        logValues[1] = 0;
        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }
        build(v);
    }

    void build(vector<T>& v) { // N log(N)
        for (int i = 0; i < n; i++) {
            table[i][0] = v[i];
        }

        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 0; i + (1 << j) - 1 < n; i++) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int L, int R) {
        int length = R - L + 1;
        int k = logValues[length];
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
            l--, r--;
            cout << spt.query(l, r) << endl;
        }
    }
}
