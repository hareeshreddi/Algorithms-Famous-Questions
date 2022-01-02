class TrieNode {
public:
    bool flag;
    TrieNode* children[26];
    TrieNode() {
        flag=false;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};
class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TrieNode;
    }
    ~WordDictionary() {
        delete(root);
    }
    
    void addWord(string word) {
        TrieNode* cur=root;
        for(int i=0;i<word.length();i++){
            int k=word[i]-'a';
            if(!cur->children[k]) cur->children[k]=new TrieNode;
            cur=cur->children[k];
        }
        cur->flag=true;
    }
    
    bool dfssearch(TrieNode* root,const string &word,int idx){
        int l=word.length();
        if(l==idx) return root->flag;
        if(word[idx]!='.'){
            int k=word[idx]-'a';
            if(!root->children[k]) return false;
            return dfssearch(root->children[k],word,idx+1);
        } else
            for(int i=0;i<26;i++)
                if(root->children[i])
                    if(dfssearch(root->children[i],word,idx+1)) return true;
        return false;
    }
    bool search(string word) {
        return dfssearch(root,word,0);
    }
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */