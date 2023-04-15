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
	vector<int> postorder(Node* root) {
		postorderN(root);
		reverse(result_9.begin(), result_9.end());
	    return result_9;
    }

	void postorderN(Node* root)
	{
		if (root == NULL)
			return;
		stack<Node*> s;
		s.push(root);
		while (!s.empty()) {
			root = s.top();
			result_9.push_back(root->val);
			s.pop();
			for (vector<Node*>::iterator iter = root->children.begin(); iter != root->children.end(); ++iter)
				s.push(*iter);
		}
	}
};