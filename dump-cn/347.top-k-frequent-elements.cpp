class Solution {
public:
 	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> countMap;
		for (int& i : nums)
			countMap[i]++;
		vector<vector<int>> tmp;
		for (auto& a : countMap)
			tmp.push_back({ a.first, a.second });
		sort(tmp.begin(), tmp.end(), [](vector<int>& a, vector<int>& b) {return a[1] > b[1]; });
		vector<int> result;
		for (vector<int>& vec : tmp)
			if (result.size() < k)
				result.push_back(vec[0]);
			else
				break;
		return result;
	}
};