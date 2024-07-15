#include <bits/stdc++.h>
using namespace std;
struct Node {
    Node* links[2];
    bool containskey (int bit) {
        return (links[bit] != NULL);
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node* emp) {
        links[bit] = emp;
    }
};
class Trie {
    private:
    Node* root;
    public:
    Trie () {
        root = new Node();
    }
    void insert(int num) {
        Node* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!curr->containskey (bit)) {
                curr->put(bit, new Node());
            }
            curr = curr->get(bit);
        }
    }
    int getmax(int num) {
        Node* curr = root;
        int mx = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int need = bit ^ 1;
            if (curr->containskey(need)) {
                mx |= (1 << i);
                curr = curr->get(need);
            }
            else {
                curr = curr->get(bit);
            }
        }
        return mx;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie tr;
    for (int i = 0; i < n; i++) {
        tr.insert(arr1[i]);
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
        ans = max(ans, tr.getmax(arr2[i]));
    }
    return ans;
}
int main() {
    
}