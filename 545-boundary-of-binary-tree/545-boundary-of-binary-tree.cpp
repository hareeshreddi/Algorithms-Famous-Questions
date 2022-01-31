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
    void left(TreeNode* root,vector<int>&ans) {
        if(root->left==NULL && root->right==NULL) return;
        ans.push_back(root->val);
        if(root->left) left(root->left,ans);
        else if(root->right) left(root->right,ans);
    }
    void right(TreeNode* root,vector<int>&ans) {
        if(root->left==NULL && root->right==NULL) return;
        if(root->right) right(root->right,ans);
        else if(root->left) right(root->left,ans);
        ans.push_back(root->val);
    }
    void leaves(TreeNode* root,vector<int>&ans){
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->val);
            return;
        }
        if(root->left)
            leaves(root->left,ans);
        if(root->right)
            leaves(root->right,ans);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>ans;
        ans.push_back(root->val);
        if(root->left){
            left(root->left,ans);
            leaves(root->left,ans);
        }
        if(root->right){
            leaves(root->right,ans);
            right(root->right,ans);
        }
        return ans;
    }
};