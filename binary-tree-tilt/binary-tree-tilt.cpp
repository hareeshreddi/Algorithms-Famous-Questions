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
    int find(TreeNode* root,int &ans)
    {
        if(!root) return 0;
        int l=find(root->left,ans);
        int r=find(root->right,ans);
        ans+=abs(l-r);
        return root->val+l+r;
    }
    int findTilt(TreeNode* root) {
        int ans=0;
        find(root,ans);
        return ans;
    }
};