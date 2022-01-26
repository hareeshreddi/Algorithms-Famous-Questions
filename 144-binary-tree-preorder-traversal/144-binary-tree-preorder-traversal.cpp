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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        stack<TreeNode*>s;
        while(!s.empty()||root){
            while(root){
                s.push(root);
                ans.push_back(root->val);
                root=root->left;
            }
            TreeNode* t=s.top();s.pop();
            root=t->right;
        }

        return ans;
    }
};
//Typical Normal Method
// while(!s.empty()){
//     TreeNode* t=s.top();s.pop();
//     ans.push_back(t->val);
//     if(t->right)
//         s.push(t->right);
//     if(t->left)
//         s.push(t->left);
// }