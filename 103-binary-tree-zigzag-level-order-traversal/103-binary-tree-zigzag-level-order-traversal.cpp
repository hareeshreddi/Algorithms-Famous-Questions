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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;
        deque<TreeNode*>q;bool flag=true;
        q.push_back(root);
        while(!q.empty()){
            int r=q.size();
            vector<int>temp;
            TreeNode* t;
            for(int i=0;i<r;i++){
                if(flag){
                    t=q.front();
                    temp.push_back(t->val);
                    q.pop_front();
                    if(t->left) q.push_back(t->left);
                    if(t->right) q.push_back(t->right);
                } else{
                    t=q.back();
                    temp.push_back(t->val);
                    q.pop_back();
                    if(t->right) q.push_front(t->right);
                    if(t->left) q.push_front(t->left);
                }
            }              
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};