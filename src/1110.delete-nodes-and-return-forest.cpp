static auto _ = []() { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
	vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		unordered_set<int> key;
		for (int& i : to_delete)
			key.insert(i);
		vector<TreeNode*> result;
		if (root)
			dfsDN(result, root, key, true);
		return result;
	}

	void dfsDN(vector<TreeNode*>& result, TreeNode* root, unordered_set<int>& key, bool tag) {
		if (tag) {
			if (!key.count(root->val)) {
				result.push_back(root);
				tag = false;
			}
		}
		if (root->left) {
			if (key.count(root->left->val)) {
				dfsDN(result, root->left, key, true);
				root->left = nullptr;
			}
			else
				dfsDN(result, root->left, key, tag);
		}
		if (root->right) {
			if (key.count(root->right->val)) {
				dfsDN(result, root->right, key, true);
				root->right = nullptr;
			}
			else
				dfsDN(result, root->right, key, tag);
		}
	}
};