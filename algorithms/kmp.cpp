#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> kmp(string s) { // O(n)
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1]; // how many characters matched till here max
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        } // keep going back until something matches but i remains where it was
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int string_matching(string s, string pat) {
    vector<int> pi = kmp(s);
    cout << endl;
    int i = 0, j = 0;
    int ans_pos = -1;
    while (i < s.size()) {
        if (s[i] == pat[j]) {
            i++, j++;
        }
        else {
            if (j > 0) {
                j = pi[j - 1];
            }
            else {
                i++; 
            }
        }
        if (j == pat.size()) {
            ans_pos = i - pat.size();
            break;
        } 
    }
    return ans_pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        string s, pat;
        cin >> s >> pat;
        int ans = string_matching(s, pat);
        cout << ans << endl;
    }
}

