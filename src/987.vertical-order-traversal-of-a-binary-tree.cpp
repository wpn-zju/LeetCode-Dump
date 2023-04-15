class Solution {
public:  
	map<int, map<int, set<int>>> verMap;
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> result;
		traversalVer(root, 0, 0);
		for (pair<int, map<int, set<int>>> kvp : verMap) {
			vector<int> vec;
			for (pair<int, set<int>> setKvp : kvp.second)
				for (int value : setKvp.second)
					vec.push_back(value);
			result.push_back(vec);
		}
		return result;
	}

	void traversalVer(TreeNode* root, int height, int pos) {
		if (!root)
			return;
		verMap[pos][height].insert(root->val);
		traversalVer(root->left, height + 1, pos - 1);
		traversalVer(root->right, height + 1, pos + 1);
	}
};