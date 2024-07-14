#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree {
    public:
    vector<int> seg;
    SegmentTree (int n) {
        seg.resize(4 * n);
    }
    void build (int index, int low, int high, vector<int> &arr, int alt) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * index + 1, low, mid, arr, alt ^ 1);
        build(2 * index + 2, mid + 1, high, arr, alt ^ 1);
        if (alt) {
            seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
        }
        else {
            seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
        }
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

    void update (int index, int low, int high, int i, int val, int alt) {
        if (low == high) {
            seg[index] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid) {
            update(2 * index + 1, low, mid, i, val, alt ^ 1);
        }
        else {
            update(2 * index + 2, mid + 1, high, i, val, alt ^ 1); 
        }
        if (alt) {
            seg[index] = seg[2 * index + 1] | seg[2 * index + 2];
        }
        else {
            seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
        }
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(pow(2, n));
    for (auto &i: v) cin >> i;
    SegmentTree sg(pow(2, n));

    // n odd then OR n even then XOR
    sg.build(0, 0, pow(2, n) - 1, v, n % 2);
    while (m--) {
        int index, val;
        cin >> index >> val;
        index--;
        sg.update(0, 0, pow(2, n) - 1, index, val, n % 2);
        int ans = sg.seg[0];
        cout << ans << endl;
    }   
}