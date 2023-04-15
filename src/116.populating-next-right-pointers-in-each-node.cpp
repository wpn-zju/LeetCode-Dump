/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL)
			return NULL;
		
		if (root->left != NULL) {
			if (root->right != NULL)
				root->left->next = root->right;
			else
				root->left->next = findLeftChild(root);
		}

		if (root->right != NULL)
			root->right->next = findLeftChild(root);

		connect(root->right);
		connect(root->left);
		
		return root;
	}

	Node* findLeftChild(Node* root) {
		Node* result = NULL;
		while (root->next != NULL) {
			root = root->next;
			if (root->left != NULL) {
				result = root->left;
				break;
			}
			else if (root->right != NULL) {
				result = root->right;
				break;
			}
		}
		
		return result;
	}
};