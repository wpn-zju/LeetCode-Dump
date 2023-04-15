class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string>& paths) {
		vector<vector<string>> result;
		unordered_map<string, vector<string>> myMap;
		for (string& str : paths) {
			int prev = 0;
			int ptr = 0;
			while (ptr < str.length() && str[ptr] != ' ')
				ptr++;
			string lib = str.substr(prev, ptr);
			prev = ++ptr;
			while (ptr < str.length()) {
				if (str[ptr] == '(') {
					int ptr2 = ptr;
					while (str[ptr2] != ')')
						ptr2++;
					myMap[str.substr(ptr + 1, ptr2 - ptr - 1)].push_back(lib + '/' + str.substr(prev, ptr - prev));
					prev = ptr = ptr2 + 2;
				}
				else
					ptr++;
			}
		}
		for (auto& a : myMap) {
			if (a.second.size() > 1) {
				vector<string> vec;
				for (string& str : a.second)
					vec.push_back(str);
				result.push_back(vec);
			}
		}
		return result;
	}
};