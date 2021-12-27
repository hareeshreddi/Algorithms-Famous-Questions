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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y) return false;
        bool h1=false,h2=false;
        TreeNode* p1=NULL,*p2=NULL;
        queue<TreeNode*>s;
        s.push(root);
        while(!s.empty())
        {
            int r=s.size();
            while(r){
                TreeNode* t=s.front();
                s.pop();
                if(t->left!=NULL){
                    s.push(t->left);
                    if(t->left->val==x)
                        h1=true,p1=t;
                    else if(t->left->val==y)
                        h2=true,p2=t;
                }
                if(t->right!=NULL){
                    s.push(t->right);
                    if(t->right->val==x)
                        h1=true,p1=t;
                    else if(t->right->val==y)
                        h2=true,p2=t;
                }
                --r;
            }
            if(h1 && h2) if(p1==p2) return false; else return true;
            else if(h1|| h2) return false;
        }
        return false;
    }
};