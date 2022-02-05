/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(TreeNode* root,unordered_set<int>&s,vector<TreeNode*>&ans,bool b){
        if(root==NULL) return NULL;
        if(s.find(root->val)==s.end()) {
            if(b) ans.push_back(root);
            if(root->left) root->left=recur(root->left,s,ans,false);
            if(root->right) root->right=recur(root->right,s,ans,false);
            return root;
        }
        else{
            if(root->left) recur(root->left,s,ans,true);
            if(root->right) recur(root->right,s,ans,true);
            delete(root);
            return NULL;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        unordered_set<int>s(to_delete.begin(),to_delete.end());
        recur(root,s,ans,true);
        return ans;
    }
};