class Solution {
public:
	int largestBSTSubtree(TreeNode* root) {
        if (!root)
            return 0;
		bool tmp0;
		int tmp1, tmp2;
		return lBSTTraversal(root, tmp0, tmp1, tmp2);
	}

	int lBSTTraversal(TreeNode* root, bool& isThisBST, int& min, int& max) {
		if (!root) {
			isThisBST = true;
			return 1;
		}
		bool isLeft = false;
		bool isRight = false;
		int leftmin, leftmax, rightmin, rightmax;
		int left = lBSTTraversal(root->left, isLeft, leftmin, leftmax);
		int right = lBSTTraversal(root->right, isRight, rightmin, rightmax);
		if (isLeft && isRight) {
			if (root->left && root->right) {
				isThisBST = root->val < rightmin && root->val > leftmax;
				if (isThisBST) {
					min = leftmin;
					max = rightmax;
				}
				return isThisBST ? left + right + 1 : std::max(left, right);
			}
			else if (root->left) {
				isThisBST = root->val > leftmax;
				if (isThisBST) {
					min = leftmin;
					max = root->val;
				}
				return std::max(right, isThisBST ? left + 1 : left);
			}
			else if (root->right) {
				isThisBST = root->val < rightmin;
				if (isThisBST) {
					min = root->val;
					max = rightmax;
				}
				return std::max(left, isThisBST ? right + 1 : right);
			}
			else {
				isThisBST = true;
				min = max = root->val;
				return 1;
			}
		}
		else if (isLeft) {
			isThisBST = false;
			return std::max(left, right);
		}
		else if (isRight) {
			isThisBST = false;
			return std::max(left, right);
		}
		else {
			isThisBST = false;
			return std::max(left, right);
		}
	}
};