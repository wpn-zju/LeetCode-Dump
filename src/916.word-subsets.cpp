class Solution {
public:
	vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
		vector<string> result;
		vector<int> pattern(26, 0);
		for (int i = 0; i < B.size(); ++i) {
			vector<int> tmp(26, 0);
			for (char& c : B[i])
				++tmp[c - 'a'];
			for (int i = 0; i < 26; ++i)
				pattern[i] = max(pattern[i], tmp[i]);
		}
		for (string& str : A) {
			vector<int> count(26, 0);
			for (char& c : str)
				++count[c - 'a'];
			bool flag = true;
			for (int i = 0; i < 26; ++i)
				if (pattern[i] > count[i]) {
					flag = false;
					break;
				}
			if (flag)
				result.push_back(str);
		}
		return result;
	}
};