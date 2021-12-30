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
    string pre(TreeNode* root,unordered_map<string,int>&s,vector<TreeNode*>&ans)
    {
        if(!root) {return "$";}
        string t=to_string(root->val)+'$';
        t+=pre(root->left,s,ans);
        t+=pre(root->right,s,ans);
        // cout<<t<<"\n";
        if(++s[t]==2) ans.push_back(root);
        return t;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        unordered_map<string,int>s;
        pre(root,s,ans);
        return ans;
    }
};