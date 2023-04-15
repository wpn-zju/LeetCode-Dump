class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		unordered_map<string, int> countMap;
		for (string& i : words)
			countMap[i]++;
		vector<pair<string, int>> tmp;
		for (auto& a : countMap)
			tmp.push_back({ a.first, a.second });
		sort(tmp.begin(), tmp.end(), [](pair<string, int>& a, pair<string, int>& b) {return a.second == b.second ? a.first < b.first : a.second > b.second; });
		vector<string> result;
		for (pair<string, int>& vec : tmp)
			if (result.size() < k)
				result.push_back(vec.first);
			else
				break;
		return result;
	}
};