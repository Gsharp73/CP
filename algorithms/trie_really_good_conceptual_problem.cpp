
// ** for every letter at each node there is another node where you store the information and not in the current node **
// ** NOTE: TRIE can also be used for bit manipulation problems like find the maximum xor possible from arr1[i] ^ arr2[j] 
#include <bits/stdc++.h> 
using namespace std;
struct Node {
    Node* links[26];
    int endwith = 0; // number of words that end here
    int cntpref = 0; // number of words with till this node as prefix 
    bool containsref(char ch) {
        return links[ch - 'a'] != NULL;
    }
    void putref(char ch, Node* ref) {
        links[ch - 'a'] = ref;
    }
    Node* getref(char ch) {
        return links[ch - 'a'];
    }
    void incpref() {
        cntpref++;
    }
    void decpref() {
        cntpref--;
    }
    void setend() {
        endwith++;
    }
    void remend() {
        endwith--;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(string &word){
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsref(word[i])) {
                curr->putref(word[i], new Node());
            }
            curr = curr->getref(word[i]);
            curr->incpref();
        }
        curr->setend();
    }

    int countWordsEqualTo(string &word){
        int count = 0;
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsref(word[i])) {
                return 0;
            }
            curr = curr->getref(word[i]);
        }
        return curr->endwith;
    }

    int countWordsStartingWith(string &word){
        int count = 0;
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            if (!curr->containsref(word[i])) {
                return 0;
            }
            curr = curr->getref(word[i]);
        }
        return curr->cntpref;
    }

    void erase(string &word){
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            curr = curr->getref(word[i]);
            curr->decpref();
        }
        curr->remend();
    }
};


// problem link -> https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM
