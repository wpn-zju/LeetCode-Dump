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
	map<int, map<int, vector<int>>> verMap;
	vector<vector<int>> verticalOrder(TreeNode* root) {
		vector<vector<int>> result;
		traversalVer(root, 0, 0);
		for (pair<int, map<int, vector<int>>> kvp : verMap) {
			vector<int> vec;
			for (pair<int, vector<int>> setKvp : kvp.second)
				for (int& value : setKvp.second)
					vec.push_back(value);
			result.push_back(vec);
		}
		return result;
	}

	void traversalVer(TreeNode* root, int height, int pos) {
		if (!root)
			return;
		verMap[pos][height].push_back(root->val);
		traversalVer(root->left, height + 1, pos - 1);
		traversalVer(root->right, height + 1, pos + 1);
	}
};