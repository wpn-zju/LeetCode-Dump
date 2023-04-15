class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		string temp = "";
		dfsGP(result, temp, n, n);
		return result;
	}

    // lN = 剩下的左括号个数 rN = 剩下的右括号个数
	void dfsGP(vector<string>& result, string& cur, int lN, int rN) {
        // 左括号没了 直接补满右括号并加入到答案
		if (!lN) {
			for (int i = 0; i < rN; ++i)
				cur.push_back(')');
			result.push_back(cur);
			for (int i = 0; i < rN; ++i)
				cur.pop_back();
		}
		else {
            // 左括号插入不受限制
			cur.push_back('(');
			dfsGP(result, cur, lN - 1, rN);
			cur.pop_back();
            // 右括号剩下的个数大于左括号才可以直接插入右括号
			if (rN > lN) {
				cur.push_back(')');
				dfsGP(result, cur, lN, rN - 1);
				cur.pop_back();
			}
		}
	}
};