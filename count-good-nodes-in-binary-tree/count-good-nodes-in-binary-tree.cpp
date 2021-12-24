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
    int goodNodes(TreeNode* root)
    {
        if(root==NULL) return 0;
        int g=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,root->val});
        while(!q.empty())
        {
            pair<TreeNode*,int>p=q.front();
            if(p.first->val>=p.second) g++;
            int r=max(p.first->val,p.second);
            if(p.first->left)
                q.push({p.first->left,r});
            if(p.first->right)
                q.push({p.first->right,r});
            q.pop();
        }
        return g;
    }

};

//DFS Solution
//     void findans(TreeNode* root,int p,int &x)
//     {
//         if(root==NULL) return;
//         if(root->val>=p) ++x;
//         p=max(p,root->val);
//         findans(root->left,p,x);
//         findans(root->right,p,x);
        
//     }
//     int goodNodes(TreeNode* root) {
//         int x=0,p=-10001;
//         findans(root,p,x);
//         return x;
//     }