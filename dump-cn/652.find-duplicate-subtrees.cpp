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
	vector<TreeNode*> result_8;
	unordered_map<string, vector<TreeNode*>> mapDup;
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		inorder_3(root);
		for (unordered_map<string, vector<TreeNode*>>::iterator iter = mapDup.begin(); iter != mapDup.end(); iter++)
			if (iter->second.size() > 1)
				result_8.push_back(iter->second[0]);
		return result_8;
	}

	string inorder_3(TreeNode* root) {
		if (root == NULL)
			return "N";
		string left = inorder_3(root->left);
		string right = inorder_3(root->right);
		string result = to_string(root->val) + left + right;
		if (mapDup.count(result) == 0) {
			vector<TreeNode*>* tmp = new vector<TreeNode*>();
			tmp->push_back(root);
			mapDup[result] = *tmp;
		}
		else {
			mapDup[result].push_back(root);
		}
		return result;
	}
};