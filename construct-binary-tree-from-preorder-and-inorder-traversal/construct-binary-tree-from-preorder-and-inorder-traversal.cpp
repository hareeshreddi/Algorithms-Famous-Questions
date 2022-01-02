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
    TreeNode* build(const vector<int>& preorder,unordered_map<int,int>&um,int &idx,int s,int e)
    {
        TreeNode* t = new TreeNode(preorder[idx]);
        int p=um[preorder[idx++]];
        if(e==s) return t;
        if(s<=p-1)
            t->left=build(preorder,um,idx,s,p-1);
        if(p+1<=e)
            t->right=build(preorder,um,idx,p+1,e);
        return t;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>um;
        for(int i=0;i<inorder.size();i++)
            um[inorder[i]]=i;
        int idx=0;
        return build(preorder,um,idx,0,preorder.size()-1);
    }
};