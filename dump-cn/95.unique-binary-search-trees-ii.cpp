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
	vector<TreeNode*> generateTrees(int n) {
		if (n == 0) {
			vector<TreeNode*> result;
			return result;
		}
		else {
			return generateTrees(1, n);
		}
	}

	vector<TreeNode*> generateTrees(int start, int end)
	{
		vector<TreeNode*> result;
		if(start<=end)
		{
			for (int i = start; i <= end; ++i)
			{
				vector<TreeNode*> leftTrees, rightTrees;
				leftTrees = generateTrees(start, i - 1);
				rightTrees = generateTrees(i + 1, end);

				for (int j = 0; j < leftTrees.size(); ++j)
				{
					for (int k = 0; k < rightTrees.size(); ++k)
					{
						TreeNode* temp = new TreeNode(i);
						temp->left = leftTrees[j];
						temp->right = rightTrees[k];
						result.push_back(temp);
					}
				}
			}
		}
        else
        {
            TreeNode* temp = NULL;
            result.push_back(temp);
        }
		return result;
	}
};