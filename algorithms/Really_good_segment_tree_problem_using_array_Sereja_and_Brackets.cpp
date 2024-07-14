#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
    public:
    vector<array<int, 3>> seg;
    SegmentTree (int n) {
        seg.resize(4 * n);
    }
    void build (int index, int low, int high, vector<char> &arr) {
        if (low == high) {
            if (arr[low] == '(')
                seg[index][0] = 1;
            else if (arr[low] == ')')
                seg[index][1] = 1;
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, arr);
        build(2 * index + 2, mid + 1, high, arr);
        int opening = seg[2 * index + 1][0];
        int closing = seg[2 * index + 2][1];
        int have = seg[2 * index + 1][2] + seg[2 * index + 2][2];
        int canbe = min(opening, closing);
        have += canbe;
        opening -= canbe;
        closing -= canbe;
        seg[index][0] = seg[2 * index + 1][0] + seg[2 * index + 2][0] - canbe;
        seg[index][1] = seg[2 * index + 1][1] + seg[2 * index + 2][1] - canbe;
        seg[index][2] = have;
    }

    array<int, 3> query(int index, int low, int high, int l, int r) {
        // 3 cases 
        // 1 -> no overlap => r < low || l > high
        if (r < low || l > high) {
            array<int, 3> empt = {0, 0, 0};
            return empt;
        }

        // case 2 - complete overlap => l >= low && r <= high
        if (l <= low && high <= r) {
            return seg[index];
        }

        // case 3 => partial overlap

        int mid = (low + high) >> 1;
        array<int, 3> left = query(2 * index + 1, low, mid, l, r);
        array<int, 3> right = query(2 * index + 2, mid + 1, high, l, r);
        array<int, 3> res = {0, 0, 0};
        int opening = left[0];
        int closing = right[1];
        int have = left[2] + right[2];
        int canbe = min(opening, closing);
        have += canbe;
        opening -= canbe;
        closing -= canbe;
        res[0] = left[0] + right[0] - canbe;
        res[1] = left[1] + right[1] - canbe;
        res[2] = have;
        return res;
    }

    // void update (int index, int low, int high, int i, int val) {
    //     if (low == high) {
    //         seg[index] = val;
    //         return;
    //     }
    //     int mid = (low + high) >> 1;
    //     if (i <= mid) {
    //         update(2 * index + 1, low, mid, i, val);
    //     }
    //     else {
    //         update(2 * index + 2, mid + 1, high, i, val); 
    //     }
    //     seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]); 
    // }
};
int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        v[i] = s[i];
    }
    SegmentTree sg(n);
    sg.build(0, 0, n - 1, v);
    // for (auto &i: sg.seg) {
    //     cout << i[2] << " ";
    // }
    // cout << endl;
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = sg.query(0, 0, n - 1, l, r)[2];
        cout << ans * 2 << endl;
    }
}