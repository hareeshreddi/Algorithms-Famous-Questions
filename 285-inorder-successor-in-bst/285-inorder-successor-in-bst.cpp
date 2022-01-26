/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
            p=p->right;
            while(p->left)
                p=p->left;
            return p;
        }
        TreeNode* ans=NULL;
        while(root){
            if(root->val>p->val){
                ans=root;
                root=root->left;
            } else root=root->right;
        }
        return ans;
    }
};