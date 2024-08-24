#include <bits/stdc++.h>
using namespace std;
#define ll long long

// only valid id DAC

void dfs(int node, vector<bool> &vis, vector<vector<int>> &gp, stack<int> &st) {
    vis[node] = true;
    for (auto child: gp[node]) {
        if (vis[child]) {
            continue;
        }
        dfs(child, vis, gp, st);
    }
    st.push(node);
}

vector<int> kahntopo(vector<bool> &vis, vector<vector<int>> &gp) {
    int n = gp.size();
    vector<int> degree(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < gp[i].size(); j++) {
            degree[gp[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty()) {
        int node = q.front();
        topo.push_back(q.front());
        q.pop();
        for (auto child: gp[node]) {
            degree[child]--;
            if (degree[child] == 0) {
                q.push(child);
            }
        }
    }
    return topo;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; 
    cin >> n >> m;
    vector<vector<int>> gp(n);
    vector<bool> vis(n, false);
    while (m--) {
        int x, y;
        cin >> x >> y;
        gp[x].push_back(y);
    }
    // stack<int> st;
    // for (int i = 0; i < n; i++) {
    //     if (!vis[i]) {
    //         dfs(i, vis, gp, st);
    //     }
    // }
    // vector<int> ans;
    // while (!st.empty()) {
    //     ans.push_back(st.top());
    //     st.pop();
    // }

    // NOTE THAT KAHN ALGO CAN ALSO BE USED TO CHECK FOR CYCLE IN DIRECTED GRAPHS, THE TOPOSORT WILL NOT CONTAIN N ELEMENTS IF CYCLIC
    // HOWEVER CANT USE DFS METHOD FOR THIS AS ALL THE NODES WILL BE INCLUDED 

    vector<int> ans = kahntopo(vis, gp);
    for (auto &i: ans) cout << i << " ";
    cout << endl;
}

