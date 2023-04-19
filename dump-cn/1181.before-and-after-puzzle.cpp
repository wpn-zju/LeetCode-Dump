class Solution {
public:
	string getFirstStr(string& in) {
		int ptr = 0;
		while (ptr < in.size() && in[ptr] != ' ')
			++ptr;
		return in.substr(0, ptr);
	}

	string getLastStr(string& in) {
		int ptr = in.size() - 1;
		while (ptr >= 0 && in[ptr] != ' ')
			--ptr;
		return in.substr(ptr + 1);
	}

	vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
		set<string> result;
		unordered_map<string, int> countMap;
		unordered_map<string, vector<string>> headStrMap;
		for (string& str : phrases) {
			++countMap[str];
			headStrMap[getFirstStr(str)].push_back(str);
		}
		for (string& str : phrases) {
			string last = getLastStr(str);
			for (string& str2 : headStrMap[last])
				if (str2 != str || countMap[str] >= 2)
					result.insert(str + str2.substr(last.length()));
		}
		return vector<string>(result.begin(), result.end());
	}
};