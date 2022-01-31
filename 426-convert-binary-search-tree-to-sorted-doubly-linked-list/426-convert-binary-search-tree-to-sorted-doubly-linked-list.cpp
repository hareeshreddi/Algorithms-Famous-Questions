/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if(root==NULL) return root;
        Node *first=NULL,*last=NULL;
        stack<Node*>s;
        while(!s.empty() || root){
            while(root){
                s.push(root);
                root=root->left;
            }
            root=s.top();s.pop();
            if(last){
                last->right=root;
                root->left=last;
            }
            else first=root;
            last=root;
            root=root->right;
        }
        last->right=first;
        first->left=last;
        return first;
    }
};