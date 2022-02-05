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
    TreeNode* flat(TreeNode* root){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL) return root;
        TreeNode* l=flat(root->left);
        TreeNode* r=flat(root->right);
        //do operations
        if(l){
            TreeNode* temp=root->right;
            root->right=root->left;
            root->left=NULL;
            l->right=temp;
        }
        //return bottom most node
        return r?r:l;
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};