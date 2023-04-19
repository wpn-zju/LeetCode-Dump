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
    Node* inorderSuccessor(Node* node) {
        if(!node)
            return NULL;
        if(node->right)
        {
            Node* p=node->right;
            while(p->left)
                p=p->left;
            return p;
        }
        else
        {
            Node* parent=node->parent;
            while(parent&&parent->left!=node)
            {
                node=parent;
                parent=node->parent;
            }
            return parent;
        }
    }
};