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
    pair<TreeNode*,TreeNode*> flat(TreeNode* root){
        if(root==NULL) return {NULL,NULL};
        if(root->left==NULL && root->right==NULL) return {root,root};
        pair<TreeNode*,TreeNode*>l=flat(root->left);
        pair<TreeNode*,TreeNode*>r=flat(root->right);
        //do operations
        if(l.first) root->right=l.first;
        root->left=NULL;
        if(l.second) l.second->right=r.first;
        //return top most & bottom most nodes
        if(r.second) return {root,r.second};
        else return {root,l.second};
    }
    void flatten(TreeNode* root) {
        flat(root);
    }
};