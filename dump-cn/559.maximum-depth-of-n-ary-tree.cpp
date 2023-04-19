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
	int maxDepth(Node* root) {
		if (root == NULL)
			return 0;
		int max = 0;
		for (int i = 0; i < root->children.size(); ++i) {
			int depth = maxDepth(root->children[i]);
			if (depth > max)
				max = depth;
		}
		return max + 1;
	}
};