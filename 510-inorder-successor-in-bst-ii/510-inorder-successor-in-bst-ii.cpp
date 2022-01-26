/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* root) {
        Node* ans=NULL;
        if(root->right){
            ans=root->right;
            while(ans->left) ans=ans->left;
            return ans;
        }
        while(root->parent){
            if(root==root->parent->left) return root->parent;
            root=root->parent;
        }
        return ans;
    }
};