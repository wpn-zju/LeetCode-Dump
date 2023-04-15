class Solution {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		vector<string> result;
		unordered_map<string, int> map1;
		for (int i = 0; i < list1.size(); ++i)
			map1[list1[i]] = i;
		int curSum = INT_MAX;
		for (int i = 0; i < list2.size(); ++i) {
			if (map1.count(list2[i])) {
				if (i + map1[list2[i]] < curSum) {
					result.clear();
					curSum = i + map1[list2[i]];
					result.push_back(list2[i]);
				}
				else if (i + map1[list2[i]] == curSum)
					result.push_back(list2[i]);
			}
		}
		return result;
	}
};