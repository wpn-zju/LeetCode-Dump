/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> closestKValues(TreeNode* root, double target, int k) {
		vector<int> values;
		dfsTreeNodes(root, values);
		vector<int> result;
		auto it = lower_bound(values.begin(), values.end(), target);
		int ptrR = it - values.begin();
		int ptrL = ptrR - 1;
		while (result.size() < k) {
			if (ptrL == -1 || ptrR != values.size() && abs(target - values[ptrR]) < abs(target - values[ptrL]))
				result.push_back(values[ptrR++]);
			else
				result.push_back(values[ptrL--]);
		}
		return result;
	}

	void dfsTreeNodes(TreeNode* cur, vector<int>& result) {
		if (!cur)
			return;
		dfsTreeNodes(cur->left, result);
		result.push_back(cur->val);
		dfsTreeNodes(cur->right, result);
	}
};