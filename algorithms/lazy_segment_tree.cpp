#include <bits/stdc++.h>
using namespace std;
#define ll long long

// use for range updates and queries

class LazySegmentTree {
    ll n;
    vector<ll> seg, lazy;
    public:
    LazySegmentTree(ll sz) {
        this->n = sz;
        seg.resize(4 * sz, LONG_LONG_MAX);
        lazy.resize(4 * sz, LONG_LONG_MAX);
    }

    void build(ll index, ll low, ll high, vector<ll> &a) {
        if (low == high) {
            seg[index] = a[low];
            return;
        }
        ll mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, a);
        build(2 * index + 2, mid + 1, high, a);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    void propagate(ll index, ll low, ll high) {
        if (lazy[index] != LONG_LONG_MAX) {
            // Apply the pending update to the current segment
            seg[index] = min(seg[index], lazy[index]);

            // If it's not a leaf node, propagate the update to the children
            if (low != high) {
                lazy[2 * index + 1] = min(lazy[index], lazy[2 * index + 1]);
                lazy[2 * index + 2] = min(lazy[index], lazy[2 * index + 1]);
            }
            // Clear the lazy value
            lazy[index] = LONG_LONG_MAX;
        }
    }

    void updateRange(ll index, ll low, ll high, ll l, ll r, ll val) {
        // First, propagate any pending updates
        propagate(index, low, high);

        if (r < low || l > high) return;

        if (l <= low && high <= r) {
            lazy[index] = min(lazy[index], val); // Mark the update for lazy propagation
            propagate(index, low, high); // Apply the update to the current segment
            return;
        }
        
        ll mid = (low + high) >> 1;
        updateRange(2 * index + 1, low, mid, l, r, val);
        updateRange(2 * index + 2, mid + 1, high, l, r, val);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    ll queryRange(ll index, ll low, ll high, ll l, ll r) {
        propagate(index, low, high);
        if (r < low || l > high) {
            return LONG_LONG_MAX;
        }

        if (l <= low && high <= r) {
            return seg[index];
        }
        ll mid = (low + high) >> 1;
        ll left = queryRange(2 * index + 1, low, mid, l, r);
        ll right = queryRange(2 * index + 2, mid + 1, high, l, r);
        return min(left, right);
    }

    ll query(ll l, ll r) {
        return queryRange(0, 0, n - 1, l, r);
    }
    void update(ll l, ll r, ll val) {
        updateRange(0, 0, n - 1, l, r, val);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {

    }
}
