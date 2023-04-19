class Solution {
public:
	vector<vector<string>> groupStrings(vector<string>& strings) {
		unordered_map<string, vector<string>> map;
		for (string str : strings) {
			string key = str;
            int offset = key[0] - 'a';
			for (char& c : key)
                if(c-'a'<offset)
                    c -= offset - 26;
                else
                    c -= offset;
			map[key].push_back(str);
		}
		vector<vector<string>> res;
		for (pair<string, vector<string>> item : map)
			res.push_back(item.second);
		return res;
	}
};