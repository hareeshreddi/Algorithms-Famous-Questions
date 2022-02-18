/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(k==0) return {target->val};
        vector<int>ans;
        unordered_map<TreeNode*,TreeNode*>um;
        TreeNode* parent=NULL;
        buildParents(root,parent,um);
        queue<TreeNode*>q;
        unordered_set<int>vis;
        q.push(target);
        vis.insert(target->val);
        processQueue(q,vis,k,um,ans);
        return ans;
    }
    void processQueue(queue<TreeNode*>&q,unordered_set<int>&vis,int k,unordered_map<TreeNode*,TreeNode*>&um,vector<int>&ans){
        while(!q.empty()){
            if(k==0) break;
            int r=q.size();
            for(int i=0;i<r;i++){
                TreeNode* p=q.front();q.pop();
                if(p->left && vis.find(p->left->val)==vis.end()){
                    vis.insert(p->left->val);
                    q.push(p->left);
                }
                if(p->right && vis.find(p->right->val)==vis.end()){
                    vis.insert(p->right->val);
                    q.push(p->right);
                }
                TreeNode* p1=um[p];
                if(p1!=NULL && vis.find(p1->val)==vis.end()){
                    vis.insert(p1->val);
                    q.push(p1);
                }
            }
            --k;
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    void buildParents(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>&um){
        if(!root) return;
        um[root]=parent;
        buildParents(root->left,root,um);
        buildParents(root->right,root,um);
    }
};