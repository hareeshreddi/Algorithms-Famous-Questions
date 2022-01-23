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
    pair<int,int> robo(TreeNode* root){//pair(a,b)=>a for including, b for exclduing root
        if(root==NULL) return {0,0};
        pair<int,int>ans;
        pair<int,int>p1=robo(root->left);
        pair<int,int>p2=robo(root->right);
        ans.first=root->val+p1.second+p2.second;
        ans.second=max(p1.first,p1.second)+max(p2.first,p2.second);
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int,int>ans=robo(root);
        return max(ans.first,ans.second);
    }
};