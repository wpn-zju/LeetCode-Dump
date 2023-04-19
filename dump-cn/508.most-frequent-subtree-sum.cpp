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
	unordered_map<TreeNode*, int> nodeSumMap;
	unordered_map<int, int> countMap;
	vector<int> result5;
	vector<int> findFrequentTreeSum(TreeNode* root) {
		if (root == NULL)
			return result5;

		calculateSum(root);
		findFrequentTreeSum2(root);

		int maxCount = 1;
		for (unordered_map<int, int>::iterator iter = countMap.begin(); iter != countMap.end(); iter++) {
			if (iter->second == maxCount) {
				result5.push_back(iter->first);
			}
			else if (iter->second > maxCount) {
				maxCount = iter->second;
				result5.clear();
				result5.push_back(iter->first);
			}
		}

		return result5;
	}

	void findFrequentTreeSum2(TreeNode* root) {
		if (root == NULL)
			return;

		findFrequentTreeSum2(root->left);
		countMap[nodeSumMap[root]]++;
		findFrequentTreeSum2(root->right);
	}

	void calculateSum(TreeNode* root) {
		if (root->left == NULL && root->right == NULL)
			nodeSumMap[root] = root->val;
		else if (root->left != NULL && root->right == NULL) {
			calculateSum(root->left);
			nodeSumMap[root] = nodeSumMap[root->left] + root->val;
		}
		else if (root->right != NULL && root->left == NULL) {
			calculateSum(root->right);
			nodeSumMap[root] = nodeSumMap[root->right] + root->val;
		}
		else {
			calculateSum(root->left);
			calculateSum(root->right);
			nodeSumMap[root] = nodeSumMap[root->left] + nodeSumMap[root->right] + root->val;
		}
	}
};