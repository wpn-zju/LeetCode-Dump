class Solution {
public:
	vector<int> resultFMV;
	vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
		return root->val == voyage[0] && traversalFMV(root, voyage, 0, voyage.size() - 1) ? resultFMV : vector<int>{ -1 };
	}

	bool traversalFMV(TreeNode* root, vector<int>& voyage, int start, int end) {
		int ptr = start + 1;
		if (root->left && root->right) {
			if (root->left->val == voyage[ptr]) {
				while (voyage[ptr] != root->right->val)
					ptr++;
				return traversalFMV(root->left, voyage, start + 1, ptr - 1) && traversalFMV(root->right, voyage, ptr, end);
			}
			else if (root->right->val == voyage[ptr]) {
				resultFMV.push_back(root->val);
				while (voyage[ptr] != root->left->val)
					ptr++;
				return traversalFMV(root->right, voyage, start + 1, ptr - 1) && traversalFMV(root->left, voyage, ptr, end);
			}
			return false;
		}
		else if (root->left)
			return root->left->val == voyage[ptr] ? traversalFMV(root->left, voyage, start + 1, end) : false;
		else if (root->right)
			return root->right->val == voyage[ptr] ? traversalFMV(root->right, voyage, start + 1, end) : false;
		return true;
	}
};