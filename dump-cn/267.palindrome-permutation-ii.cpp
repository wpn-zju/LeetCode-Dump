class Solution {
public:
	vector<string> generatePalindromes(string s) {
		if (s.length() == 1)
			return vector<string>{s};
		vector<string> result;
		int m = s.length();
		unordered_map<char, int> map;
		for (char c : s)
			map[c]++;
		char oddChar = '!';
		for (pair<char, int> i : map)
			if (i.second % 2 == 1)
				if (oddChar == '!')
					oddChar = i.first;
				else
					return result;

		string tmp = "";
		for (pair<char, int> p : map)
			for (int i = 0; i < p.second / 2; ++i)
				tmp.push_back(p.first);
		dfsUnique(result, tmp, 0, oddChar);
		return result;
	}

	bool isEqual(string& a, int left, int right) {
		for (int i = left; i < right; ++i)
			if (a[i] == a[right])
				return true;
		return false;
	}

	void dfsUnique(vector<string>& result, string& a, int step, char& odd) {
		if (step == a.size() - 1) {
			string tmp = a;
			reverse(tmp.begin(), tmp.end());
			if (odd == '!')
				result.push_back(a + tmp);
			else
				result.push_back(a + odd + tmp);
			return;
		}
		for (int i = step; i < a.size(); i++) {
			if (isEqual(a, step, i))
				continue;
			swap(a[step], a[i]);
			dfsUnique(result, a, step + 1, odd);
			swap(a[i], a[step]);
		}
	}
};