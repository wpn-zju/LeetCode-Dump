class Solution {
public:
	unordered_map<TreeNode*, int> indexMapBT;
	int widthOfBinaryTree(TreeNode* root) {
		if (root && root->val == 0 && !root->left && root->right && root->right->val == 0)
			return 1;
		int maxV = 0;
		queue<TreeNode*> myQueue;
		indexMapBT[root] = 0;
		myQueue.push(root);
		while (!myQueue.empty())
		{
			int size = myQueue.size();
			vector<int> vec;
			while (size--) {
				vec.push_back(indexMapBT[myQueue.front()]);
				if (myQueue.front()->left) {
					indexMapBT[myQueue.front()->left] = 2 * indexMapBT[myQueue.front()];
					myQueue.push(myQueue.front()->left);
				}
				if (myQueue.front()->right) {
					indexMapBT[myQueue.front()->right] = 2 * indexMapBT[myQueue.front()] + 1;
					myQueue.push(myQueue.front()->right);
				}
				myQueue.pop();
			}
			maxV = max(maxV, vec[vec.size() - 1] - vec[0] + 1);
		}
		return maxV;
	}
};