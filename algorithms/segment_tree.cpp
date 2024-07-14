#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> seg;
    public:
    SegmentTree (int n) {
        seg.resize(4 * n);
    }
    void build (int index, int low, int high, vector<int> &arr) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
    }

    int query(int index, int low, int high, int l, int r) {
        // 3 cases 
        // 1 -> no overlap => r < low || l > high
        if (r < low || l > high) {
            return INT_MAX;
        }

        // case 2 - complete overlap => l >= low && r <= high
        if (l <= low && high <= r) {
            return seg[index];
        }

        // case 3 => partial overlap

        int mid = (low + high) >> 1;
        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);
        return min(left, right); 
    }

    void update (int index, int low, int high, int i, int val) {
        if (low == high) {
            seg[index] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) {
            update(2 * index + 1, low, mid, i, val);
        }
        else {
            update(2 * index + 2, mid + 1, high, i, val); 
        }
        seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]); 
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> seg(4 * n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    SegmentTree sg(n);
    sg.build(0, 0, n - 1, v);  // O(n)
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1){
            int l, r;
            cin >> l >> r;
            int ans = sg.query(0, 0, n - 1, l, r);
            cout << ans << endl;
        }
        else if (type == 2) {
            int index, val;
            cin >> index >> val;
            v[index] = val;
            sg.update(0, 0, n - 1, index, val);
        }
    }
}