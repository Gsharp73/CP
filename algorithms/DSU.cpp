#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
pair<int, int> parent[N];
int rankk[N];

void make_set(int v) {
    parent[v] = make_pair(v, 0);
    rankk[v] = 0;
}

pair<int, int> find_set(int v) {
    if (v != parent[v].first) {
        int len = parent[v].second;
        parent[v] = find_set(parent[v].first);
        parent[v].second += len;
    }
    return parent[v];
}

void union_sets(int a, int b) {
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
int main() {

}