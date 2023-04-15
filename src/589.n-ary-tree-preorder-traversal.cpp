/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> result_9;
	vector<int> preorder(Node* root) {
		preorderN(root);
		return result_9;
	}

	void preorderN(Node* root)
	{
		if (root == NULL)
			return;
		stack<Node*> s;
		s.push(root);
		while (!s.empty()) {
			root = s.top();
			result_9.push_back(root->val);
			s.pop();
			for (vector<Node*>::reverse_iterator iter = root->children.rbegin(); iter != root->children.rend(); ++iter)
				s.push(*iter);
		}
	}
};