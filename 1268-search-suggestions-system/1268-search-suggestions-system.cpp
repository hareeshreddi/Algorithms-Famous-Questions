class TrieNode{
public:
    bool flag;
    TrieNode* children[26];
    TrieNode(){
        flag=false;
        for(int i=0;i<26;i++) children[i]=NULL;
    }
};
class Solution {
public:
    Solution(){
        root=new TrieNode();
    }
    ~Solution(){
        delete(root);
    }
    void addWord(string word){
        TrieNode* r=root;
        for(const auto &s:word){
            int k=s-'a';
            if(!r->children[k]){
                r->children[k]=new TrieNode();
            }
            r=r->children[k];
        }
        r->flag=true;
    }
    void dfswithPrefix(TrieNode* root, string &cur,vector<string>&ans){
        if(root->flag) ans.push_back(cur);
        for(int i=0;i<26;i++){
            if(ans.size()==3) return;
            if(root->children[i]){
                cur.push_back('a'+i);
                dfswithPrefix(root->children[i],cur,ans);
                cur.pop_back();
            }
        }
    }
    void search(string &cur,vector<string>&ans){
        TrieNode* r=root;
        for(auto p:cur){
            int k=p-'a';
            if(!r->children[k]) return;
            r=r->children[k];
        }
        dfswithPrefix(r,cur,ans);
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for(const auto &s:products) addWord(s);
        vector<vector<string>>ans;
        ans.reserve(searchWord.size());
        string cur="";
        for(int i=0;i<searchWord.size();i++){
            cur+=searchWord[i];
            vector<string>ans1;
            search(cur,ans1);
            ans.push_back(ans1);
        }
        return ans;
    }
private:
    TrieNode* root;
};