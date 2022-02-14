class TrieNode{
public:
  bool flag;
  TrieNode* children[26];
  TrieNode(){
    for(int i=0;i<26;i++) children[i]=NULL;
    flag=false;
  }
};
class Trie {
public: 
    Trie(){
        root=new TrieNode();
    }
    void insert(string &w){
        TrieNode* root=this->root;
        for(int i=0;i<w.length();i++){
            int k=w[i]-'a';
            if(root->children[w[i]-'a']==NULL)
                root->children[w[i]-'a']=new TrieNode();
            root=root->children[w[i]-'a'];
        }
        root->flag=true;
    }
    TrieNode* getRoot(){
        return root;
    }
private:
    TrieNode* root;
};  
class Solution {
public:
    constexpr static int arr[5]={-1,0,1,0,-1};
    void dfs(vector<vector<char>>&board,int i,int j,vector<string>&ans,TrieNode* root,string &cur){
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return;
        char c=board[i][j];
        if(c==' '||root->children[c-'a']==NULL) return;
        root=root->children[c-'a'];
        cur.push_back(c);
        if(root->flag){
            ans.push_back(cur);
            root->flag=false;//de-duplication
        }
        board[i][j]=' ';
        for(int p=0;p<4;p++)
            dfs(board,i+arr[p],j+arr[p+1],ans,root,cur);
        board[i][j]=c;
        cur.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie=new Trie();
        TrieNode* root=trie->getRoot();
        for(auto w:words){
            trie->insert(w);
        }
        vector<string>ans;
        string cur;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board,i,j,ans,root,cur);
            }
        }
        return ans;   
    }
};