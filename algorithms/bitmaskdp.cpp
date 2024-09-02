#include <bits/stdc++.h>
using namespace std;
#define ll long long

// NOTE: log2(x ^ (x | (x + 1))) gives the first unset bit of the x 

const int N = 10;
const int M = 50;

int dp[N][M];

// N ranks and M students find mask satisfaction of the students
// Time Complexity = M * (2 ^ N) * N   
int rec(int i, int mask, vector<vector<int>> &happy) {
    if (i == M) return 0;
    // Add memoization here
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }

    int ans = rec(i + 1, mask, happy); // Don't match this student
    for (int j = 0; j < N; j++) {
        if (((1 << j) & mask) == 0) { // If rank not already allotted
            ans = max(ans, rec(i + 1, mask | (1 << j), happy) + happy[i][j]); // Match this student
        }
    }
    return dp[i][mask] = ans;
}


// finding path from 1 to N with no nodes repeating and all nodes traversed
int rec2path(int node, int mask, vector<vector<int>> &gp) {
    // O((n + m) * 2 ^ N)
    if (mask == (1 << N) - 1) {
        if (node == N) {
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[node][mask] != -1) {
        return dp[node][mask];
    }
    int ans = 0;
    for (auto &child: gp[node]) {
        if (mask & (1 << (child - 1))) {
            continue;
        }
        ans += rec2path(child, (mask | (1 << (child - 1))), gp);
    }
    return dp[node][mask] = ans;
}

long long int dp2[10][1 << 20];
long long int A[N];
// 2 * N chess players and N chess boards then find the best satisfaction
long long int bestPairing(int board, int mask) {
    if (board == N + 1) return 0;
    if (dp2[board][mask] != -1) return dp2[board][mask];
    
    long long int ans = 0;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = 0; j < 2 * N; j++) {
            if ((mask & ((1 << i) | (1 << j))) == 0) {
                ans = max(ans, bestPairing(board + 1, mask | ((1 << i) | (1 << j))) 
                               + board * abs(A[i] - A[j]) * gcd(A[i], A[j]));
            }
        }
    }
    
    dp2[board][mask] = ans;
    return dp2[board][mask];
}


// find minimum number of edges to remove to get DAG using topo sort
int bestChoice(int pos, int mask, vector<vector<int>> &gp) {
    if (pos == N + 1) return 0; // Base case: If all positions have been processed
    // Add memoization here if needed
    
    int ans = 1e9; // Initialize ans with a large value (infinity)
    for (int i = 0; i < N; i++) {
        if (mask & (1 << i)) continue; // Skip if i-th element is already included in the mask
        
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) {
                temp += gp[i][j]; // Accumulate the value based on NumEdge[i][j] for selected pairs
            }
        }
        
        ans = min(ans, bestChoice(pos + 1, mask | (1 << i), gp) + temp); // Recur for the next position
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {

    }
}

