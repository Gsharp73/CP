#include <bits/stdc++.h>
using namespace std;

#define int long long

template <typename T>
class dsu {
private:
    vector<pair<T, int>> parent;
    vector<int> rankk;

public:
    dsu(int size) {
        parent.resize(size);
        rankk.resize(size, 0);
    }

    void make_set(T v) {
        parent[v] = std::make_pair(v, 0);
        rankk[v] = 0;
    }

    pair<T, int> find_set(T v) {
        if (v != parent[v].first) {
            int len = parent[v].second;
            parent[v] = find_set(parent[v].first);
            parent[v].second += len;
        }
        return parent[v];
    }

    void union_sets(T a, T b) {
        a = find_set(a).first;
        b = find_set(b).first;
        if (a == b) {
            return;
        }
        if (rankk[a] < rankk[b]) {
            swap(a, b);
        }
        parent[b] = make_pair(a, 1);
        if (rankk[a] == rankk[b]) {
            rankk[a]++;
        }
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        
    }
}

