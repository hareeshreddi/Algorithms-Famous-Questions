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
    pair<int,int> find(TreeNode* root,int &ans)
    {
        if(!root) return {INT_MAX,INT_MIN};
        int val=root->val;
        pair<int,int>p1=find(root->left,ans);
        pair<int,int>p2=find(root->right,ans);
        int min1=min(p1.first,p2.first);
        int max1=max(p1.second,p2.second);
        if(min1!=INT_MAX)
            ans=max(ans,abs(val-min1));
        if(max1!=INT_MIN)
            ans=max(ans,abs(val-max1));
        // cout<<min(min1,val)<<" and "<<max(max1,val)<<"\n";
        return {min(min1,val),max(max1,val)};
    }
    int maxAncestorDiff(TreeNode* root) {
        int ans=INT_MIN;
        find(root,ans);
        return ans;
    }
};