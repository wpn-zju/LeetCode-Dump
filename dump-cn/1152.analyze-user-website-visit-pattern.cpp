class Solution {
public:
	vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
		vector<string> cp = website;
		sort(cp.begin(), cp.end());
		unordered_map<string, char> nameMap;
		unordered_map<char, string> id2Name;
		char count = 0;
		for (string& str : cp)
			if (!nameMap.count(str)) {
				nameMap[str] = count;
				id2Name[count] = str;
				++count;
			}

		unordered_map<string, vector<pair<int, char>>> data;
		for (int i = 0; i < username.size(); ++i)
			data[username[i]].push_back({ timestamp[i],nameMap[website[i]] });
		for (pair<string, vector<pair<int, char>>> p : data) {
			sort(p.second.begin(), p.second.end(), [](pair<int, char>& a, pair<int, char>& b) {return a.first < b.first; });
			data[p.first] = p.second;
		}

		unordered_map<string, int> countMap;
		for (pair<string, vector<pair<int, char>>> p : data) {
			unordered_set<string> tmpSet;
			for (int i = 0; i < p.second.size(); ++i)
				for (int j = i + 1; j < p.second.size(); ++j)
					for (int k = j + 1; k < p.second.size(); ++k)
						tmpSet.insert({ p.second[i].second,p.second[j].second,p.second[k].second });
			for (string str : tmpSet)
				++countMap[str];
		}

		vector<pair<string, int>> vec;
		for (pair<string, int> p : countMap)
			vec.push_back(p);
		sort(vec.begin(), vec.end(), [](pair<string, int>& a, pair<string, int>& b) {
			return a.second == b.second ? a.first < b.first : a.second > b.second;
		});

		vector<string> result;
		string res = vec.front().first;
		for (char& c : res)
			result.push_back(id2Name[c]);
		return result;
	}
};