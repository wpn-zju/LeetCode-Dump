class Solution {
public:
	bool canConvert(string str1, string str2) {
		if (str1 == str2)
			return true;
		vector<int> match(26, -1);
		vector<int> indegree(26, 0);
		for (int i = 0; i < str1.size(); ++i) {
			if (match[str1[i] - 'a'] == -1)
				match[str1[i] - 'a'] = str2[i] - 'a';
			else if (match[str1[i] - 'a'] != str2[i] - 'a')
				return false;
			++indegree[str2[i] - 'a'];
		}

		for (int& i : indegree)
			if (!i)
				return true;
		return false;
	}
};