/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string serialized = "";
		levelOrder(root, serialized);
		int ptr = serialized.size() - 1;
		while (ptr >= 0 && (serialized[ptr]<'0' || serialized[ptr]>'9'))
			ptr--;
		serialized.resize(ptr + 1);
		return serialized;
	}

	void levelOrder(TreeNode* root, string& s) {
		if (!root)
			return;
		queue<TreeNode*> myQueue;
		myQueue.push(root);
		while (myQueue.size() != 0)
		{
			s += myQueue.front() ? to_string(myQueue.front()->val) + ',' : "null,";
			if (myQueue.front()) {
				myQueue.push(myQueue.front()->left);
				myQueue.push(myQueue.front()->right);
			}
			myQueue.pop();
		}
	}

	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int m = data.length();
		if (!m)
			return nullptr;
		queue<int> myQueue;
		queue<TreeNode*> buildQueue;
		int ptr = 0;
		while (ptr < m) {
			if (data[ptr] == 'n') {
				myQueue.push(INT_MIN);
				ptr += 5;
				continue;
			}
			int len = 0;
			bool flag = true;
			if (data[ptr] == '-') {
				flag = false;
				ptr++;
			}
			while (ptr < m && data[ptr] != ',') {
				len *= 10;
				len += data[ptr] - '0';
				ptr++;
			}
			if (flag)
				myQueue.push(len);
			else
				myQueue.push(-len);
			ptr++;
		}
		TreeNode* root = new TreeNode(myQueue.front());
		TreeNode* cur = root;
		myQueue.pop();
		buildQueue.push(cur);
		while (!myQueue.empty()) {
			cur = buildQueue.front();
			if (myQueue.front() == INT_MIN)
				cur->left = nullptr;
			else {
				cur->left = new TreeNode(myQueue.front());
				buildQueue.push(cur->left);
			}
			myQueue.pop();
			if (myQueue.empty())
				break;
			if (myQueue.front() == INT_MIN)
				cur->right = nullptr;
			else {
				cur->right = new TreeNode(myQueue.front());
				buildQueue.push(cur->right);
			}
			myQueue.pop();
			buildQueue.pop();
		}
		return root;
	}
};