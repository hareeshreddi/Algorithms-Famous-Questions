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
    //recursive inorder traversal
    void findMax(TreeNode* root,TreeNode* &prev,int &max1,int &cur){
        if(root->left)
            findMax(root->left,prev,max1,cur);
        int r=root->val;
        if(prev->val==root->val) max1=max(max1,++cur);
        else cur=1;
        prev=root;
        if(root->right)
            findMax(root->right,prev,max1,cur);
    }
    //iterative inorder traversal
    void findAns(TreeNode* root,TreeNode* &prev,int &max1,vector<int>&ans,int &cur){
        stack<TreeNode*>s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root=root->left;
            }
            TreeNode* curNode=s.top();s.pop();
            if(prev->val==curNode->val) ++cur;
            else cur=1;
            if(cur==max1) ans.push_back(curNode->val);
            prev=curNode;
            root=curNode->right;
        }
    }
    vector<int> findMode(TreeNode* root) {
        if(!root) return {};
        int max1=1,cur=0;
        TreeNode* prev=root;
        findMax(root,prev,max1,cur);
        vector<int>ans;
        cur=0;prev=root;
        findAns(root,prev,max1,ans,cur);
        return ans;
    }
};