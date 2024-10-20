#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T>
class BITree {
private:
    vector<T> BIT; // this is 1 indexed
    int n;
public:
    BITree(int size) {
        n = size;
        BIT.resize(n + 1, 0);
    }

    void update(int x, T delta) {
        for (; x <= n; x += (x & -x)) {
            BIT[x] += delta;
        }
    }

    T query(int x) {
        T sum = 0;
        for (;x > 0; x -= (x & -x)) {
            sum += BIT[x];
        }
        return sum;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1; // cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        BITree<int> bt(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            bt.update(i + 1, a[i]);
        }
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type) {
                int i, x;
                cin >> i >> x;
                bt.update(i, x);
            }
            else {
                int l, r;
                cin >> l >> r;
                int ans = bt.query(r) - bt.query(l - 1);
                cout << ans << endl;
            }
        }
    }
}
