#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 20;
int dp[N];
vector<vector<int>> happy(N, vector<int> (N, 0));
int findhappiness(int mask) {
    int happiness = 0;
    for (int i = 0; i < 10; i++) {
        int curr = (1 << i) & mask;
        if (curr == 0) {
            continue;
        }
        for (int j = 0; j < 10; j++) {
            if (i == j) {
                continue;
            }
            if ((1 << j) & mask) {
                happiness += happy[i][j];
            }
        }
    }
    return happiness;
}

// better find happiness function
int findhappiness(int N, vector<vector<int>>& Happy) {
    vector<int> G_happiness(1 << N, 0);
    for (int mask = 1; mask < (1 << N); mask++) {
        int temp = -1;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                temp = i;
                break;
            }
        }
        G_happiness[mask] = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                G_happiness[mask] += Happy[i][temp];
            }
        }
        G_happiness[mask] += G_happiness[mask ^ (1 << temp)];
    }
    return G_happiness[(1 << N) - 1];
}


int rec(int mask) {
    if (mask == 0) {
        return 0;
    }
    if (dp[mask] != -1) {
        return dp[mask];
    }
    int ans = 0;
    // create the submask for each mask 
    for (int submask = mask; submask; submask = (submask - 1)&mask) {
        int temp = findhappiness(submask);
        ans = max(ans, temp + rec(mask ^ submask));
    }
    return dp[mask] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {

    }
}

