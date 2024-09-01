#define ll long long
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        ll ans = 0;
        int n = damage.size();
        vector<tuple<double, int, int>> d;

        for (int i = 0; i < n; i++) {
            double ratio = double(damage[i]) / ceil(double(health[i]) / power);
            // if it gives more damage in ratio to the times taken to kill it then it should
            // be killed first
            // use this ratio to detect who to kill first
            d.push_back(make_tuple(ratio, damage[i], ceil(double(health[i]) / power)));
        }

        sort(d.begin(), d.end());
        reverse(d.begin(), d.end());

        int curr = accumulate(damage.begin(), damage.end(), 0);

        for (auto &elem : d) {
            int cd, t;
            double ratio;
            
            tie(ratio, cd, t) = elem;
            
            ans += (ll)curr * t;
            curr -= cd;
        }

        return ans;
    }
};