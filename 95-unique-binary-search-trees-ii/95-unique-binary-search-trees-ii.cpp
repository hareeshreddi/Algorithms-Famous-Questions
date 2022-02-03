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
    map<pair<int,int>,vector<TreeNode*>>m;
    vector<TreeNode*> generate(int s,int e){
        if(s>e) return {NULL};
        if(s==e){
            if(m.find({s,s})==m.end()) return m[{s,s}]={new TreeNode(s)};
            else return m[{s,s}];
        }
        if(m.find({s,e})!=m.end()) return m[{s,e}];
        vector<TreeNode*>result;
        for(int i=s;i<e+1;i++){
            vector<TreeNode*>l=generate(s,i-1);
            vector<TreeNode*>r=generate(i+1,e);
            for(TreeNode* out:l)
                for(TreeNode* in:r){
                    TreeNode* p=new TreeNode(i);
                    p->left=out;
                    p->right=in;
                    result.push_back(p);
                }
        }
        return m[{s,e}]=result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
};