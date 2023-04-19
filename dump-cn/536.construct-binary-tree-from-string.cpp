class Solution {
public:
	TreeNode* str2tree(string s) {
		return str2Tree(s, 0, s.size() - 1);
	}

	TreeNode* str2Tree(string& s, int start, int end) {
		if (start > end)
			return nullptr;
		int ptr = start;
		int val = 0;
		bool neg = s[ptr] == '-';
		if (neg)
			ptr++;
		while (ptr <= end && s[ptr] >= '0' && s[ptr] <= '9') {
			val *= 10;
			val += s[ptr] - '0';
			ptr++;
		}
		if (neg)
			val *= -1;
		TreeNode* cur = new TreeNode(val);
		if (ptr == end)
			return cur;
		int space1 = ptr;
		int space2 = ptr + 1;
		int lCount = 0;
		int rCount = 0;
		while (space2 <= end) {
			if (s[space2] == '(')
				lCount++;
			else if (s[space2] == ')')
				rCount++;
			if (s[space2] == '(' && lCount == rCount)
				break;
			space2++;
		}
		cur->left = str2Tree(s, space1 + 1, space2 - 2);
		cur->right = str2Tree(s, space2 + 1, end - 1);
		return cur;
	}
};