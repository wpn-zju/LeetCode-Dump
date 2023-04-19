	class FindElements {
	public:
		unordered_set<int> search;
		FindElements(TreeNode* root) {
			dfsAssign(root, 0);
		}

		void dfsAssign(TreeNode* cur, int val) {
			if (!cur)
				return;
			cur->val = val;
			search.insert(val);
			dfsAssign(cur->left, (val << 1) + 1);
			dfsAssign(cur->right, (val << 1) + 2);
		}

		bool find(int target) {
			return search.count(target);
		}
	};