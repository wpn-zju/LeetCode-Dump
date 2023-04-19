class Solution {
public: 
	bool checkOne(string& a, string& b) {
		int ptr1 = 0, ptr2 = 0;
		while (ptr1 < a.size() && ptr2 < b.size())
			if (a[ptr1] == b[ptr2++])
				++ptr1;
		return ptr1 == a.size();
	}

	bool checkSub(string& a, vector<string>& data) {
		for (string& str : data)
			if (checkOne(a, str))
				return true;
		return false;
	}

	int findLUSlength(vector<string>& strs) {
		unordered_map<string, int> count;
		for (string& str : strs)
			++count[str];
		vector<string> vec1;
		vector<string> vec2;
		for (pair<string, int> p : count)
			if (p.second == 1)
				vec1.push_back(p.first);
			else
				vec2.push_back(p.first);
		sort(vec1.begin(), vec1.end(), [](string& a, string& b) {
			return a.size() < b.size();
		});
		while (!vec1.empty()) {
			if (!checkSub(vec1.back(), vec2))
				return vec1.back().size();
			vec2.push_back(vec1.back());
			vec1.pop_back();
		}
		return -1;
	}
};