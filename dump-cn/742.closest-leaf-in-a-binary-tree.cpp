class Solution {
public:
    class Node {
	public:
		int val;
		vector<Node*> neighbors;

		Node() {}

		Node(int _val, vector<Node*> _neighbors) {
			val = _val;
			neighbors = _neighbors;
		}
	};
    
	void toGraph(TreeNode* prev, Node* prevN, TreeNode* root, Node* src, int& target, Node*& targetN) {
		if (!root)
			return;
		src->neighbors[0] = prevN;
		if (root->val == target)
			targetN = src;
		if (root->left)
			toGraph(root, src, root->left, src->neighbors[1] = new Node(root->left->val, vector<Node*>(3, nullptr)), target, targetN);
		if (root->right)
			toGraph(root, src, root->right, src->neighbors[2] = new Node(root->right->val, vector<Node*>(3, nullptr)), target, targetN);
	}

	unordered_map<Node*, bool> nodeMap;
	void dfsGraphFCL(Node* root, Node*& result, int dis, int& mindis) {
		nodeMap[root] = true;
		if (!root->neighbors[1] && !root->neighbors[2] && dis < mindis) {
			mindis = dis;
			result = root;
		}
		if (root->neighbors[0] && !nodeMap[root->neighbors[0]])
			dfsGraphFCL(root->neighbors[0], result, dis + 1, mindis);
		if (root->neighbors[1] && !nodeMap[root->neighbors[1]])
			dfsGraphFCL(root->neighbors[1], result, dis + 1, mindis);
		if (root->neighbors[2] && !nodeMap[root->neighbors[2]])
			dfsGraphFCL(root->neighbors[2], result, dis + 1, mindis);
	}

	int findClosestLeaf(TreeNode* root, int k) {
		Node* src = new Node(root->val, vector<Node*>(3, nullptr));
		Node* tar = nullptr;
		Node* result = nullptr;
		int minDis = INT_MAX;
		toGraph(nullptr, nullptr, root, src, k, tar);
		dfsGraphFCL(tar, result, 0, minDis);
		return result->val;
	}
};