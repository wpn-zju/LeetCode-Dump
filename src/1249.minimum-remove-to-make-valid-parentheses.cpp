class Solution {
public:
	string minRemoveToMakeValid(string s) {
		unordered_set<int> deleteSet;
		int r = 0, l = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				++l;
			}
			else if (s[i] == ')') {
				if (l == r)
					deleteSet.insert(i);
				else
					++r;
			}
		}
		r = l = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == '(') {
				if (l == r)
					deleteSet.insert(i);
				else
					++l;
			}
			else if (s[i] == ')') {
				++r;
			}
		}
		string result = "";
		for (int i = 0; i < s.size(); ++i)
			if (!deleteSet.count(i))
				result += s[i];
		return result;
	}
};