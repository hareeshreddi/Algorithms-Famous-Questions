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
    void convert(TreeNode* root,int &val)
    {
        if(root->right)
            convert(root->right,val);
        val+=root->val;
        root->val=val;
        if(root->left)
            convert(root->left,val);
    }
    TreeNode* bstToGst(TreeNode* root) {
       int val=0;
       convert(root,val);
       return root;
    }
};