#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Number of ways to place 2x1 dominos on an N x M board
// There are two ways to place: horizontally or vertically
// The mask keeps track of the current state of the board row

int n, m;
vector<vector<vector<int>>> dp;
int vis[13][13];

bool check(int i, int j) {
    return j < m;
}

int rec(int i, int j, int mask) {
    // Base case
    if (i > n || j > m || mask >= (1 << m)) return 0;
    if (i == n) {
        return (mask == (1 << m) - 1 && j == 0) ? 1 : 0; // if already covered
    }

    if (dp[i][j][mask] != -1) return dp[i][j][mask];

    int ans = 0;
    if (i != 0 && (mask & 1) == 0) {
        // Placing vertically
        int new_mask = (mask >> 1) | (1 << (m - 1));
        if (check(i, j + 1)) {
            ans += rec(i, j + 1, new_mask);
        } 
        else {
            ans += rec(i + 1, 0, new_mask);
        }
    } else {
        // Leaving the current cell empty
        int new_mask = mask >> 1;
        if (check(i, j + 1)) {
            ans += rec(i, j + 1, new_mask);
        } 
        else {
            ans += rec(i + 1, 0, new_mask);
        }

        // Placing horizontally
        if ((mask & (1 << (m - 1))) == 0 && j != 0) {
            new_mask = (mask >> 1) | (1 << (m - 1)) | (1 << (m - 2));
            if (check(i, j + 1)) {
                ans += rec(i, j + 1, new_mask);
            } else {
                ans += rec(i + 1, 0, new_mask);
            }
        }
    }

    return dp[i][j][mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis, -1, sizeof(vis));
    int tt;
    cin >> tt;
    while (tt--) {
        int n1, m1;
        cin >> n1 >> m1;
        n = max(n1, m1);
        m = min(n1, m1);
        dp.assign(n + 1, vector<vector<int>>(m + 1, vector<int>(1 << m, -1)));
        if (vis[n][m] == -1) vis[n][m] = rec(0, 0, 0);
        cout << vis[n][m] << endl;
        dp.clear();
    }

    return 0;
}
