class Solution {
public:
	bool carPooling(vector<vector<int>>& trips, int capacity) {
		int sum = 0;
		map<int, int> myMap;
		for (vector<int>& vec : trips) {
			myMap[vec[1]] += vec[0];
			myMap[vec[2]] -= vec[0];
		}
		for (pair<const int, int>& a : myMap) {
			sum += a.second;
			if (sum > capacity)
				return false;
		}
		return true;
	}
};