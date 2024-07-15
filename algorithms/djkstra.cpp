#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<vector<pair<int, long>>> adj(200006); // edges and their weights
vector<ll> a(200006); // if the vertices also have weights
bool vis[200006];
void solve() {
    int n, m;
    cin >> n >> m;
    memset(vis,false,sizeof(vis));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        ll u, v, b;
        cin >> u >> v >> b;
        u--, v--;
        adj[u].push_back({v, b});
        adj[v].push_back({u, b});
    }

    set<pair<long long, int>> pq;
    vector<ll> dist(n, LONG_LONG_MAX);
    pq.insert(make_pair(0LL, 0));
    dist[0] = a[0];
    while (!pq.empty()) {
        ll u = (*(pq.begin())).second;
        pq.erase(pq.begin());
        if (vis[u]) {
            continue;
        }
        vis[u] = true;
        for (auto &child: adj[u]) {
            int v = child.first;
            ll extra = a[v];
            ll weight = child.second;
            if (dist[v] > dist[u] + weight + extra) {
                dist[v] = dist[u] + weight + extra;
                pq.insert(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i < n; i++)
        cout << dist[i] << " ";
}

int main() {

}