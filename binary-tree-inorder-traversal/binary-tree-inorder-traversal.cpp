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
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*>s;
        vector<int>ans;
        TreeNode* root1=root;
        while(!s.empty() || root1)
        {
            while(root1){
                s.push(root1);
                root1=root1->left;
            }
            TreeNode* t=s.top();s.pop();
            ans.push_back(t->val);
            root1=t->right;
        }
        return ans;
    }
};