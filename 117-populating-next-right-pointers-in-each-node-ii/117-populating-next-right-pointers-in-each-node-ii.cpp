/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* findNext(Node* root){
        while(root){
            if(root->left) return root->left;
            else if(root->right) return root->right;
            root=root->next;
        }
        return root;
    }
    Node* connect(Node* root) {
        if(!root) return root;
        if(root->left){
            if(root->right) root->left->next=root->right;
            else if(root->next) root->left->next=findNext(root->next);
        }
        if(root->right){
            if(root->next) root->right->next=findNext(root->next);
        }
        connect(root->right);
        connect(root->left);
        return root;
    }
};