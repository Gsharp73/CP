#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/

class Solution {
private:
    int dp[101][1025];    
    int func(vector<vector<int>>& grid, int bitmask, int num, unordered_map<int, vector<int>>& mp) {
        if(num == 0)
            return 0;
        if(dp[num][bitmask] != -1)
            return dp[num][bitmask];

        // If num does not exist in the grid
        int res = func(grid, bitmask, num-1, mp);

        for(auto row: mp[num]) {
            // Skip if row has already been visited
            if(bitmask >> row & 1)
                continue;
            res = max(res, num + func(grid, (bitmask | (1<<row)), num-1, mp));
        }
        return dp[num][bitmask] = res;
    }

public:
    int maxScore(vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();
        unordered_map<int, vector<int>> mp;
        // for each number we have stored the rows in which it is present 
        // and we maintain the bitmask of row from which the element has 
        // been chosen starting from 100

        memset(dp, -1, sizeof(dp));
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                mp[grid[i][j]].push_back(i);
            }
        }
        return func(grid, 0, 100, mp);
    }
};