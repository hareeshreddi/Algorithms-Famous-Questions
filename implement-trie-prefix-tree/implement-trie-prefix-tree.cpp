class TrieNode {
    public:
        bool flag;
        TrieNode* children[26];
        TrieNode() {
            flag=false;
            for(int i=0;i<26;i++) children[i]=NULL;
        }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur=root;
        for(int i=0;i<word.length();i++){
            int k=word[i]-'a';
            if(!cur->children[k]) cur->children[k]=new TrieNode();
            cur=cur->children[k];
        }
        cur->flag=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur=root;
        for(int i=0;i<word.length();i++){
            cur=cur->children[word[i]-'a'];
            if(!cur) return false;
        }
        return cur->flag;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur=root;
        for(int i=0;i<prefix.length();i++){
            cur=cur->children[prefix[i]-'a'];
            if(!cur) return false;
        }
        return true;
    }
 private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */