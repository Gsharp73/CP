template<typename T = int>
class BinaryLifting {
private:
    int n, l, timer;
    vector<vector<T>> adj;
    vector<int> tin, tout;
    vector<vector<T>> up;
    
    void dfs(int v, int p) {
        tin[v] = ++timer;
        up[v][0] = p;
        
        for (int i = 1; i <= l; ++i)
            up[v][i] = up[up[v][i-1]][i-1];
            
        for (auto u : adj[v]) {
            if (u != p)
                dfs(u, v);
        }
        
        tout[v] = ++timer;
    }
    
    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }
    
public:
    BinaryLifting(int size) : n(size) {
        adj.resize(n);
        tin.resize(n);
        tout.resize(n);
        timer = 0;
        l = ceil(log2(n));
        up.assign(n, vector<T>(l + 1));
    }
    
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void preprocess(int root) {
        dfs(root, root);
    }
    
    T get_lca(int u, int v) {
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
            
        for (int i = l; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v))
                u = up[u][i];
        }
        return up[u][0];
    }
    
    T get_kth_ancestor(int v, int k) {
        if (k == 0) return v;
        
        for (int i = 0; i <= l; i++) {
            if (k & (1 << i)) {
                v = up[v][i];
            }
        }
        return v;
    }
    
    int get_distance(int u, int v) {
        int lca = get_lca(u, v);
        return get_depth(u) + get_depth(v) - 2 * get_depth(lca);
    }
    
    int get_depth(int v) {
        int depth = 0;
        for (int i = l; i >= 0; --i) {
            if (up[v][i] != v) {
                depth += (1 << i);
                v = up[v][i];
            }
        }
        return depth;
    }
};