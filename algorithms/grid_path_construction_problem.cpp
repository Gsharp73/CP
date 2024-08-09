#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxn = 1e5;

vector<pair<int, int>> moves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> gp;
    vector<vector<char>> par(n, vector<char> (m, '*'));
    vector<vector<int>> depthm(n, vector<int> (m, INT_MAX));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        gp.push_back(s);
    }
    int sti = -1, stj = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gp[i][j] == 'A') {
                sti = i;
                stj = j;
            }
            if (gp[i][j] == 'M') {
                depthm[i][j] == 0;
            }
        }
    }

    if (sti == n - 1 || sti == 0 || stj == m - 1 || stj == 0) {
        cout << "YES" << endl << 0 << endl;
        return 0;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (gp[i][j] == 'M') {
                v.push_back({i, j});
            }
        }
    }
    function<bool(int, int)> check = [&](int i, int j) -> bool{
        if (i >= n || i < 0 || j < 0 || j >= m) {
            return true;
        }
        return false;
    };
    function<bool(int, int)> checkmon = [&](int i, int j) -> bool{
        if (gp[i][j] == '#' || gp[i][j] == 'M') {
            return true;
        }
        return false;
    };
    {
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        for (auto &[i, j]: v) {
            q.push({i, j});
            depthm[i][j] = 0;
        }
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = true;
            for (auto &move: moves) {
                int nx = x + move.first;
                int ny = y + move.second;
                if (check(nx, ny)) {
                    continue;
                }

                if (checkmon(nx, ny)) {
                    continue;
                }

                if (vis[nx][ny]) {
                    continue;
                }
                depthm[nx][ny] = min(depthm[nx][ny], depthm[x][y] + 1);
                q.push({nx, ny});
            }
        }
    }
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<vector<int>> depth(n, vector<int> (m, INT_MAX));
    bool reached = false;
    queue<pair<int, int>> q;
    q.push({sti, stj});
    depth[sti][stj] = 0;
    int fti = 0, ftj = 0;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        int x = node.first;
        int y = node.second;
        if (vis[x][y]) {
            continue;
        }
        vis[x][y] = true;
        for (auto &move: moves) {
            int nx = x + move.first;
            int ny = y + move.second;
            if (check(nx, ny)) {
                continue;
            }
            if (checkmon(nx, ny)) {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            
            depth[nx][ny] = min(depth[nx][ny], depth[x][y] + 1);
            if (depth[nx][ny] >= depthm[nx][ny]) {
                continue;
            }
            if (move.first == 1 && move.second == 0) {
                par[nx][ny] = 'D';
            }
            else if (move.first == 0 && move.second == -1) {
                par[nx][ny] = 'L';
            }
            else if (move.first == -1 && move.second == 0) {
                par[nx][ny] = 'U';
            }
            else if (move.first == 0 && move.second == 1) {
                par[nx][ny] = 'R';
            }
            q.push({nx, ny});
            if (nx == n - 1 || nx == 0 || ny == m - 1 || ny == 0) {
                reached = true;
                fti = nx;
                ftj = ny;
                break;
            }
        }
        if (reached) {
            break;
        }
    }

    if (!reached) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        int cnt = 0;
        string ans;
        while (fti != sti || ftj != stj) {
            ans += par[fti][ftj];
            if (par[fti][ftj] == 'U') {
                fti++;
            }
            else if (par[fti][ftj] == 'D') {
                fti--;
            } 
            else if (par[fti][ftj] == 'L') {
                ftj++;
            }
            else if (par[fti][ftj] == 'R') {
                ftj--;
            }
            cnt++;
        }
        cout << cnt << endl;
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
}

