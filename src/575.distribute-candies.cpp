class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> myMap;
		for (int i = 0; i < candies.size(); ++i)
			myMap.insert(candies[i]);
		return min(candies.size() / 2, myMap.size());
	}
};