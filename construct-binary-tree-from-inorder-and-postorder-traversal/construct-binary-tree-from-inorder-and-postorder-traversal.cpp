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
    TreeNode* build(const vector<int>&postorder,unordered_map<int,int>&um,int &idx,int s,int e)
    {
        if(s>e) return NULL;
        TreeNode* t=new TreeNode(postorder[idx]);
        int p=um[postorder[idx--]];
        t->right=build(postorder,um,idx,p+1,e);
        t->left=build(postorder,um,idx,s,p-1);
        return t;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>um;
        for(int i=0;i<inorder.size();i++)
            um[inorder[i]]=i;
        int idx=postorder.size()-1;
        return build(postorder,um,idx,0,idx);
    }
};