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
    void create(TreeNode* root,string &ans)
    {
        if(!root) return;
        ans+=to_string(root->val);
        if(root->right)
        {
            ans+="(";
            create(root->left,ans);
            ans+=")(";
            create(root->right,ans);
            ans+=")";
        }
        else if(root->left)
        {
            ans+="(";
            create(root->left,ans);
            ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        create(root,ans);
        return ans;
    }
};