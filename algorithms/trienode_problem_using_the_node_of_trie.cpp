#include <bits/stdc++.h>
using namespace std;

// always in dp don't run loop iterate over point i or j do rec(i + 1, ) or something similar

struct Node {
    Node* links[26];
    bool flag = false;
    bool containsref(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void putref(char ch, Node* ref) {
        links[ch - 'a'] = ref;
    }
    Node* getref(char ch) {
        return links[ch - 'a'];
    }
    void setend() {
        flag = true;
    }
    bool isend() {
        return flag;
    }
};

class Trie {
    
public:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    void insert(string &word) {  // O(word.size())
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsref(word[i])) {
                curr->putref(word[i], new Node());
            }
            curr = curr->getref(word[i]);
        }
        curr->setend();
    }

    bool startswith(string &prefix) { // O(prefix.size())
        Node* curr = root; 
        for (int i = 0; i < prefix.size(); i++) {
            if (!curr->containsref(prefix[i])) {
                return false;
            }
            curr = curr->getref(prefix[i]);
        }
        return true;
    }
    
};

class Solution {
public:
    int rec(int idx, string &target, Trie &tt, vector<int> &dp) {
        if (idx == target.size()) {
            return 0;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        Node* curr = tt.root;
        int ans = 1e4;
        for (int i = idx; i < target.size(); i++) {
            // curr += target[i];
            int ch = target[i] - 'a';
            if (curr->links[ch] != NULL) {
                ans = min(ans, 1 + rec(i + 1, target, tt, dp));
                curr = curr->links[ch];
            }
            else {
                break;
            }
        }
        return dp[idx] = ans;
    }

    int minValidStrings(vector<string>& words, string target) {
        Trie tt;
        for (int i = 0; i < words.size(); i++) {
            tt.insert(words[i]);
        }
        vector<int> dp(target.size(), -1);

        int ans = rec(0, target, tt, dp);

        if (ans >= 1e4) {
            return -1;
        }
        return ans;
    }
};