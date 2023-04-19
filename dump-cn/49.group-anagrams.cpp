class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string>> map;
		for (string str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			map[key].push_back(str);
		}
		vector<vector<string>> res;
		for (pair<string, vector<string>> item : map) 
			res.push_back(item.second);
		return res;
	}
};