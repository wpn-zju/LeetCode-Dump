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
	bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		vector<int> v1, v2;
		stack<TreeNode*> s;
		while (!s.empty() || root1) {
			while (root1) {
				s.push(root1);
				root1 = root1->left;
			}
			root1 = s.top()->right;
			v1.push_back(s.top()->val);
			s.pop();
		}
		while (!s.empty() || root2) {
			while (root2) {
				s.push(root2);
				root2 = root2->right;
			}
			root2 = s.top()->left;
			v2.push_back(s.top()->val);
			s.pop();
		}
		int ptr1 = 0, ptr2 = 0;
		while (ptr1 != v1.size() && ptr2 != v2.size()) {
			if (v1[ptr1] + v2[ptr2] == target)
				return true;
			else if (v1[ptr1] + v2[ptr2] < target)
				++ptr1;
			else
				++ptr2;
		}
		return false;
	}
};